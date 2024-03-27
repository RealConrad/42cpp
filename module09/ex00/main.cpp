#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Error: Specify 1 file" << std::endl;
		std::cout << "Usage: ./btc <file-name>" << std::endl;
		return 1;
	}
	BitcoinExchange btc;
	btc.loadPricesFromFile("data.csv");
	btc.calculateValue(argv[1]);
	return 0;
}
