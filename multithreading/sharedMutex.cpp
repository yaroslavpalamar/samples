#include <iostream>
#include <mutex>
#include <shared_mutex>
#include <thread>

class ReadWriteThread {
public:
	ReadWriteThread() {
		val=0; 
	}
	int readVal() const {
		std::shared_lock sp(mtx);
		return val;
	}
	void increment() {
		std::unique_lock up(mtx);
		val++;
	}
	void reset() {
		std::unique_lock up(mtx);
		val = 0;
	}
private:
	int val;
	mutable std::shared_mutex mtx;
};

int main ()
{
	ReadWriteThread count;
	auto incrementTest = [&count]() {
		for(int i=0; i<3; i++) {
			count.increment();
			std::cout << std::this_thread::get_id()<< ' '<< count.readVal() << std::endl;
			// Note: Writing to std::cout actually needs to be synchronized as well
			// by another std::mutex. This has been omitted to keep the example small.
		}
	};

	std::thread t1(incrementTest);
	std::thread t2(incrementTest);

	t1.join();
	t2.join();
	return 0;
}

