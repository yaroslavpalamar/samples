#include <iostream>
#include <string>
#include <set>
using namespace std;

class Subject;

class Observer {
public:
	virtual void update(Subject & subject) = 0;
};

// also knows as Observable in literature
class Subject
{
	string state;
	set<Observer*> observers;
	void notifyObservers() {
		for (auto &o : observers) {
			o->update(*this);
		}
	}
public:
	void attachObserver(Observer *o) { observers.insert(o); }
	void detachObserver(Observer *o) { observers.erase(o); }
	string getState() { return state; }
	
	void changeState(const string & s) {
		state = s;
		notifyObservers();
	}
};


//different objects which will be updated by one mechanizm in subject object
class ObserverImpl : public Observer
{
	string state;
public:
	void update(Subject & sbj) override {
		cout << "obj ObserverImpl was updated"<<endl;
		state = sbj.getState();
	}
	string getState() { return state; }
};

class SecondObservImpl : public Observer
{
	string state;
public:
	void update(Subject & sbj) override {
		cout << "obj SecondObservImpl was updated"<<endl;
		state = sbj.getState();
	}
	string getState() { return state+"abc"; }
};

int 
main(int argv, char** argc)
{
	// create four objects a,b and they will observ changes in "subject" object
	ObserverImpl a;
	SecondObservImpl b;

	// subject objec will notify observers
	Subject subject;
	subject.attachObserver(&a);
	subject.attachObserver(&b);
	
	// call changeState to notify all observers
	subject.changeState("Notify all observ impl and print them");
	cout << a.getState() << endl;
	cout << b.getState() << endl;
	
	// check if state was changed after detach one observ
	subject.detachObserver(&a);
	subject.changeState("Changed observer impl and print them");
	cout << a.getState() << endl;
	cout << b.getState() << endl;

	return 0;
}

