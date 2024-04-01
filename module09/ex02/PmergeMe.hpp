#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <string>
#include <stdexcept>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <limits>
#include <algorithm> 

enum ContainerType {
	VECTOR,
	DEQUE
};
class PmergeMe {
	private:
		std::vector<int> vectorData;
		std::deque<int> dequeData;
		std::vector<std::pair<int, int> > vectorPair;
    	std::deque<std::pair<int, int> > dequePair;
		std::vector<int> jacobsthalNumbers;
		std::vector<size_t> insertionPositions;
		int outlier;
		bool hasOutlier;
		clock_t start;
		clock_t end;
		ContainerType type;

		static bool comparePairsByFirst(const std::pair<int, int>& a, const std::pair<int, int>& b);
		void initJacobsthal(size_t numElements);
		void generateInsertionPositions(size_t numElements);

		/* -------------------------------- Templates ------------------------------- */
		template <typename Container, typename Pair>
		void createAndSortPairs(Container& container, Pair& pair);
		
		template <typename Container, typename PairContainer>
		void splitAndMerge(const PairContainer& pairs);
		
		template <typename Container>
		void insertToMainChain(Container& mainChain, Container& pendChain);
		template <typename Container>
		void printResult(const Container& container);
		
		// Debug
		template <typename Pair>
		void printPairs(const Pair& pair);
		template <typename Container>
		void printContainer(const Container& container);
	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

		void validateInput(int argc, char** argv);
		void fordJohnsonSort();
};

#include "PmergeMe.tpp"

#endif