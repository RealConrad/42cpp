#include "DiamondTrap.hpp"

int main(void) {
	DiamondTrap d1("Bob");

	d1.attack("Jerry");
	d1.whoAmI();
	std::cout << std::endl;
	return 0;
}
