#include "MutantStack.hpp"

void testWithStack();
void testWithVector();
void testWithList();

int main() {
	testWithStack();
	testWithVector();
	testWithList();
	return 0;
}

void testWithStack() {
	std::cout << "==========TESTING WITH CONTAINER DEQUE==========" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "Removing top element: " << mstack.top() << std::endl;
	std::cout << "Stack Size Before pop():" << mstack.size() << std::endl;
	mstack.pop();
	std::cout << "Stack Size After pop():" << mstack.size() << std::endl;
	std::cout << "New top element: " << mstack.top() << std::endl;
	std::cout << "Adding more elements...." << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(7311);
	mstack.push(180);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	std::cout << "\nIterating through the entire stack: " << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	// explicity convert MutantStack to std::stack (does not throw error)
	std::stack<int> s(mstack); // works, because mstack is derived from std::stack
}

void testWithVector() {
	std::cout << "==========TESTING WITH CONTAINER VECTOR==========" << std::endl;
	MutantStack< int, std::vector<int> > mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "Removing top element: " << mstack.top() << std::endl;
	std::cout << "Stack Size Before pop():" << mstack.size() << std::endl;
	mstack.pop();
	std::cout << "Stack Size After pop():" << mstack.size() << std::endl;
	std::cout << "New top element: " << mstack.top() << std::endl;
	std::cout << "Adding more elements...." << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(7311);
	mstack.push(180);
	mstack.push(0);
	MutantStack< int, std::vector<int> >::iterator it = mstack.begin();
	MutantStack< int, std::vector<int> >::iterator ite = mstack.end();
	++it;
	--it;
	std::cout << "\nIterating through the entire stack: " << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack< int, std::vector<int> > s(mstack);
}

void testWithList() {
	std::cout << "==========TESTING WITH CONTAINER LIST==========" << std::endl;
	MutantStack< int, std::list<int> > mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "Removing top element: " << mstack.top() << std::endl;
	std::cout << "Stack Size Before pop():" << mstack.size() << std::endl;
	mstack.pop();
	std::cout << "Stack Size After pop():" << mstack.size() << std::endl;
	std::cout << "New top element: " << mstack.top() << std::endl;
	std::cout << "Adding more elements...." << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(7311);
	mstack.push(180);
	mstack.push(0);
	MutantStack< int, std::list<int> >::iterator it = mstack.begin();
	MutantStack< int, std::list<int> >::iterator ite = mstack.end();
	++it;
	--it;
	std::cout << "\nIterating through the entire stack: " << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack< int, std::list<int> > s(mstack);
}
