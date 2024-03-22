#include "Span.hpp"

Span::Span(): maxCapacity(0) {
	this->values.reserve(0);
}

Span::Span(int n): maxCapacity(n) {
	this->values.reserve(n);
}

Span::Span(const Span& other) {
	*this = other;
}

Span& Span::operator=(const Span& other) {
	if (this != &other) {
		this->values = other.values;
		this->maxCapacity = other.maxCapacity;
	}
	return *this;
}

Span::~Span() {}

void Span::addMultiple(int amount) {
	int startIndex = this->values.empty() ? 0 : this->values.back() + 1;
	for (int i = 0; i < amount; i++) {
		if (this->values.size() == this->maxCapacity)
			throw StorageFullException(); 
		this->values.push_back(startIndex + i + 1);
	}
}

void Span::display() {
	if (this->values.size() == 0)
		throw NothingToDisplayException();
	std::cout << "Stored values: " << std::endl;
	for (size_t i = 0; i < this->values.size(); i++) {
		std::cout << this->values[i] << " ";
	}
	std::cout << std::endl;
}

void Span::addNumber(int num) {
	if (this->values.size() == this->maxCapacity)
		throw StorageFullException();
	this->values.push_back(num);
};

int Span::shortestSpan() {
	if (this->values.size() < 2)
		throw InvalidSpanException();

	// sort vector ascending
	std::sort(this->values.begin(), this->values.end());
	// init shortestspan with first value
	int shortestSpan = this->values[1] - this->values[0];
	// skip first index as we did that above ^^
	for (size_t i = 1; i < this->values.size(); i++) {
		if (this->values[i + 1]) {
			int currentSpan = this->values[i + 1] - this->values[i];
			if (currentSpan < shortestSpan)
				shortestSpan = currentSpan;
		}
	}
	return shortestSpan;
}

int Span::longestSpan() {
	if (this->values.size() < 2)
		throw InvalidSpanException();
	std::vector<int>::iterator maxI = std::max_element(this->values.begin(), this->values.end());
	std::vector<int>::iterator minI = std::min_element(this->values.begin(), this->values.end());
	return *maxI - *minI;
}
