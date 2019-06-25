#ifndef INCLUDE_BLOOM_FILTER_HPP
#define INCLUDE_BLOOM_FILTER_HPP

#include <vector>

//template< class Key, class Hash = std::hash<Key> >
struct BloomFilter {
	std::vector<bool> m_bits;
	uint8_t m_numHashes;

	BloomFilter(uint64_t size, uint8_t numHashes);

	void insert(const uint8_t *data, std::size_t len);
	bool contains(const uint8_t *data, std::size_t len) const;
};


#endif

