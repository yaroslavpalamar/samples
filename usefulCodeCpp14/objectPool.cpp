#include <algorithm>
#include <iostream>
#include <vector>
#include <chrono>

template <class T>
class ObjectPool final {
public:
	const static std::size_t Size = 100000;
	using value_type = T;
	using pointer = value_type *;
	ObjectPool() {
		for(auto i = 1; i<Size; ++i)
			mPool[i-1].mNext = &mPool[i];
		mNextFree = &mPool[0];
	}
	~ObjectPool() = default;

	ObjectPool& operator = (ObjectPool&& other) = default;

	ObjectPool(const ObjectPool&& other) noexcept
		: mPool{std::move(other.mPool) }
			, mNextFree{ other.mNextFree }
	{
		other.mNextFree = nullptr;
	}

	[[nodiscard]] pointer allocate()
	{
		if (mNextFree == nullptr)
			throw std::bad_alloc{};
		const auto item = mNextFree;
		mNextFree = item->mNext;

		return reinterpret_cast<pointer>(&item->mStorage);
	}
	void deallocate(pointer p) noexcept
	{
		const auto item = reinterpret_cast<Item*>(p);

		item->mNext = mNextFree;
		mNextFree = item;
	}

	template<class ...Args>
	[[nodiscard]] pointer construct(Args&& ...args)
	{
		return new (allocate()) value_type(std::forward<Args>(args)...);
	}

	void destroy (pointer p) noexcept
	{
		if (p == nullptr)
			return;
		p->~value_type();
		deallocate(p);
	}

	ObjectPool(const ObjectPool& other) = delete;
	ObjectPool& operator = (const ObjectPool& other) = delete;
private:
	union Item
	{
		std::aligned_storage_t<sizeof(value_type), alignof(value_type)> mStorage;
		Item* mNext;
	};

	std::unique_ptr<Item[]> mPool = std::make_unique<Item[]>(Size);
	Item* mNextFree = nullptr;
};




template<class Resolution = std::chrono::milliseconds>
class ExecutionTimer
{
public:
	using Clock = std::conditional_t<std::chrono::high_resolution_clock::is_steady,
									std::chrono::high_resolution_clock,
									std::chrono::steady_clock>;
	ExecutionTimer() = default;
	~ExecutionTimer() {
		// use std::chrono::duration_cast<std::chrono::milliseconds> casting to get milliseconds
		// system_clock is not good for time measurement
		std::cout
			<< "Elapsed: "
			<< std::chrono::duration_cast<Resolution>(Clock::now() - mStart).count() << std::endl;
	}
private:
	Clock::time_point mStart = Clock::now();
};

int
main()
{
	{
		ObjectPool<int> pool;
		ExecutionTimer<> timer;
		{
			//for (auto i = 0; i < 100000; ++i)
				//delete new int;
			for (auto i = 0; i < 100000; ++i)
				pool.destroy(pool.construct());
		}
	}
	{
		ObjectPool<int> pool;
		ExecutionTimer<> timer;
		{
			for (auto i = 0; i < 100000; ++i)
				delete new int;
		}
	}
	return 0;
}

