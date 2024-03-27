#include "BitcoinExchange.hpp"


/* -------------------------------------------------------------------------- */
/*                              Helper functions                              */
/* -------------------------------------------------------------------------- */

std::string trim(const std::string& str) {
	size_t first = str.find_first_not_of(' ');
	if (first == std::string::npos)
		return ""; // string is all spaces

	size_t last = str.find_last_not_of(' ');
	return str.substr(first, (last - first + 1));
}

bool isOnlyDigits(const std::string& str) {
	for (size_t i = 0; i < str.length(); i++) {
		if (!std::isdigit(str[i])) {
			return false;
		}
	}
	return true;
}

/* -------------------------------------------------------------------------- */
/*                               Class functions                              */
/* -------------------------------------------------------------------------- */

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other): prices(other.prices) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this != &other) {
		this->prices = other.prices;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

std::map<std::string, double>& BitcoinExchange::getPrices() {
	return this->prices;
}

int BitcoinExchange::daysInMonth(int year, int month) {
	bool isLeapYear = false;
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		isLeapYear = true;
	switch (month) {
		case 4:
		case 6:
		case 9:
		case 11:
			return 30;
		case 2:
			return isLeapYear ? 29 : 28;
		default:
			return 31;
	}
}

bool BitcoinExchange::isValidDate(const std::string& date) {
	int year, month, day;
	std::string temp;

	std::stringstream dateStream(trim(date));
	
	// Get year
	std::getline(dateStream, temp, '-');
	if (!isOnlyDigits(temp))
		return false;
	std::istringstream(temp) >> year;

	// Get month
	std::getline(dateStream, temp, '-');
	if (!isOnlyDigits(temp))
		return false;
	std::istringstream(temp) >> month;

	// Get day
	std::getline(dateStream, temp);
	if (!isOnlyDigits(temp))
		return false;
	std::istringstream(temp) >> day;

	// Check valid date ranges
	if (year < 0 || year > 9999)
		return false;
	if (month < 1 || month > 12)
		return false;
	if (day < 1 || day > daysInMonth(year, month))
		return false;
	return true;
}

valueType BitcoinExchange::isValidValue(const std::string& rateStr) {
	std::istringstream iss(trim(rateStr));
	double rate;
	iss >> rate;
	if (iss.fail())
		return ERR_NAN;
	if (rate < 0)
		return ERR_NEGATIVE;
	if (rate > INT_MAX)
		return ERR_TOO_LARGE;
	return VALID;
}

double BitcoinExchange::calculateExchangeRate(const std::string& date) {
	std::map<std::string, double>::iterator it = this->prices.lower_bound(date);
	if (it == prices.end() || it->first != date) {
		if (it == prices.begin()) {
			return 0; // TODO???
		}
		it--;
	}

	double exchangeRate = it->second;
	return exchangeRate;
}

void BitcoinExchange::calculateValue(const std::string& filename) {
	std::ifstream file(filename.c_str());
	std::string line;

	if (!file.is_open()) {
		std::cout << "Failed to open the file: " << filename << std::endl;
		return;
	}

	// skip first line
	std::getline(file, line);
	while (std::getline(file, line)) {
		std::stringstream ss(line);
		std::string date, rateStr;

		// Split string by date and value
		std::getline(ss, date, '|');
		if (!isValidDate(date)) {
			std::cout << "Error: bad input => " << date << std::endl;
			continue;
		}
		// Check if the value is valid
		std::getline(ss, rateStr);
		switch (isValidValue(rateStr)) {
			case (ERR_NEGATIVE):
				std::cout << "Error: not a positive number" << std::endl;
				break;
			case (ERR_TOO_LARGE):
				std::cout << "Error: too large a number" << std::endl;
				break;
			case (ERR_NAN):
				std::cout << "Error: not a number" << std::endl;
				break;
			default:
				double rate, value;
				std::istringstream iss(rateStr);
				iss >> rate;
				value = calculateExchangeRate(date);
				std::cout << date << " => (" << trim(rateStr) << " * " << value << ") => " << std::fixed << std::setprecision(2) << value * rate << std::endl;
				break;
		}
	}
	file.close();
}

void BitcoinExchange::loadPricesFromFile(const std::string& filename) {
	std::ifstream file(filename.c_str());
	std::string line;

	if (!file.is_open()) {
		std::cout << "Failed to open the file: " << filename << std::endl;
		return;
	}

	// skip first line
	std::getline(file, line);
	while (std::getline(file, line)) {
		std::stringstream ss(line);
		std::string date, rateStr;
		double rate;

		// splitting string into date and exchange rate
		std::getline(ss, date, ',');
		std::getline(ss, rateStr);

		//convert string to double
		std::istringstream iss(rateStr);
		iss >> rate;

		// Add it to map with date as the "key"
		this->prices[date] = rate;
	}
	file.close();
}
