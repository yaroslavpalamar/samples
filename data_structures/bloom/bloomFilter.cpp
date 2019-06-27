#include <iostream>
#include "bloomFilter.hpp"
#include <fstream>

void bloomFilterTest1() {
	BloomFilter filter(33548945, 23);
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
		if (filter.check(str_list[i])) {
			std::cout << "BF contains: " << str_list[i] << std::endl;
		}
	}

	// Query the existence of numbers
	for (std::size_t i = 0; i < 100; ++i) {
		if (filter.check(i)) {
			std::cout << "BF contains: " << i << std::endl;
		}
	}

	std::string invalid_str_list[] = { "AbCX", "iJkX", "XYZX" };

	// Query the existence of invalid strings
	for (std::size_t i = 0; i < (sizeof(invalid_str_list) / sizeof(std::string)); ++i) {
		if (filter.check(invalid_str_list[i])) {
			std::cout << "BF falsely contains: " << invalid_str_list[i] << std::endl;
		}
	}

	// Query the existence of invalid numbers
	for (int i = -1; i > -100; --i) {
		if (filter.check(i)) {
			std::cout << "BF falsely contains: " << i << std::endl;
		}
	}
}

template <class T, class Allocator,
          template <class,class> class Container>
bool readFile(const std::string& fileName, Container<T, Allocator>& c)
{
	std::ifstream stream(fileName.c_str());
	if (!stream) {   
		std::cout << "Error: Failed to open file '" << fileName << "'" << std::endl;
		return false;
	}

	std::string buffer;
	while (std::getline(stream, buffer)) {
		c.push_back(buffer);
	}

	return true;
}

bool loadWords(std::vector<std::string>& wordList, std::string& fileName)
{
	std::cout << "Loading words from " << fileName << ".....";

	if (!readFile(fileName,wordList)) {
		return false;
	}

	if (wordList.empty()) {
		std::cout << "No word list - Either none requested, or desired word list could not be loaded." << std::endl;
		return false;
	} else
		std::cout << " Complete." << std::endl;

	return true;
}


int checkIfContains (BloomFilter& filter, std::vector<std::string>& words, std::string& file, bool err) {
	std::string msg = "BF contains: ";
	if (!err)
		msg = "BF false contains: ";
		
	if (!loadWords(words, file)) {   
		return 0;
	}
	int size = words.size();
	for (int i = 0; i < size; ++i) {
		if (filter.check(words[i])) {
			std::cout << msg << words[i] << std::endl;
		}
	}
	return 1;
}

bool bloomFilterTest2() {
	BloomFilter filter(33548945, 23);

	std::vector<std::string> wordsInFilter;
	std::string inputFile = "h1.txt";
	if (!loadWords(wordsInFilter, inputFile)) {   
		return 0;
	}
	int wordsSize = wordsInFilter.size();
	for (int i = 0; i < wordsSize; ++i) {
		filter.insert(wordsInFilter[i]);
	}


	std::vector<std::string> wordsToFind;
	std::string checkFile = "h2.txt";
	if (!checkIfContains(filter ,wordsToFind, checkFile, true)) {   
		return 0;
	}

	std::vector<std::string> falseWords;
	std::string falseWordsFile = "random-list.txt";
	if (!checkIfContains(filter, falseWords, falseWordsFile, false)) {   
		return 0;
	}

	return 1;
}

int main()
{
	bloomFilterTest1(); 
	
	if (!bloomFilterTest2()) {
		return 1;
	}

	return 0;
}

