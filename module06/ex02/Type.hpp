#ifndef TYPE_HPP
#define TYPE

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <exception>
#include "Base.hpp"

Base* generate();
void identify(Base* p);
void identify(Base& p);

#endif