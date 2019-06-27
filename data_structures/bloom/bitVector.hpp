#ifndef BIT_VECTOR
#define BIT_VECTOR

#include <cmath>

template <class data_type>
class BitVector {
	size_t vec_size;
	data_type* array;
	const int BITS_PER_BYTE = 8;

	BitVector(const BitVector& other) = delete;
	BitVector& operator = (const BitVector& other) = delete;
	BitVector(const BitVector&& other) = delete;
	BitVector& operator = (const BitVector&& other) = delete;
public:
	explicit BitVector () {
		this->vec_size = 1;
		this->array = new data_type[this->vec_size];
		this->array[0] = 0;
	}
	
	~BitVector () {
		delete [] this->array;
	}

	/// Change the capacity of new vector
	/// @param  {const size_t&} size The new capacity.
	/// @return {void}
	void resize(const size_t& size) {
		unsigned int i;
		data_type* new_internal_array = new data_type[size];
		for (i = 0; i < this->vec_size; ++i) {
			this->array[i] = new_internal_array[i];
		}
		this->vec_size = size;
		delete [] this->array;
		this->array = new_internal_array;
	}
	
	//TODO:	
	/// As for required method new I am not clearly understand what I need to do.
	/// I decided to not overload new operator and juxt create method new1.
	/// @param  {const size_t&} size The new capacity.
	/// @return {void}
	void new1 (const size_t& size) {
		this->resize(size);
	}
	
	/// Provides the value of bit at the given position.
	/// @param  {const size_t&} pos The position within the vector.
	/// @return {bool}              The success of the look up.
	bool get_bit(const size_t& pos) const {
		if (pos < 0 || pos >= this->vec_size * sizeof(data_type) * BITS_PER_BYTE) {
			throw std::range_error("Attempted to access an illegal position in BitVector.");
		}
		int index = floor((pos + 1) / (sizeof(data_type) * BITS_PER_BYTE));
		int seqCpy = this->array[index];
		return (seqCpy >> ((sizeof(data_type) * BITS_PER_BYTE) - pos)) & 1;
	}

	/// Attempts to set a particular bit within the BitVector.
	/// @param  {const size_t&}  pos  The position within the vector.
	/// @param  {const bool&} data The bit to set.
	/// @return {void}
	void set_bit(const size_t& pos, const bool& data) {
		if (pos < 0 || pos >= this->vec_size * sizeof(data_type) * BITS_PER_BYTE) {
			throw std::range_error("Attempted to access an illegal position in BitVector.");
		}
		int index = floor((pos + 1) / ((sizeof(data_type) * BITS_PER_BYTE)));
		if (data) {
			this->array[index] |= 1 << ((sizeof(data_type) * BITS_PER_BYTE) - pos);
		} else {
			this->array[index] &= ~(1 << ((sizeof(data_type) * BITS_PER_BYTE) - pos));
		}
	}

	data_type operator[] (const size_t& pos) const {
		return this->get_bit(pos);
	}

	size_t size () const {
		return this->vec_size * sizeof(data_type) * BITS_PER_BYTE;	
	}
	
};

#endif
