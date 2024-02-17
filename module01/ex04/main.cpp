#include "Sed.hpp"

int main(int argc, char **argv) {
	if (argc != 4)
	{
		std::cout << "Only 4 arguments allowed :)" << std::endl;
		return 1;
	}
	Sed sed(argv[1], argv[2], argv[3]);
	sed.replace();
	return 0;
}
