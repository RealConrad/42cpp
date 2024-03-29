#ifndef PMERGE_ME_TPP
#define PMERGE_ME_TPP

#include "PmergeMe.hpp"

template <typename Container>
void printContainer(const Container& container) {
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
            pair.push_back(std::make_pair(first, second));
        }
        else {
            this->outlier = *iter;
			this->hasOutlier = true;
			iter++;
        }
    }
}

#endif