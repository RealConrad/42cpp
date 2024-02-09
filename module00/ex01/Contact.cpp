#include "Contact.hpp"

std::string getValidInput(const std::string& prompt);

void Contact::inputContactDetails(void) {
	firstName = getValidInput("Enter firstname: ");
	lastName = getValidInput("Enter lastname: ");
	nickname = getValidInput("Enter nickname: ");
	darkestSecret = getValidInput("Enter darkest secret: ");
	phoneNumber = getValidInput("Enter phone number: ");
}

std::string getValidInput(const std::string& prompt) {
	std::string input;

	while (input.empty()) {
		std::cout << prompt;
		std::getline(std::cin, input);
		if (input.empty()) {
			std::cout << "Input cannot be empty. Try again stupid." << std::endl;
		}
	}
	return (input);
}

void Contact::displayContact(void) {
	std::cout << "First name: " << firstName << std::endl;
	std::cout << "Last name: " << lastName << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Darkest secret: " << darkestSecret << std::endl;
	std::cout << "Phone Number: " << phoneNumber << std::endl;
	std::cout << "Index: " << index << std::endl;
}

/* ---------------------------- Setter functions ---------------------------- */
void Contact::setIndex(int idx) {
	index = idx;
}

/* ---------------------------- Getter functions ---------------------------- */

std::string Contact::getIndex(void) {
	return (std::to_string(index));
}

std::string Contact::getFirstName(void) {
	return (firstName);
}

std::string Contact::getLastName(void) {
	return (lastName);
}

std::string Contact::getNickname(void) {
	return (nickname);
}
