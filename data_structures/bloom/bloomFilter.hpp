#ifndef INCLUDE_BLOOM_FILTER_HPP
#define INCLUDE_BLOOM_FILTER_HPP

#include <vector>
#include <array>
#include "bloomFilter.hpp"
#include "MurmurHash3.h"

/*
	Based on article below we need to use two hash functions h1(x) and 
		h2(x) to simulate additional hash functions of the form: 
		gi(x) = h1(x) + ih2(x)
	To get two hash function have been used next function MurmurHash3_x64_128 from library:
		https://github.com/aappleby/smhasher
		MurmurHash3_x64_128 function generates a 128 bit hash, and we need 2 64 bit hashes, 
		we can split the returned hash in half to get hasha(x) and hashb(x) 
	Article - http://citeseer.ist.psu.edu/viewdoc/download;jsessionid=4060353E67A356EF9528D2C57C064F5A?doi=10.1.1.152.579&rep=rep1&type=pdf 
*/
class HashGenerator {
	std::array<uint64_t, 2> hashValue;
public:
	HashGenerator(const uint8_t *data, std::size_t len) {
		MurmurHash3_x64_128(data, len, 0, hashValue.data());
	}

	uint64_t nthHash(uint8_t n, uint64_t filterSize) {
		uint64_t hashA = hashValue[0];
		uint64_t hashB = hashValue[1];
        	return (hashA + n * hashB) % filterSize;
	}
};


/*
	k - number of hash functions
	bitVector - base data structure of a Bloom filter
*/
class BloomFilter {
	std::vector<bool> bitVector;
	uint8_t k;

public:
	BloomFilter(uint64_t m, uint8_t k) : bitVector(m, false)
	{
		this->k = k;
	}
	
	template <typename T>
	void insert(const T& t) 
	{
		insert(reinterpret_cast<const unsigned char*>(&t),sizeof(T));
	}

	void insert(const unsigned char* data, const std::size_t& len) 
	{
		HashGenerator hash(data, len);
        	for (int n = 0; n < k; n++) {
                	bitVector[hash.nthHash(n, bitVector.size())] = true;
        	}
	}

	void insert(const std::string& key) 
	{
		insert(reinterpret_cast<const unsigned char*>(key.data()),key.size());
	}

	
	bool check(const unsigned char *data, const std::size_t& len) const 
	{
		HashGenerator hash(data, len);
		for (int n = 0; n < k; n++) {
			if (!bitVector[hash.nthHash(n, bitVector.size())]) {
				return false;
                	}
        	}
	        return true;
	}

	bool check(const std::string& key) const
	{
		return check(reinterpret_cast<const unsigned char*>(key.c_str()),key.size());
	}

	template <typename T>
	bool check(const T& t) const 
	{
		return check(reinterpret_cast<const unsigned char*>(&t),static_cast<std::size_t>(sizeof(T)));
	}
};

#endif

