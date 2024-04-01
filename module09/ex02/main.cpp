#include "PmergeMe.hpp"

int main(int argc, char **argv) {
	if (argc < 2) {
		std::cout << "Error: Invalid parameters" << std::endl;
		std::cout << "Usage: ./PmergeMe <numbers>" << std::endl;
		return 1;
	}

	try {
		PmergeMe me;
		me.validateInput(argc, argv);
		me.fordJohnsonSort();
	} catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	return 0;
}
