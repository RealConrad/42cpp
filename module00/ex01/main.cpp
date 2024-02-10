#include "Contact.hpp"
#include "Phonebook.hpp"

int main()
{
	Phonebook phonebook;
	std::string userInput;

	phonebook.startMessage();
	while (true)
	{
		std::cout << "Command: ";
		if (!std::getline(std::cin, userInput))
			break ;
		if (userInput.compare("SEARCH") == 0) {
			phonebook.search();
		}
		else if (userInput.compare("ADD") == 0) {
			Contact newContact;
			newContact.inputContactDetails();
			phonebook.addContact(newContact);
		}
		else if (userInput.compare("EXIT") == 0)
			break ;
		else
			std::cout << "Invalid command, try again stupid." << std::endl;
	}
	return (0);
}
