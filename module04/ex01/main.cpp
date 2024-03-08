#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main() {
	std::cout << "=====TEST 1=====" << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;
	delete i;

	std::cout << std::endl;
	std::cout << "=====TEST 2=====" << std::endl;
	Brain brain1;
	Brain brain2(brain1);
	Brain brain3;
	brain3 = brain1;

	std::cout << std::endl;
	std::cout << "=====TEST 3=====" << std::endl;
	Cat *cat = new Cat();
	Dog *dog = new Dog();

	cat->addIdea("I will rule the world");
	cat->addIdea("Why is this human petting me?");
	cat->addIdea("Feed me this instant, human!");

	dog->addIdea("Play");
	dog->addIdea("Guard house");
	dog->addIdea("Throw the ball for me!");

	std::cout<< "Cat ideas:" << std::endl;
	cat->printIdeas();
	std::cout<< "Dog ideas:" << std::endl;
	dog->printIdeas();

	delete cat;
	delete dog;
	return 0;
}
