#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other): dataVector(other.dataVector), dataDeque(other.dataDeque) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
        this->dataDeque = other.dataDeque;
        this->dataVector = other.dataVector;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

std::vector<int> PmergeMe::getVector() const {
    return this->dataVector;
}

void PmergeMe::validateInput(int argc, char** argv) {
   for (int i = 1; i < argc; i++) {
        std::istringstream iss(argv[i]);
        double num;
        iss >> num;
        if (iss.fail() || num < std::numeric_limits<int>::min() || num > std::numeric_limits<int>::max()) {
            throw std::invalid_argument("Invalid input");
        }
        this->dataVector.push_back(static_cast<int>(num));
        this->dataDeque.push_back(static_cast<int>(num));
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
