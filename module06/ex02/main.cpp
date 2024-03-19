#include "Base.hpp"
#include "Type.hpp"
#include "Derived.hpp"

int main() {
	// Seed the RNG (give it random starting point), this ensures its different each time function gets called
	std::srand(std::time(NULL));

	Base* a = generate();
	Base* b = generate();
	Base* c = generate();
	Base& d = *c;
	Base* e = NULL;

	identify(a);
	identify(b);
	identify(c);
	identify(d);
	identify(e);

	delete a;
	delete b;
	delete c;

	return 0;
}