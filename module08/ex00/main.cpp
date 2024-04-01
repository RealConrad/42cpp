#include "easyfind.hpp"
#include <vector>
#include <list>

int main() {
	std::cout << "==========TEST 1 (vec)=========" << std::endl;
	try {
		std::vector<int> myVec;
		myVec.push_back(10);
		myVec.push_back(20);
		myVec.push_back(30);
		std::cout << easyfind(myVec, 30) << std::endl;
		std::cout << easyfind(myVec, 0) << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "==========TEST 2 (list)=========" << std::endl;
	try {
		std::list<int> myList;
		myList.push_back(10);
		myList.push_back(20);
		myList.push_back(30);
		std::cout << easyfind(myList, 10) << std::endl;
		std::cout << easyfind(myList, 0) << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
