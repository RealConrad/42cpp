#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; i++) {
		this->templates[i] = NULL;
	}
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++) {
		delete this->templates[i];
	}
}

void MateriaSource::learnMateria(AMateria *m) {
	for (int i = 0; i < 4; i++) {
		if (!this->templates[i]) {
			this->templates[i] = m;
			return ;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const& type) {
	for (int i = 0; i < 4; i++) {
		if (this->templates[i] && this->templates[i]->getType() == type) {
			return this->templates[i]->clone();
		}
	}
	return NULL;
}

