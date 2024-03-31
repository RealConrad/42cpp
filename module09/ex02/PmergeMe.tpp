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

template<typename Container>
void PmergeMe::insertUsingSequence(Container& firstChain, Container& secondChain) {
    initJacobsthal(secondChain.size());

    // Offset keeps track of how much the original positions have been shifted by insertions.
    int offset = 0;
    // Keep track of the last Jacobsthal number used to ensure we do not duplicate insertions.
    int prev_jcb_number = -1;

    for (size_t j = 0; j < jacobsthalNumbers.size(); ++j) {
        // Get the current Jacobsthal number, used as index
        int jcb_number = jacobsthalNumbers[j];

        // If the Jacobsthal number is larger than the size of secondChain, or if it's a repeat, skip it.
        if (jcb_number >= static_cast<int>(secondChain.size()) || jcb_number == prev_jcb_number) {
            continue;
        }

        // Iterate from the current Jacobsthal number down to the last used one (or zero).
        for (int i = jcb_number; i > prev_jcb_number; --i) {
            // Get the element to insert from secondChain.
            int elementToInsert = secondChain[i];

            // Find the correct position in the firstChain where this element should be inserted.
            // Adjust the search space within firstChain to account for the shifted elements due to prev insertions.
            typename Container::iterator insertPos = std::lower_bound(firstChain.begin(), firstChain.begin() + i + offset, elementToInsert);

            // Insert the element from secondChain into the firstChain at the found position.
            firstChain.insert(insertPos, elementToInsert);

            // Increase the offset for each insertion made.
            ++offset;
        }
        // Update prev_jcb_number to the current Jacobsthal number after processing it.
        prev_jcb_number = jcb_number;
    }
    if (this->hasOutlier) {
        typename Container::iterator insertPos = std::upper_bound(firstChain.begin(), firstChain.end(), this->outlier);
        firstChain.insert(insertPos, this->outlier);
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