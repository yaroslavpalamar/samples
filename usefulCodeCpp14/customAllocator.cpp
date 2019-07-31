#include <algorithm>
#include <iostream>
#include <vector>
#include <limits>

template<class T>
class TrackingAllocator
{
public:

	using value_type = T; //required

	using pointer = T*; //optional
	using const_pointer = const T*; //optional

	//using void_pointer = void *; //optional
	//using const_void_pointer = const void *; //optional

	using size_type = size_t; //optional
	//using different_type = std::ptrdiff_t; //optional

	/*template<class U>
	struct rebind
	{
		using other = TrackingAllocator<U>;
	};*/

	TrackingAllocator() = default;

	template<class U> //required
	TrackingAllocator(const TrackingAllocator<U> &other) {}

	~TrackingAllocator() = default;

	//current method called once for allocation 5 objects.
	pointer allocate(size_type numObjects) //required
	{
		mAllocations += numObjects;
		return static_cast<pointer>(operator new(sizeof(T) * numObjects));
	}

	/*pointer allocate(size_type numObjects, const_void_pointer hint)
	{
		return allocate(numObjects);
	}*/

	void deallocate(pointer p, size_type numObjects) //required
	{
		operator delete(p);
	}

	/*size_type max_size() const
	{
		return std::numeric_limits<size_type>::max();
	}

	//construction function which allocate memory
	template<class U, class... Args>
	void construct(U *p, Args && ...args)
	{
		new(p) U(std::forward<Args>(args)...);
	}

	template<class U>
	void destroy(U *p)
	{
		p->~U();
	}*/

	size_type get_allocations() const
	{
		return mAllocations;
	}
private:
	static size_type mAllocations;
};


template<class T>
typename TrackingAllocator<T>::size_type TrackingAllocator<T>::mAllocations = 0;

int
main()
{
	//using TAint = TrackingAllocator<int>;
	//using TAdouble = TAint::rebind<double>::other;
	std::vector<int, TrackingAllocator<int>> v(5);
	std::cout<<v.get_allocator().get_allocations() << "\n";
	return 0;
}

