#ifndef SED_HPP
#define SED_HPP

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

class Sed {
	private:
		std::string inputFileName;
		std::string outputFileName;
		std::string s1;
		std::string s2;
	
	public:
		Sed(std::string fileName, std::string s1, std::string s2);
		void replace(void);

};

#endif