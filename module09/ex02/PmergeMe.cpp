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

/*
function FordJohnsonSort(list) {
    if list.size <= 1:
        return list

    # Step 1: Initial Pairing and Sorting
    pairedList = pairAndSort(list)

    # Step 2: Recursive Merge-Sort with Insertion Preparation
    sortedList = recursiveMergeSort(pairedList)

    # Step 3: Insertion of Remaining Elements
    for each unpaired element in list:
        position = optimizedBinarySearch(sortedList, element)
        insert(sortedList, element, position)

    return sortedList
}
*/

void PmergeMe::fordJohnsonSort() {
	// start sorting vector first
	createAndSortPairs(this->vectorData, this->vectorPair);
	printPairs(this->vectorPair);
	





	// start sorting deque
}
