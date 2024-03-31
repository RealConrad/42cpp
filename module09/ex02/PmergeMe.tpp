#ifndef PMERGE_ME_TPP
#define PMERGE_ME_TPP

#include "PmergeMe.hpp"

template <typename Container>
void PmergeMe::printContainer(const Container& container) {
	typename Container::const_iterator it = container.begin();
	while (it != container.end()) {
		std::cout << *it << " ";
		++it;
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

template <typename Container>
void PmergeMe::insertUsingSequence(Container& firstChain, Container& secondChain) {
    (void)firstChain;
    (void)secondChain;
    // initJacobsthal(secondChain.size() + 1);
    // for (size_t i = 0; i < secondChain.size(); i++) {
    //     // The index for the Jacobsthal sequence, which determines the order of insertion
    //     size_t jacobIndex = jacobsthalNumbers[i];
        
    //     // If the Jacobsthal index is larger than the current size of the secondChain,
    //     // it means we have no elements left in secondChain
    //     if (jacobIndex >= secondChain.size()) {
    //         break;
    //     }

    //     // Retrieve the element from the secondChain based on Jacobsthal order
    //     int elementToInsert = secondChain[jacobIndex];

    //     // Find the position in the firstChain where this element should be inserted
    //     typename Container::iterator insertPos = std::upper_bound(firstChain.begin(), firstChain.end(), elementToInsert);

    //     // Insert the element at the correct sorted position in the firstChain
    //     firstChain.insert(insertPos, elementToInsert);
    // }
}

template <typename Container, typename PairContainer>
void PmergeMe::splitAndMerge(const PairContainer& pairs) {
    Container firstChain;
    Container secondChain;
    for (typename PairContainer::const_iterator it = pairs.begin(); it != pairs.end(); ++it) {
        firstChain.push_back(it->first);
        secondChain.push_back(it->second);
    }
    if (this->hasOutlier) {
        secondChain.push_back(this->outlier);
    }
    insertUsingSequence(firstChain, secondChain);
    printContainer(firstChain);
}

#endif