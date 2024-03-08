#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#include <iostream>

class Cure: public AMateria {
	public:
		Cure();
		Cure(const Cure& other);
		Cure& operator=(const Cure& other);
		virtual ~Cure();

		//override clone()
		virtual AMateria* clone() const;
		//override use()
		virtual void use(ICharacter& target);
};

#endif