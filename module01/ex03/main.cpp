#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"


int main(void) {
	Weapon weapon;
	weapon.setType("Rapier");

	HumanA human1;
	human1.setName("Bob");
	human1.attack();
	human1.setWeapon(weapon);
	human1.attack();

	std::cout << std::endl;

	HumanB human2;
	human2.setName("Gary");
	human2.attack();
	human2.setWeapon(weapon);
	human2.attack();

	return (0);
}
