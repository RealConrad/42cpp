#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {

	ScavTrap s1("Bob");
	ClapTrap t1("Jerry");

	std::cout << std::endl;
	s1.attack("Jerry");
	s1.guardGate();

	std::cout << std::endl;
	t1.beRepaired(10);
	t1.attack("Bob");
	std::cout << std::endl;
	return 0;
}
