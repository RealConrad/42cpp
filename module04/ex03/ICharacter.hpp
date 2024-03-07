#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include <iostream>
#include "AMateria.hpp"

// Forward declare the class.
// Forward declaration tells the compiler that a class will be defined later
class AMateria;

class ICharacter {
	public:
		virtual ~ICharacter() {}
		virtual std::string const & getName() const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;
};

#endif