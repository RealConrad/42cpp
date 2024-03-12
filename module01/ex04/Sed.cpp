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

static std::string replaceAll(std::string str, const std::string& s1, const std::string& s2) {
	// nothing to replace so just return
	if (s1.empty()) 
		return str;

	std::string result;
	size_t startPosition = 0;
	size_t foundPosition = str.find(s1, startPosition);

	// If find() does not find s1 in the string, it returns `std::string::npos` a special constant (no match found)
	// then we break out
	while (foundPosition != std::string::npos) {
		// Append the part of the string before the found substring
		result += str.substr(startPosition, foundPosition - startPosition);
		result += s2;
		// update pointer
		startPosition = foundPosition + s1.length();
		// Look for the s1;
		foundPosition = str.find(s1, startPosition);
	}
	// Append any remaining parts of the original string after the last replacement
	result += str.substr(startPosition);
	return result;
}
