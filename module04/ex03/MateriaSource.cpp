#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; i++) {
		this->templates[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource& other) {
	for (int i = 0; i < 4; i++) {
		this->templates[i] = NULL;
	}
	for (int i = 0; i < 4; i++) {
		if (other.templates[i])
			this->templates[i] = other.templates[i];
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
	if (this != &other) {
		for (int i = 0; i < 4; i++) {
			delete this->templates[i];
			this->templates[i] = NULL;
		}

		for (int i = 0; i < 4; i++) {
			if (other.templates[i])
				this->templates[i] = other.templates[i];
		}
	}
	return *this;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++) {
		delete this->templates[i];
	}
}

void MateriaSource::learnMateria(AMateria *m) {
	for (int i = 0; i < 4; i++) {
		if (!this->templates[i]) {
			if (dynamic_cast<Ice *>(m))
				this->templates[i] = new Ice(*dynamic_cast<Ice *>(m));
			else if (dynamic_cast<Cure *>(m))
				this->templates[i] = new Cure(*dynamic_cast<Cure *>(m));
			return ;
		}
	}
	std::cout << "Cannot learn more materia!" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const& type) {
	for (int i = 0; i < 4; i++) {
		if (this->templates[i] && this->templates[i]->getType() == type) {
			return this->templates[i]->clone();
		}
	}
	return NULL;
}
