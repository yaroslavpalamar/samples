#ifndef INCLUDE_BLOOM_FILTER_HPP
#define INCLUDE_BLOOM_FILTER_HPP

#include <vector>
#include <array>
#include "bloomFilter.hpp"
#include "MurmurHash3.h"


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

class BloomFilter {
	std::vector<bool> vec_size;
	uint8_t k;

public:
	BloomFilter(uint64_t m, uint8_t numHashes) : vec_size(m, false)
	{
		k = numHashes;
	}

	void insert(const unsigned char* data, const std::size_t& len) {
		HashGenerator hash(data, len);
        	for (int n = 0; n < k; n++) {
                	vec_size[hash.nthHash(n, vec_size.size())] = true;
        	}
	}

	template <typename T>
	void insert(const T& t) {
		insert(reinterpret_cast<const unsigned char*>(&t),sizeof(T));
	}

	inline void insert(const std::string& key) {
		insert(reinterpret_cast<const unsigned char*>(key.data()),key.size());
	}

	bool contains(const unsigned char *data, const std::size_t& len) const {
		HashGenerator hash(data, len);
		for (int n = 0; n < k; n++) {
			if (!vec_size[hash.nthHash(n, vec_size.size())]) {
				return false;
                	}
        	}

	        return true;
	}

	inline bool contains(const std::string& key) const
	{
		return contains(reinterpret_cast<const unsigned char*>(key.c_str()),key.size());
	}

	template <typename T>
	inline bool contains(const T& t) const
	{
		return contains(reinterpret_cast<const unsigned char*>(&t),static_cast<std::size_t>(sizeof(T)));
	}
};

#endif

