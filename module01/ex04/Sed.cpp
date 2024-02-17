#include "Sed.hpp"

static std::string replaceAll(std::string line, const std::string &s1, const std::string &s2);

Sed::Sed(std::string fileName, std::string s1, std::string s2) {
	this->inputFileName = fileName;
	this->s1 = s1;
	this->s2 = s2;
	
	std::string temp = fileName.substr(0, fileName.find(".", 0));
 	temp += ".replace";
	this->outputFileName = temp;
}

void Sed::replace(void) {
	// throws warning on linux if type is not `const char *`. Code still works without it on Mac.
	std::ifstream inputFile(this->inputFileName.c_str());
	std::ofstream outputFile(this->outputFileName.c_str());
	std::string line;

	if (!inputFile.is_open()) {
		std::cerr << "Error: Could not open input file: " << this->inputFileName << std::endl;
		return ;
	}
	if (!outputFile.is_open()) {
		std::cerr << "Error: Could not create output file: " << this->outputFileName << std::endl;
		return ;
	}

	while (std::getline(inputFile, line)) {
		std::string newLine = replaceAll(line, this->s1, this->s2);
		outputFile << newLine << std::endl;
	}
}

static std::string replaceAll(std::string line, const std::string &s1, const std::string &s2) {
	if (s1.empty())
		return (line);
	size_t startPosition = 0;
	while (true) {
		// If find() does not find s1 in the string, it returns `std::string::npos` a special constant (no match found)
		if ((startPosition = line.find(s1, startPosition)) == std::string::npos)
			break ;
		line.replace(startPosition, s1.length(), s2);
		startPosition += s2.length();
	}
	return (line);
}
