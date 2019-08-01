#include <functional>
#include <condition_variable>
#include <thread>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <future>

class ThreadPool
{
public:
	using Task = std::function<void()>;

	explicit ThreadPool(std::size_t numThreads)
	{
		start(numThreads);
	}

	~ThreadPool()
	{
		stop();
	}

	//to get a value from a finished task use feature
	template<class T>
	auto enqueue(T task)->std::future<decltype(task())>
	{
		auto wrapper = std::make_shared<std::packaged_task<decltype(task()) ()>>(std::move(task));
		{
			std::unique_lock<std::mutex> lock{mEventMutex};
			mTasks.emplace([=]{
				(*wrapper)();
			});
		}
		mEventVar.notify_one();
		return wrapper->get_future();
	}
private:
	std::vector<std::thread> mThreads;
	std::condition_variable mEventVar;

	//list of tasks to be executed in thread pool
	std::queue<Task> mTasks;

	std::mutex mEventMutex;
	bool mStopping = false;
	void start(std::size_t numThreads)
	{
		for(auto i = 0u; i < numThreads; ++i) {
			mThreads.emplace_back([=] {
				while (true)
				{
					Task task;
					{ //we want to have critical section as small as possible
						//that's why we have current braces
						std::unique_lock<std::mutex> lock{mEventMutex};
						mEventVar.wait(lock, [=]{return mStopping || !mTasks.empty();});
						if(mStopping && mTasks.empty())
							break;

						task = std::move(mTasks.front());
						mTasks.pop();
					}
					task();
				}
			});
		}
	}
	void stop() noexcept
	{
		{
			std::unique_lock<std::mutex> lock{mEventMutex};
			mStopping = true;
		}
		mEventVar.notify_all();

		for(auto &thread : mThreads)
			thread.join();
	}
};

int
main()
{

	{
		ThreadPool pool(36);
		auto f1 = pool.enqueue([]{
				return 1;
		});
		auto f2 = pool.enqueue([]{
				return 2;
		});

		std::cout << (f1.get() + f2.get()) << std::endl;
	}
	return 0;
}

