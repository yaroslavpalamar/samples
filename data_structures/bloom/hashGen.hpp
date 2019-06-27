#ifndef HASH_GEN
#define HASH_GEN
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



#endif

