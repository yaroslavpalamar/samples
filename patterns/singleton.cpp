#include <iostream>

class Singleton {
private:
	Singleton() {
		std::cout << "Singleton created" << "\n";
	}
	~Singleton() {
		std::cout << "Singleton destroyed" << "\n";
	}
	Singleton(const Singleton& other) = delete;
	Singleton& operator = (const Singleton& other) = delete;

	Singleton(const Singleton&& other) = delete;
	Singleton&& operator = (const Singleton&& other) = delete;

public:
	static Singleton& getInstance() 
	{
		static Singleton inst;
		return inst;
	}
};

int
main () 
{
	Singleton& s = Singleton::getInstance();
	return 0;
}
