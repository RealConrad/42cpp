#include "Zombie.hpp"

int main(void) {
	Zombie* horde = zombieHorde(-1, "Bob");

	delete[] horde;
	return (0);
}
