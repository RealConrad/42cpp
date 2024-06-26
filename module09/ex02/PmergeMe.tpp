#ifndef PMERGE_ME_TPP
#define PMERGE_ME_TPP

#include "PmergeMe.hpp"

template <typename Container>
void PmergeMe::printContainer(const Container& container) {
	int counter = 0;
	typename Container::const_iterator it = container.begin();
	while (it != container.end()) {
		if (counter == 20) {
			std::cout << " [....] ";
			break ;
		}
		std::cout << *it << " ";
		++it;
		counter++;
	}
	std::cout << std::endl;
}

template <typename Pair>
void PmergeMe::printPairs(const Pair& pair) {
	typename Pair::const_iterator iter;
	for (iter = pair.begin(); iter != pair.end(); ++iter) {
		std::cout << "(" << iter->first << ", " << iter->second << ") ";
	}
	std::cout << std::endl;
	if (this->hasOutlier)
		std::cout << "Outlier: " << this->outlier;
	std::cout << std::endl;
}

template <typename Container>
bool PmergeMe::is_sorted(const Container& container) {
	if (container.empty())
		return true; // An empty container is considered sorted.

	typename Container::const_iterator it = container.begin();
	typename Container::const_iterator next = it;
	++next;

	while (next != container.end()) {
		if (*next < *it) {
			return false;
		}
		++it;
		++next;
	}

	return true; // Container is sorted.
}

template<typename Container>
void PmergeMe::validateInput(int argc, char** argv, Container& container) {
	for (int i = 1; i < argc; i++) {
		std::istringstream iss(argv[i]);
		double num;
		iss >> num;
		if (iss.fail() || num < std::numeric_limits<int>::min() || num > std::numeric_limits<int>::max()) {
			throw std::invalid_argument("Invalid input");
		}
		container.push_back(static_cast<int>(num));
	}
	if (container.size() == 1 || is_sorted(container)) {
		throw std::invalid_argument("Input is already sorted. Sorting not required.");
	}
}

template<typename Container>
void PmergeMe::printResult(const Container& container) {
	double elapsedTime = 0;

	elapsedTime = (static_cast<double>(end - start) / CLOCKS_PER_SEC) * 1000;
	
	if (this->type == VECTOR) {
		std::cout << "===== VECTOR =====" << std::endl;
		std::cout << "Before: ";
		printContainer(this->vectorData);
		std::cout << "After: ";
		printContainer(container);
		std::cout << "Time to process a range of " << container.size() << " elements with std::vector: " << elapsedTime << " ms" << std::endl;
	} else if (this->type == DEQUE) {
		std::cout << "===== DEQUE =====" << std::endl;
		std::cout << "Before: ";
		printContainer(this->dequeData);
		std::cout << "After: ";
		printContainer(container);
		std::cout << "Time to process a range of " << container.size() << " elements with std::deque: " << elapsedTime << " ms" << std::endl;
	}
}

template <typename Container, typename Pair>
void PmergeMe::createAndSortPairs(Container& container, Pair& pair) {
	this->hasOutlier = false;

	for (size_t i = 0; i + 1 < container.size(); i += 2) {
		int first = container[i];
		int second = container[i + 1];
		if (first < second) {
			pair.push_back(std::make_pair(second, first));
		} else {
			pair.push_back(std::make_pair(first, second));
		}
	}
	if (container.size() % 2 != 0) {
		this->hasOutlier = true;
		this->outlier = container[container.size() - 1];
	}
}

template<typename Pair>
void PmergeMe::mergeSortPairs(Pair& pairs) {
	if (pairs.size() <= 1)
		return;

	// Divide up to 2 halves
	size_t mid = pairs.size() / 2;
	Pair leftHalf(pairs.begin(), pairs.begin() + mid);
	Pair rightHalf(pairs.begin() + mid, pairs.end());

	// recursively sort
	mergeSortPairs(leftHalf);
	mergeSortPairs(rightHalf);

	// merge once all sorted
	std::merge(leftHalf.begin(), leftHalf.end(), rightHalf.begin(), rightHalf.end(), pairs.begin());
}

template<typename Container>
void PmergeMe::insertToMainChain(Container& mainChain, Container& pendChain) {
	int offset = 0;
	int prev_jcb_number = -1;

	for (size_t j = 2; j < jacobsthalNumbers.size(); j++) {
		int jcb_number = jacobsthalNumbers[j];

		if (jcb_number > static_cast<int>(pendChain.size() - 1)) {
	 		jcb_number = pendChain.size() - 1;
		}
		for (int i = jcb_number; i > prev_jcb_number; --i) {
			int elementToInsert = pendChain[i];
			typename Container::iterator insertPos = std::lower_bound(
				mainChain.begin(), mainChain.begin() + i + offset, elementToInsert);
			mainChain.insert(insertPos, elementToInsert);
			offset++;
		}
		prev_jcb_number = jcb_number;
	}
}

template <typename Container, typename PairContainer>
void PmergeMe::splitAndMerge(const PairContainer& pairs) {
	Container mainChain;
	Container pendChain;
	for (typename PairContainer::const_iterator it = pairs.begin(); it != pairs.end(); ++it) {
		mainChain.push_back(it->first);
		pendChain.push_back(it->second);
	}
	if (this->hasOutlier) {
		pendChain.push_back(this->outlier);
	}
	insertToMainChain(mainChain, pendChain);
	this->end = clock();
	printResult(mainChain);
}

#endif