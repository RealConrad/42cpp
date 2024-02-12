#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
	if (N < 0) {
		std::cout << "ERROR: Enter a positive number :)" << std::endl;
		return (NULL);
	}
	else {
		Zombie* horde = new Zombie[N];

		for (int i = 0; i < N; i++) {
			horde[i].setName(name);
			horde[i].annouce();
		}
		return (horde);
	}
}
