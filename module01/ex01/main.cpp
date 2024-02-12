#include "Zombie.hpp"

int main(void) {
	Zombie* horde = zombieHorde(2, "Bob");

	delete[] horde;
	return (0);
}
