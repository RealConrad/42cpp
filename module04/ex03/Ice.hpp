#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include <iostream>

class Ice: public AMateria {
	public:
		Ice();
		virtual ~Ice();

		// override clone() to return a new instance of Ice class
		virtual AMateria* clone() const;
		// override use() to display specific message
		virtual void use(ICharacter& target);
};

#endif