#include "PmergeMe.hpp"


void MarkusCode() {
	int threshold = 50 / 2 + 1;
	std::vector<int> tmp_jacob;
	tmp_jacob.push_back(2);
	for (int i = 4; tmp_jacob.back() < threshold; ++i) {
		tmp_jacob.push_back((((1 << i) - (i % 2 == 0 ? 1 : -1)) / 3) - 1);
	}
	std::cout <<"MARKUS CODE: " << std::endl;
	std::vector<int>::const_iterator it = tmp_jacob.begin();
	while (it != tmp_jacob.end()) {
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cout << "Error: Invalid parameters" << std::endl;
        std::cout << "Usage: ./PmergeMe <numbers>" << std::endl;
        return 1;
    }

    try {
        PmergeMe me;
        me.validateInput(argc, argv);
		me.fordJohnsonSort();
		// MarkusCode();
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}
