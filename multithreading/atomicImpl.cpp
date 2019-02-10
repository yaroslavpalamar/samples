#include <iostream>       // std::cout
#include <atomic>         // std::atomic, std::atomic_flag, ATOMIC_FLAG_INIT
#include <thread>         // std::thread, std::this_thread::yield
#include <vector>         // std::vector

using namespace std;

/*
	1. exist different atomic types: char/short/bool... atomic<bool> ready(false);
	2. atomic_flag 100% works withou blocking, but std::atomic may be implemented with blocking
	3. std::this_thread::yield() wait for ready signal
	4. winner.test_and_set() check if flag is set
	5. create 10 threads and push them to vector<std::thread>
	6. every thread will start function countToMillion (int id) {while(!ready){this_thread::yeld();}
		for (volatile int i=0; i<1000000;++i)
		if (!winner.test_and_set()){print winner}}
*/
atomic<bool> ready(false);
atomic_flag winner = ATOMIC_FLAG_INIT;

void countToMillion (int id) {
	while (!ready) { 
		std::this_thread::yield();  
		// wait for the ready signal
	}     	
	for (volatile int i=0; i<1000000; ++i) {
		// count to 1 million
	}         
	if (!winner.test_and_set()) { 
		cout << "thread #" << id << " won!\n"; 
	}
};

int main ()
{
	vector<std::thread> threads;
	cout << "spawning 10 threads that count to 1 million...\n";	
	for (int i=1; i<=10; ++i) 
		threads.push_back(std::thread(countToMillion,i));
  	ready = true;
  
	for (auto& th : threads) 
		th.join();

	return 0;
}
