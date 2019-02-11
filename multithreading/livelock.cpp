#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>

using namespace std;

/*

	Thread1_____________\
			Worker1___________________________________________________________
			       /|\						  	/|\
				|							No
(Common Resources)--------(handover the resource to other thread)<-YES--{is other Worker active?}
				|							No
			       \|/						  	\|/
			Worker2__________________________________________________________
	Thread2____________/


	1. A real-world example of livelock occurs when two people meet in a narrow corridor
	2. We have Worker class with worker() method which contain common resource, worker() give acces to many threads:
		void work(CommonRes* comRes,Worker* othWorker,mutex*mtx)
		Worker class contain methods:
			getName(); getId(); isActive(); and constructor to init values: 
				Worker (string name, bool active, int id)
	3. Created obj of CommonRes class will be passed to different workers
		CommonRes contain field Worker* owner; (should be set in constructor)
		Also CommonRes have setter and getter for owner.
	4. create two Workers object and pass Worker object and CommorRes obj to function: 
		void work(CommonRes* comRes, Worker* othWorker, mutex*mtx)
		inside this function will be logic from diargame above 
			before access to common resource check for other thread if other thread 
			try to acces give this access to other thread in result
			you will get livelock every thread will always give access to other thread
*/

class CommonRes;
class Worker;
class Worker {
	string name;
	int id;
	bool active;

public:
	Worker (string name, bool active, int id) {
		this->name = name;
		this->active = active;
		this->id = id;
	}
	string getName() {
		return name;
	}
	int getId() {
		return id;
	}
	bool isActive() {
		return active;
	}

	void work(CommonRes* comRes, Worker* othWorker, mutex* mtx);

};

class CommonRes {
	Worker* owner;
public:
	CommonRes(Worker* w) {
		this->owner = w;
	}

	Worker* getOwner () {
		return owner;
	}

	void setOwner (Worker* d, mutex& mtx1) {
		unique_lock<mutex> lock(mtx1);
		owner = d;
	}
};

	void Worker::work(CommonRes* comRes, Worker* othWorker, mutex* mtx)
	{
		unique_lock<mutex> lock(*mtx);
		mutex mtx1;
		while (active) {
			if (comRes->getOwner()->getId() != getId()) {
				this_thread::sleep_for(chrono::milliseconds(200));
				continue;
			}
			// If you don't wan't to have livelock give access to common resource consistently 
			// and don't handover, this code should be rewriten 
			if (othWorker->isActive()) {
				cout << "handover resource to worker " << othWorker->getName()<< endl;
				comRes->setOwner(othWorker, mtx1);
				continue;
			}

			// frolm current line starts common resource
			cout << getName() << " working on the common resource" << endl;
			active = false;
			comRes->setOwner(othWorker, mtx1);
			// end of common resoure.
		}
	}

int main()
{
	mutex mtx1;
	mutex mtx2;	
	Worker w1("w1", true, 1);
	Worker w2("w2", true, 2);
	CommonRes cR(&w1);
	thread t1(&Worker::work, &w1, &cR, &w2, &mtx1);
	thread t2(&Worker::work, &w2, &cR, &w1, &mtx2);	
	t1.join();
	t2.join();

	return 0;
}

