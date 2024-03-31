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
    // Ensure Jacobsthal sequence is large enough to include the potential outlier.
    initJacobsthal(secondChain.size() + 1);

    std::cout << "Jacobsthal Numbers: " << std::endl;
    printContainer(this->jacobsthalNumbers);

    int offset = 0;
    int prev_jcb_number = -1;

    for (size_t j = 0; j < jacobsthalNumbers.size(); j++) {
        int jcb_number = jacobsthalNumbers[j];

        if (jcb_number > static_cast<int>(secondChain.size())) {
            std::cout << "Breaking\tJCB_NUM\t" << jcb_number << "\t\tChain Size:\t" << secondChain.size() << std::endl;
            continue;
        }

         for (int i = jcb_number; i > prev_jcb_number; i--) {
            int elementToInsert = secondChain[i];
            typename Container::iterator insertPos = std::lower_bound(
                firstChain.begin(), firstChain.begin() + i + offset, elementToInsert);
            std::cout << "Inseting... " << elementToInsert << " at position " << insertPos - firstChain.begin() << std::endl;
            firstChain.insert(insertPos, elementToInsert);
            offset++;
        }
        prev_jcb_number = jcb_number;
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

    std::cout << "First chain: ";
    printContainer(firstChain);

    std::cout << "Second chain: ";
    printContainer(secondChain);
    insertUsingSequence(firstChain, secondChain);

    std::cout << "Final Result: ";
    printContainer(firstChain);
}

#endif