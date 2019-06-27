#ifndef INCLUDE_BLOOM_FILTER_HPP
#define INCLUDE_BLOOM_FILTER_HPP

#include <vector>
#include <array>
#include "bloomFilterTask.hpp"
#include "hashGen.hpp"
#include "bitVector.hpp"

/// Bloom filter sample with insert and check operations
class BloomFilter {
	BitVector<int> bitVector;
	uint8_t k;

	void insert(const uint8_t* data, const std::size_t& len) {
		HashGenerator hash(data, len);
        	for (int n = 0; n < k; n++) {
			try {
                		bitVector.set_bit(hash.nthHash(n, bitVector.size()), true);
			} catch (const std::exception& e) {
				std::cout << e.what() << "\n";
				std::abort();
			}
        	}
	}

	bool check(const uint8_t *data, const std::size_t& len) const {
		HashGenerator hash(data, len);
		for (int n = 0; n < k; n++) {
			try {
				if (!bitVector[hash.nthHash(n, bitVector.size())]) {
					return false;
             			}	
			} catch (const std::exception& e) {
				std::cout << e.what() << "\n";
				std::abort();
			}
        	}
	        return true;
	}
	BloomFilter(const BloomFilter& other) = delete;
	BloomFilter& operator = (const BloomFilter& other) = delete;

	BloomFilter(const BloomFilter&& other) = delete;
	BloomFilter&& operator = (const BloomFilter&& other) = delete;

public:
	/// Construct a bit vector and set size of hash functions
	/// @param m The number of cells
	/// @param k The number of hash functions
	explicit BloomFilter(uint64_t m, uint8_t k) {
		// TODO:
		// as for required method new(int vec_size) described in task 
		// description I am not clearly understand, should I overload operator new 
		// or it can be other name like resize or just init it in constructor.
		bitVector.new1(m);
		std::cout << "Size on creation: " << bitVector.size() << "\n";
		try {
			bitVector.set_bit(m, true);
		} catch (const std::exception& e) {
			std::cout << e.what() << "\n";
			std::abort();
		}

		this->k = k;
	}
	
	
	/// Adds an element to the Bloom filter
	/// @param key The element to insert 
	void insert(const std::string& key)  {
		insert(reinterpret_cast<const uint8_t*>(key.data()),key.size());
	}
	

	/// Check if element exist in Bloom filter
	/// @param key The element to check
	bool check(const std::string& key) const {
		return check(reinterpret_cast<const uint8_t*>(key.c_str()),key.size());
	}
};

#endif

