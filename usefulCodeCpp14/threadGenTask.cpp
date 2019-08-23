#include <iostream>
#include <thread>
#include <queue>
#include <chrono>
#include <mutex>
using namespace std;

struct Msg {
	int m_src_id;
	int m_src_msg_id;
	int m_srv_msg_id;
};

class Receiver {
public:
	void addMsg(Msg m) {
		unique_lock<mutex> lck{mtx};
		int i=0;
		m.m_srv_msg_id = i++;
		q.push(m);
	}
	int getQueueSize (){
		unique_lock<mutex> lck{mtx};
		return q.size();
	}

private:
	queue<Msg> q;
	mutex mtx;
};

class ThreadGen
{
public:
	explicit ThreadGen(int numThreads, int sec, Receiver& r) : seconds(sec), receiver(r) {
		for (auto i = 1; i<=numThreads; ++i) {
			nThreads.emplace_back([=]{
			try {
				int msgAmount = seconds/i;
				for (auto j = 1; j<=msgAmount; ++j) {
					this_thread::sleep_for(chrono::seconds(i));
					Msg m;
					m.m_src_id = i;
					m.m_src_msg_id = j;
					m.m_srv_msg_id = 0;
					receiver.addMsg(m);
				}
			} catch (exception& ex) {
				cout << "std exception was catched: " << ex.what() << "\n"; 
			} catch (...) {
				cout<< "thread" << i << "got unexpected error" << "\n";
			}
			});
		}
	}
  
	void joinThreads () {
		for (auto &thread: nThreads) {
			thread.join();
		}
	}
private:
	int seconds;
	Receiver& receiver;
	vector<thread> nThreads;
};

int main() {
	Receiver receiver;
	ThreadGen tG(3, 10, receiver);
	tG.joinThreads();
	cout << receiver.getQueueSize() << "\n";
	return 0;
}

