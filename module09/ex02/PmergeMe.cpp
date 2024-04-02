#include "PmergeMe.hpp"

PmergeMe::PmergeMe(): outlier(0), hasOutlier(false), start(0), end(0), type(UNKNOWN) {}

PmergeMe::PmergeMe(const PmergeMe& other)
	: vectorData(other.vectorData), dequeData(other.dequeData),
	  vectorPair(other.vectorPair), dequePair(other.dequePair),
	  jacobsthalNumbers(other.jacobsthalNumbers),
	  insertionPositions(other.insertionPositions),
	  outlier(other.outlier), hasOutlier(other.hasOutlier),
	  start(other.start), end(other.end), type(other.type) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	if (this != &other) {
		vectorData = other.vectorData;
		dequeData = other.dequeData;
		vectorPair = other.vectorPair;
		dequePair = other.dequePair;
		jacobsthalNumbers = other.jacobsthalNumbers;
		insertionPositions = other.insertionPositions;
		outlier = other.outlier;
		hasOutlier = other.hasOutlier;
		start = other.start;
		end = other.end;
		type = other.type;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

bool PmergeMe::comparePairsByFirst(const std::pair<int, int>& a, const std::pair<int, int>& b) {
	return a.first < b.first;
}

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

void PmergeMe::fordJohnsonSort(int argc, char **argv) {

	this->start = clock();
	this->type = DEQUE;
	validateInput(argc, argv, this->dequeData);
	createAndSortPairs(this->dequeData, this->dequePair);
	mergeSortPairs(this->dequePair);
	splitAndMerge<std::deque<int>, std::deque<std::pair<int, int> > >(this->dequePair);	

	this->start = clock();
	this->type = VECTOR;
	validateInput(argc, argv, this->vectorData);
	createAndSortPairs(this->vectorData, this->vectorPair);
	mergeSortPairs(this->vectorPair);
	splitAndMerge<std::vector<int>, std::vector<std::pair<int, int> > >(this->vectorPair);
}
