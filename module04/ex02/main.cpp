#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main() {
	// const Animal *animal = new Animal();
	const Animal *cat = new Cat();
	const Animal *dog = new Dog();
	
	std::cout << "----CORRECT----" << std::endl;
	// std::cout << animal->getType() << std::endl;
	std::cout << cat->getType() << std::endl;
	std::cout << dog->getType() << std::endl;
	// animal->makeSound();
	cat->makeSound();
	dog->makeSound();

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "EXITING PROGRAM:" << std::endl;
	// delete animal;
	delete cat;
	delete dog;
	return 0;
}
