#include <iostream>
#include "bloomFilter.hpp"


int main()
{
	BloomFilter filter(10000, 10);
	std::string str_list[] = { "AbC", "iJk", "XYZ" };

	/* Insert into Bloom Filter */

	// Insert some strings
	for (std::size_t i = 0; i < (sizeof(str_list) / sizeof(std::string)); ++i) {
		filter.insert(str_list[i]);
	}

	// Insert some numbers
	for (std::size_t i = 0; i < 100; ++i) {
		filter.insert(i);
	}



	/* Query Bloom Filter */

	// Query the existence of strings
	for (std::size_t i = 0; i < (sizeof(str_list) / sizeof(std::string)); ++i) {
		if (filter.contains(str_list[i])) {
			std::cout << "BF contains: " << str_list[i] << std::endl;
		}
	}

	// Query the existence of numbers
	for (std::size_t i = 0; i < 100; ++i) {
		if (filter.contains(i)) {
			std::cout << "BF contains: " << i << std::endl;
		}
	}

	std::string invalid_str_list[] = { "AbCX", "iJkX", "XYZX" };

	// Query the existence of invalid strings
	for (std::size_t i = 0; i < (sizeof(invalid_str_list) / sizeof(std::string)); ++i) {
		if (filter.contains(invalid_str_list[i])) {
			std::cout << "BF falsely contains: " << invalid_str_list[i] << std::endl;
		}
	}

	// Query the existence of invalid numbers
	for (int i = -1; i > -100; --i) {
		if (filter.contains(i)) {
			std::cout << "BF falsely contains: " << i << std::endl;
		}
	}

	return 0;
}

