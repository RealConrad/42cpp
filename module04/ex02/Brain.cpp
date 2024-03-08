#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain construcotr called" << std::endl;
}

Brain::~Brain() {
	std::cout << "Brain descontructor called" << std::endl;
}

Brain::Brain(const Brain& copy) {
	for (int i = 0; i < 100; i++) {
		this->ideas[i] = copy.ideas[i];
	}
	std::cout << "Brain copy contructor called" << std::endl;
}

Brain& Brain::operator=(const Brain& copy) {
	for (int i = 0; i < 99; i++) {
		this->ideas[i] = copy.ideas[i];
	}
	std::cout << "Brain copy assignment contructor called" << std::endl;
	return *this;
}

void Brain::addIdea(const std::string& idea) {
	for (int i = 0; i < 100; i++) {
		if (this->ideas[i].empty()) {
			this->ideas[i] = idea;
			break ;
		}
	}
}

void Brain::printIdeas() const {
	for (int i = 0; i < 100; i++) {
		if (!this->ideas[i].empty()) {
			std::cout << "Idea " << i + 1 << " :" << this->ideas[i] << std::endl;
		}
	}
}

