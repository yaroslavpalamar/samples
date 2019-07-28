#include <iostream>
#include <new>

struct Widget
{
	int i;
	const int j;
};

int main()
{
	auto w = new Widget{1,2};
	// placement new example
	new(w) Widget{3,4}; //in this case we rewrite const j, which is undefined behaviour
	// to resolve undefined behaviour use std launder
	std::cout << *std::launder(&w->j);

	delete w;
	return 0;
}
