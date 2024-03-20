#include "Array.hpp"

template<typename T>
void printArray(Array<T> arr) {
	std::cout << "Array values:" << std::endl;
	for (int i = 0; i < arr.getSize(); i++)
		std::cout << i << ": " << arr[i] << std::endl;
}

int main() {
	std::cout << "==========TEST 1==========" << std::endl;
	Array<int> myIntArr(3);
	std::cout << "Int array size: " << myIntArr.getSize() << std::endl;
	printArray(myIntArr);
	
	for (int i = 0; i < myIntArr.getSize(); i++)
		myIntArr[i] = i + 1;
	printArray(myIntArr);

	std::cout << "\n==========TEST 2==========" << std::endl;
	Array<double> myDoubleArr(3);
	std::cout << "Double array size: " << myIntArr.getSize() << std::endl;

	for (int i = 0; i < myDoubleArr.getSize(); i++)
		myDoubleArr[i] = i + 0.5;
	printArray(myDoubleArr);
	
	try {
		std::cout << "Trying to acces out of bounds...." << std::endl;
		std::cout << myDoubleArr[10] << std::endl;
		std::cout << "Success!" << std::endl;
	} catch (const std::exception& e) {
		std::cout << "EXCEPTION: " << e.what() << std::endl;
	}
	std::cout << "\n==========TEST 3==========" << std::endl;
	Array<std::string> myStringArr(3);
	for (int i = 0; i < myStringArr.getSize(); i++) {
		myStringArr[i] = "String";
	}
	printArray(myStringArr);

	Array<int> test;
	Array<int> test2(0);
	return 0;
}
