#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>
#include <string>

class Zombie {
	private:
		std::string name;
	
	public:
		~Zombie(void);
		void annouce(void);
		void setName(std::string name);
};

Zombie* zombieHorde(int N, std::string name);

#endif