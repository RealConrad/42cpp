#ifndef PMERGE_ME_TPP
#define PMERGE_ME_TPP

#include "PmergeMe.hpp"

template <typename Container>
void PmergeMe::printContainer(const Container& container) {
	int counter = 0;
	typename Container::const_iterator it = container.begin();
	while (it != container.end()) {
		if (counter == 100) {
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

template <typename Container, typename Pair>
void PmergeMe::createAndSortPairs(Container& container, Pair& pair) {
	this->hasOutlier = false;
	typename Container::iterator iter = container.begin();
	while (iter != container.end()) {
		// Check we have at least two elements to form a pair
		if (std::distance(iter, container.end()) >= 2) {
			int first = *iter;
			iter++;
			int second = *iter;
			iter++;

			// Ensure the larger number is always first
			if (first < second) {
				std::swap(first, second);
			}
			// Add the pair to the container
			pair.push_back(std::make_pair(first, second));
		}
		else {
			this->outlier = *iter;
			this->hasOutlier = true;
			iter++;
		}
	}
	// Sort the pairs by the first element
	std::sort(pair.begin(), pair.end(), comparePairsByFirst);
}


template<typename Container>
void PmergeMe::insertToMainChain(Container& mainChain, Container& pendChain) {
	// Ensure Jacobsthal sequence is large enough to include the potential outlier.
	initJacobsthal(pendChain.size());

	// std::cout << "Jacobsthal Numbers: " << std::endl;
	// printContainer(this->jacobsthalNumbers);

	int offset = 0;
	int prev_jcb_number = -1;

	for (size_t j = 0; j < jacobsthalNumbers.size(); j++) {
		int jcb_number = jacobsthalNumbers[j] + 1;
		std::cout << "JSCB NUM: " << jcb_number << std::endl;;

		if (jcb_number > static_cast<int>(pendChain.size())) {
			std::cout << "Breaking\tJCB_NUM\t" << jcb_number << "\t\tChain Size:\t" << pendChain.size() << std::endl;
			break;
		}

		 for (int i = jcb_number; i > prev_jcb_number; i--) {
			int elementToInsert = pendChain[i];
			typename Container::iterator insertPos = std::lower_bound(
				mainChain.begin(), mainChain.begin() + i + offset, elementToInsert);
			// std::cout << "Inseting... " << elementToInsert << " at position " << insertPos - mainChain.begin() << std::endl;
			mainChain.insert(insertPos, elementToInsert);
			offset++;
		}
		prev_jcb_number = jcb_number;
	}
	for (size_t i = prev_jcb_number + 1; i < pendChain.size(); i++) {
		int elementToInsert = pendChain[i];
		typename Container::iterator insertPos = std::lower_bound(
			mainChain.begin(), mainChain.end(), elementToInsert);
		mainChain.insert(insertPos, elementToInsert);
	}
}

// template<typename Container>
// void PmergeMe::insertToMainChain(Container& mainChain, Container& pendChain) {
//     for (size_t i = 0; i < pendChain.size(); i++) {
//         int elementToInsert = pendChain[i];
//         size_t low = 0;
// 		size_t high = mainChain.size(); // Set high to the current size of mainChain

//         // Perform a manual binary search within mainChain
//         while (low < high) {
//             size_t mid = low + (high - low) / 2;
//             if (mainChain[mid] < elementToInsert) {
//                 low = mid + 1; // Search in the right half
//             } else {
//                 high = mid; // Search in the left half
//             }
//         }
//         // At this point, low is the index where elementToInsert should be placed
//         typename Container::iterator insertPos = mainChain.begin() + low;
//         mainChain.insert(insertPos, elementToInsert);
//     }
// }

template<typename Container>
void PmergeMe::printResult(const Container& container) {
	double elapsedTime = 0;

	elapsedTime = static_cast<double>(end - start) / CLOCKS_PER_SEC;
	
	if (this->type == VECTOR) {
		std::cout << "===== VECTOR =====" << std::endl;
		std::cout << "Before: ";
		printContainer(this->vectorData);
		std::cout << "After: ";
		printContainer(container);
		std::cout << "Time to process a range of " << container.size() << " elements with std::vector: " << elapsedTime << " seconds" << std::endl;
	} else if (this->type == DEQUE) {
		std::cout << "===== DEQUE =====" << std::endl;
		std::cout << "Before: ";
		printContainer(this->dequeData);
		std::cout << "After: ";
		printContainer(container);
		std::cout << "Time to process a range of " << container.size() << " elements with std::vector: " << elapsedTime << " seconds" << std::endl;
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
	std::cout << "Pairs: " << std::endl;
	printPairs(pairs);
	std::cout << "First chain: ";
	printContainer(mainChain);
	std::cout << "Second chain: ";
	printContainer(pendChain);

	insertToMainChain(mainChain, pendChain);

	std::cout << "Final Result: ";
	printContainer(mainChain);
	this->end = clock();
	// printResult(mainChain);
}

#endif