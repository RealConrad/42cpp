#include "Zombie.hpp"

/**
 * @brief Allocates memory for a new Zombie class
 * @param name The name of the zombie
 * @return A pointer to the newly allocated Zombie class
 */
Zombie* newZombie(std::string name) {
	return (new Zombie(name));
}
