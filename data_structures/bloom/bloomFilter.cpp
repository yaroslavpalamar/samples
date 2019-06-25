#include <iostream>
#include <string>
#include <array>

#include "MurmurHash3.h"
#include "bloomFilter.hpp"


BloomFilter::BloomFilter(uint64_t size, uint8_t numHashes)
      : m_bits(size),
        m_numHashes(numHashes) {}

std::array<uint64_t, 2> hash(const uint8_t *data,
                             std::size_t len) {
  std::array<uint64_t, 2> hashValue;
  MurmurHash3_x64_128(data, len, 0, hashValue.data());

  return hashValue;
}

inline uint64_t nthHash(uint8_t n,
                        uint64_t hashA,
                        uint64_t hashB,
                        uint64_t filterSize) {
    return (hashA + n * hashB) % filterSize;
}

void BloomFilter::insert(const uint8_t *data, std::size_t len) {
  auto hashValues = hash(data, len);

  for (int n = 0; n < m_numHashes; n++) {
      m_bits[nthHash(n, hashValues[0], hashValues[1], m_bits.size())] = true;
  }
}

bool BloomFilter::contains(const uint8_t *data, std::size_t len) const {
  auto hashValues = hash(data, len);

  for (int n = 0; n < m_numHashes; n++) {
      if (!m_bits[nthHash(n, hashValues[0], hashValues[1], m_bits.size())]) {
          return false;
      }
  }

  return true;
}

int main()
{
	BloomFilter filter(300, 3);
/*   bloom_parameters parameters;
   // How many elements roughly do we expect to insert?
   parameters.projected_element_count = 1000;
   // Maximum tolerable false positive probability? (0,1)
   parameters.false_positive_probability = 0.0001; // 1 in 10000
   // Simple randomizer (optional)
   parameters.random_seed = 0xA5A5A5A5;
   if (!parameters)
   {
      std::cout << "Error - Invalid set of bloom filter parameters!" << std::endl;
      return 1;
   }
   parameters.compute_optimal_parameters();



   bloom_filter filter(parameters);
*/
   std::string str_list[] = { "AbC", "iJk", "XYZ" };

   // Insert into Bloom Filter
   {
      // Insert some strings
      for (std::size_t i = 0; i < (sizeof(str_list) / sizeof(std::string)); ++i)
      {
         filter.insert((const uint8_t*)str_list[i], sizeof(str_list[i]));
      }

      // Insert some numbers
      for (std::size_t i = 0; i < 100; ++i)
      {
         filter.insert((const uint8_t*)i, sizeof(i));
      }
   }

   // Query Bloom Filter
   {
      // Query the existence of strings
      for (std::size_t i = 0; i < (sizeof(str_list) / sizeof(std::string)); ++i)
      {
         if (filter.contains((const uint8_t*)str_list[i], sizeof(str_list[i])))
         {
            std::cout << "BF contains: " << str_list[i] << std::endl;
         }
      }

      // Query the existence of numbers
      for (std::size_t i = 0; i < 100; ++i)
      {
         if (filter.contains((const uint8_t*)i, sizeof(i)))
         {
            std::cout << "BF contains: " << i << std::endl;
         }
      }

      std::string invalid_str_list[] = { "AbCX", "iJkX", "XYZX" };

      // Query the existence of invalid strings
      for (std::size_t i = 0; i < (sizeof(invalid_str_list) / sizeof(std::string)); ++i)
      {
         if (filter.contains((const uint8_t*)invalid_str_list[i], sizeof(invalid_str_list[i])))
         {
            std::cout << "BF falsely contains: " << invalid_str_list[i] << std::endl;
         }
      }

      // Query the existence of invalid numbers
      for (int i = -1; i > -100; --i)
      {
         if (filter.contains((const uint8_t*)i, sizeof(i)))
         {
            std::cout << "BF falsely contains: " << i << std::endl;
         }
      }
   }

   return 0;
}
