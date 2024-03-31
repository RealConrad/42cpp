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
    initJacobsthal(secondChain.size() + 1);
    typename Container::iterator insertPos = firstChain.begin();
    for (size_t i = 0; i < secondChain.size(); i++) {
        // The index for the Jacobsthal sequence, which determines the order of insertion
        size_t jacobIndex = jacobsthalNumbers[i];

        // Advance the insertPos iterator by jacobIndex positions
        std::advance(insertPos, jacobIndex);

        // If we've reached the end of the firstChain, reset insertPos to the beginning
        if (insertPos == firstChain.end()) {
            insertPos = firstChain.begin();
        }

        // Find the position in the firstChain where this element should be inserted
        insertPos = std::upper_bound(firstChain.begin(), insertPos, secondChain[i]);

        // Insert the element from the secondChain at the correct position in the firstChain
        firstChain.insert(insertPos, secondChain[i]);

        // Reset insertPos to the beginning of the firstChain for the next iteration
        insertPos = firstChain.begin();
    }
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