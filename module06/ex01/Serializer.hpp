#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <string>
#include <cstdlib>
#include <stdint.h>
#include "Data.hpp"

class Serializer {
	private:
		Serializer();

	public:
		Serializer(const Serializer& other);
		Serializer& operator=(const Serializer& other);
		~Serializer();

		static Data* deserialize(uintptr_t raw);
		static uintptr_t serialize(Data* ptr);
};

#endif