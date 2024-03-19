#include <iostream>
#include "iter.hpp"

struct Point {
	int x;
	int y;
	int z;
};

void printInt(int element) {
	std::cout << element << " ";
}
void increaseAndPrint(int element) {
	std::cout << ++element << " ";
}

void printString(const std::string& str) {
	std::cout << str;
}

void printPoints(Point p) {
	std::cout << "(x: " << p.x << ", y: " << p.y << ", z: " << p.z << ")" << std::endl;;
}

int main() {
	std::cout << "==========TEST 1==========" << std::endl;
	int arr[6] = {1, 2, 3, 4, 5, 6};
	iter(arr, 6, printInt);
	std::cout << std::endl;
	iter(arr, 6, increaseAndPrint);

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "==========TEST 2==========" << std::endl;
	std::string strs[] = {"Hello ", "World", ", this ", "is ", "my ", "string ", "test"};
	iter(strs, 7, printString);

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "==========TEST 3==========" << std::endl;
	Point points[] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	iter(points, 3, printPoints);
}
