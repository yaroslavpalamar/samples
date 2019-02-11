#include <iostream>
#include <mutex>
#include <condition_variable>
#include <thread>
#include <chrono>

using namespace std;

/*
	1. Semaphore class contain private fields std::mutex mtx; std::condition_variable cv; int count;
	2. And two public methods:
		constructor Semaphore to init count variable with number of threads that can access common code
		wait(){unique_lock<mutext>lock(mtx) while(count==0){cv.wait(lock);}count--;}
		notify(){unique_lock...lock(mtx); count++; cv.notify_one;}
*/
class Semaphore {
public:
	Semaphore (int count_ = 0) : count(count_) 
	{}

	void notify()
	{
		std::unique_lock<std::mutex> lock(mtx);
		count++;
		cv.notify_one();
	}

	void wait()
	{
		std::unique_lock<std::mutex> lock(mtx);

		while(count == 0){
			cv.wait(lock);
		}	
		count--;
	}

private:
	std::mutex mtx;
	std::condition_variable cv;
	int count;
};


void print1(Semaphore& mtx1)
{
        mtx1.wait();
        for (int i = 0; i<5; ++i) {
                for (int i=0; i<10;++i) {
                        cout << '*';
                        this_thread::sleep_for(chrono::milliseconds(20));
                }
                cout << endl;
        }
        cout << endl;
        mtx1.notify();
}


void print2(Semaphore& mtx1)
{
        mtx1.wait();
        for (int i = 0; i<5; ++i) {
                for (int i=0; i<10;++i) {
                        cout << '%';
                        this_thread::sleep_for(chrono::milliseconds(20));
                }
                cout << endl;
        }
        cout << endl;
        mtx1.notify();
}

void sleepAndPrint(Semaphore& mtx1, int time)
{
        mtx1.wait();
        this_thread::sleep_for(chrono::milliseconds(time));
	cout << "finish sleeping"<< endl; 
        mtx1.notify();
}

int main()
{
	Semaphore sem(2);
        thread t1(print1, ref(sem));
        thread t2(sleepAndPrint, ref(sem), 1500);

	// thread 3 will start runing print2 just when print1 or emptyCall will finish the job.
	thread t3(print2, ref(sem));
        t1.join();
        t2.join();
	t3.join();

	return 0;
}
