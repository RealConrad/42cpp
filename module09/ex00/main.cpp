#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Only 1 parameter allowed" << std::endl;
		return 0;
	}
	BitcoinExchange btc;
	btc.loadPricesFromFile("data.csv");
	btc.calculateValue(argv[1]);

	return 0;
}
