#include "Harl.hpp"

int main(int argc, char **argv) {
	(void)argv;
	if (argc != 1) {
		std::cout << "No arguments allowed :)" << std::endl;
		return (1);
	}
	Harl harl;
	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");
	harl.complain("INVALID");
	return 0;
}