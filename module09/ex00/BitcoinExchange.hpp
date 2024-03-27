#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include <sstream>

enum valueType {
	ERR_TOO_LARGE,
	ERR_NEGATIVE,
	ERR_NAN,
	VALID
};
class BitcoinExchange {
	private:
		std::map<std::string, double> prices;
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();

		bool isValidDate(const std::string& date);
		valueType isValidValue(const std::string& rateStr);
		double calculateExchangeRate(const std::string& date);
		int daysInMonth(int year, int month);
		void loadPricesFromFile(const std::string& filename);
		void calculateValue(const std::string& filename);
		std::map<std::string, double>& getPrices();
};

#endif