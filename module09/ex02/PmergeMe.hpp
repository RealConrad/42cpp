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


class PmergeMe {
    private:
        std::vector<int> dataVector;
        std::deque<int> dataDeque;
        clock_t startTime;
        clock_t endTime;
        double elapsedTime;

    public:
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();

        /* ---------------------------- Member functions ---------------------------- */
        void fordJohnsonSort();
        void validateInput(int argc, char** argv);
        std::vector<int> getVector() const;


        /* -------------------------------- Templates ------------------------------- */
        template <typename Container>
        void printContainer(const Container& container) const {
            typename Container::const_iterator it = container.begin();
            while (it != container.end()) {
                std::cout << *it << " ";
                ++it;
            }
            std::cout << std::endl;
        }

        template<typename Container>
        void pairAndSort(Container& container) {
            for (std::size_t i = 0; i < container.size() - 1; i += 2) {
                if (container[i] > container[i + 1]) {
                    std::swap(container[i], container[i + 1]);
                }
            }
        }
};

#endif