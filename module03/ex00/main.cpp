#include "ClapTrap.hpp"

int main(void) {

	ClapTrap ct1("Bob");
	ClapTrap ct2("Jerry");

	ct1.attack("Harry");
	ct1.takeDamage(16);
	ct1.beRepaired(5);

	ct2.attack("Conrad");
	ct2.takeDamage(2);
	ct2.beRepaired(2);
	return 0;
}