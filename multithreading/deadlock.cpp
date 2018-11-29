#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>

using namespace std;

mutex mtx1;
mutex mtx2;

void print1()
{
	mtx2.lock();
	this_thread::sleep_for(chrono::milliseconds(1)); /// if you comment out this line deadlock will be unstable
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
	mtx2.unlock();
}


void print2()
{
	mtx1.lock();
	this_thread::sleep_for(chrono::milliseconds(1)); /// if you comment out this line deadlock will be unstable
	mtx2.lock();
        for (int i = 0; i<5; ++i) {
                for (int i=0; i<10;++i) {
                        cout << '%';
                        this_thread::sleep_for(chrono::milliseconds(20));                                                                  
                }
                cout << endl;
        }
        cout << endl;
	mtx2.unlock();
	mtx1.unlock();
}


int main()
{
	thread t1(print1);
	thread t2(print2);
	
	t1.join();
	t2.join();

	return 0;
}

