#include <iostream>

template<class T>
class SingletonT 
{
protected:
	SingletonT() = default;
	SingletonT(const SingletonT& other) = delete;
	SingletonT& operator = (const SingletonT& other) = delete;

	SingletonT(const SingletonT&& other) = delete;
	SingletonT& operator = (const SingletonT&& other) = delete;

public:
	static T& getInstance() 
	{
		static T inst;
		return inst;
	}

};

class Singleton2 : public SingletonT<Singleton2> {
private:
	Singleton2() = default;
	Singleton2(const Singleton2& other) = delete;
	Singleton2& operator = (const Singleton2& other) = delete;

	Singleton2(const Singleton2&& other) = delete;
	Singleton2& operator = (const Singleton2&& other) = delete;

	friend class SingletonT<Singleton2>;
};

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
	Singleton& operator = (const Singleton&& other) = delete;

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
	auto &s2 = Singleton2::getInstance();
	return 0;
}
