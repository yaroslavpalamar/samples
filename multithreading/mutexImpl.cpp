#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>

using namespace std;

/*
 	1. spinLock creation with atomic_flag which guarantee synchronization without locks
	2. class SpinLock {private: std::atomic_flag locked 
		also contatin lock() unlock() functions:
		lock( while(locked.test_and_set(std::memory_order_acquire){std::this_thread::yeld();}))
		unlock(){locked.clear(std::memory_order_release)}}
*/

class SpinLock {
	std::atomic_flag locked;
public:
	void lock() {
		while (locked.test_and_set(std::memory_order_acquire)) { 
			std::this_thread::yield(); //<- this is not in the source but might improve performance. 
		}
	}
	void unlock() {
		locked.clear(std::memory_order_release);
	}
};

void printSpinLock(SpinLock& mtx1)
{
	mtx1.lock();	
	for (int i = 0; i<5; ++i) {
		for (int i=0; i<10;++i) {
			cout << '*';
			this_thread::sleep_for(chrono::milliseconds(20));
		}
		cout << endl;
	}
	cout << endl;
	mtx1.unlock();
}


void printSpinLock2(SpinLock& mtx1)
{
	mtx1.lock();
        for (int i = 0; i<5; ++i) {
                for (int i=0; i<10;++i) {
                        cout << '%';
                        this_thread::sleep_for(chrono::milliseconds(20));                                                                  
                }
                cout << endl;
        }
        cout << endl;
	mtx1.unlock();
}

void print1(mutex& mtx1)
{
	mtx1.lock();	
	for (int i = 0; i<5; ++i) {
		for (int i=0; i<10;++i) {
			cout << '*';
			this_thread::sleep_for(chrono::milliseconds(20));
		}
		cout << endl;
	}
	cout << endl;
	mtx1.unlock();
}


void print2(mutex& mtx1)
{
	mtx1.lock();
        for (int i = 0; i<5; ++i) {
                for (int i=0; i<10;++i) {
                        cout << '%';
                        this_thread::sleep_for(chrono::milliseconds(20));                                                                  
                }
                cout << endl;
        }
        cout << endl;
	mtx1.unlock();
}


int main()
{
	/*mutex mtx;
	thread t1(print1, ref(mtx));
	thread t2(print2, ref(mtx));
	
	t1.join();
	t2.join();*/

	SpinLock mtx;
	thread t1(printSpinLock, ref(mtx));
	thread t2(printSpinLock2, ref(mtx));
	
	t1.join();
	t2.join();

	return 0;
}

