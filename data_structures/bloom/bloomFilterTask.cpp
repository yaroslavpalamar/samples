#include <iostream>
#include "bloomFilterTask.hpp"
#include <fstream>
#include <vector>

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

bool bloomFilterTest(const int BF_BIT_VEC_SIZE, const int HASH_NUM) {
	BloomFilter filter(BF_BIT_VEC_SIZE, HASH_NUM);

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
	const int HASH_NUM = 23;
	const int BF_BIT_VEC_SIZE = 33548945;
	if (!bloomFilterTest(BF_BIT_VEC_SIZE, HASH_NUM)) {
		return 1;
	}

	return 0;
}

