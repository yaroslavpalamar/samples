#ifndef INCLUDE_BLOOM_FILTER_HPP
#define INCLUDE_BLOOM_FILTER_HPP

#include <vector>
#include <array>
#include "bloomFilterTask.hpp"
#include "hashGen.hpp"
#include "bitVector.hpp"

/// Bloom filter sample with insert and check operations
class BloomFilter {
	std::vector<bool> bitVector;
	uint8_t k;

	void insert(const uint8_t* data, const std::size_t& len) 
	{
		HashGenerator hash(data, len);
        	for (int n = 0; n < k; n++) {
                	bitVector[hash.nthHash(n, bitVector.size())] = true;
        	}
	}

	bool check(const uint8_t *data, const std::size_t& len) const 
	{
		HashGenerator hash(data, len);
		for (int n = 0; n < k; n++) {
			if (!bitVector[hash.nthHash(n, bitVector.size())]) {
				return false;
                	}
        	}
	        return true;
	}
public:
	/// Construct a bit vector and set size of hash functions
	/// @param m The number of cells
	/// @param k The number of hash functions
	BloomFilter(uint64_t m, uint8_t k) : bitVector(m, false)
	{
		this->k = k;
	}
	
	
	/// Adds an element to the Bloom filter
	/// @param key The element to insert 
	void insert(const std::string& key) 
	{
		insert(reinterpret_cast<const uint8_t*>(key.data()),key.size());
	}
	

	/// Check if element exist in Bloom filter
	/// @param key The element to check
	bool check(const std::string& key) const
	{
		return check(reinterpret_cast<const uint8_t*>(key.c_str()),key.size());
	}
};

#endif

