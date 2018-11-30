#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>

using namespace std;

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
public:
	Worker* owner;
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
			// If you don't wan't to have livelock just comment out from lines (62-66) and (82-86) 
			// also uncomment line 80,81 for sequetially execution.
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
	//w1.work(&cR, &w2, &mtx1);
	//w2.work(&cR, &w1, &mtx2);
	thread t1(&Worker::work, &w1, &cR, &w2, &mtx1);
	thread t2(&Worker::work, &w2, &cR, &w1, &mtx2);	
	t1.join();
	t2.join();

	return 0;
}

