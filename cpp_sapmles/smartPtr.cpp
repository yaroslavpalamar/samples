#include <iostream>
#include <memory>

class A {
public:
	virtual void f() {
		std::cout << "A" << "\n";
	}
	virtual ~A() {
	}
};

class B : public A {
public:
	virtual void f() {
		std::cout << "B" << "\n";
	}
};

int
main() {
	std::unique_ptr<A> a = std::make_unique<B>();
	a->f();
}
