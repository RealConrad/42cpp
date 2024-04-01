#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other): vectorData(other.vectorData), dequeData(other.dequeData) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
        this->vectorData = other.vectorData;
        this->dequeData = other.dequeData;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::validateInput(int argc, char** argv) {
   for (int i = 1; i < argc; i++) {
        std::istringstream iss(argv[i]);
        double num;
        iss >> num;
        if (iss.fail() || num < std::numeric_limits<int>::min() || num > std::numeric_limits<int>::max()) {
            throw std::invalid_argument("Invalid input");
        }
        this->vectorData.push_back(static_cast<int>(num));
        this->dequeData.push_back(static_cast<int>(num));
    }
}

bool PmergeMe::comparePairsByFirst(const std::pair<int, int>& a, const std::pair<int, int>& b) {
    return a.first < b.first;
}

/// @brief // J(n)=J(n−1)+2⋅J(n−2) with initial values of // J(0)=0 and J(1)=1
/// @param numElements 
void PmergeMe::initJacobsthal(size_t numElements) {
    this->jacobsthalNumbers.clear();
    this->jacobsthalNumbers.push_back(0); // J(0) = 0
    if (numElements > 1) {
        this->jacobsthalNumbers.push_back(1); // J(1) = 1
    }
    for (size_t i = 2; i < numElements; i++) {
        // J(n) = J(n−1)+2⋅J(n−2)
        int nextNumber = this->jacobsthalNumbers[i - 1] + 2 * this->jacobsthalNumbers[i - 2];
		if (static_cast<size_t>(nextNumber) > numElements)
			break ;
        this->jacobsthalNumbers.push_back(nextNumber);
    }
}

void PmergeMe::fordJohnsonSort() {
	// vector
	this->type = VECTOR;
	this->start = clock();
	createAndSortPairs(this->vectorData, this->vectorPair);
    splitAndMerge<std::vector<int>, std::vector<std::pair<int, int> > >(this->vectorPair);	

	// deque
	// this->type = DEQUE;
	// this->start = clock();
	// createAndSortPairs(this->dequeData, this->dequePair);
    // splitAndMerge<std::deque<int>, std::deque<std::pair<int, int> > >(this->dequePair);	
}
