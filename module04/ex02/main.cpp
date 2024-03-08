#include "AAnimal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main() {
	// const AAnimal *animal = new AAnimal();
	const AAnimal *cat = new Cat();
	const AAnimal *dog = new Dog();
	
	std::cout << "----CORRECT----" << std::endl;
	// std::cout << animal->getType() << std::endl;
	std::cout << cat->getType() << std::endl;
	std::cout << dog->getType() << std::endl;
	// animal->makeSound();
	cat->makeSound();
	dog->makeSound();

	std::cout << std::endl;
	std::cout << "----WRONG----" << std::endl;
	const WrongAnimal *wrongAnimal = new WrongCat();
	std::cout << wrongAnimal->getType() << std::endl;
	wrongAnimal->makeSound();

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "EXITING PROGRAM:" << std::endl;
	delete wrongAnimal;
	// delete animal;
	delete cat;
	delete dog;
	return 0;
}
