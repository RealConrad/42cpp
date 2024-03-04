#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain {
    private:
        std::string ideas[100];
    public:
        Brain();
        ~Brain();
        Brain(const Brain& copy); // copy constructor
        Brain& operator=(const Brain& copy); // copy assignment operator
};

#endif