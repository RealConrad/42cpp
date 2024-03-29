#include "Type.hpp"
#include "Derived.hpp"
#include "Base.hpp"

Base* generate() {
	int randomValue = std::rand() % 3;

	switch(randomValue) {
		case 0:
			return new A;
		case 1:
			return new B;
		case 2:
			return new C;
		default:
			return NULL;
	}
	return NULL;
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "Type: A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Type: B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Type: C" << std::endl;
	else
		std::cout << "Type: Unknown" << std::endl;
}

void identify(Base& p) {
	try {
		Base& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "Type: A" << std::endl;
		return;
	} catch(const std::exception& e) {
		(void)e;
	}

	try {
		Base& b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "Type: B" << std::endl;
		return;
	} catch (std::exception& e) {
		(void)e;
	}

	try {
		Base& c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "Type: C" << std::endl;
		return;
	} catch (std::exception& e) {
		(void)e;
	}
	std::cout << "Type: Unknown" << std::endl;
}
