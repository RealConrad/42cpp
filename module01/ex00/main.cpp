
#include "Zombie.hpp"

int main(void) {
	std::cout << "Creating a zombie on stack:" << std::endl;
	Zombie z1("Bob");
	z1.announce();

	std::cout << std::endl;
	std::cout << "Creating a zombie on Heap:" << std::endl;
	Zombie *z2 = newZombie("Jerry");
	z2->announce();

	std::cout << std::endl;
	std::cout << "Destroying objects:" << std::endl;
	delete z2;
	return (0);
}
