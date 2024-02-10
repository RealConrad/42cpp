#include "Phonebook.hpp"

std::string formatCell(const std::string& text);
void printRow(const std::string& col1, const std::string& col2, const std::string& col3, const std::string& col4);

/**
 * @brief Adds a contact to the array stored in the Phonebook class. If the max amount of contacts
 * are reached, start replacing the oldest one in the array.
 * @param contact The contact to add. 
 */
void Phonebook::addContact(const Contact& contact) {
	if (currentSize < 8) {
		contacts[currentSize] = contact;
		contacts[currentSize].setIndex(currentSize);
		currentSize++;
	} else {
		// The phonebook is full, start replacing contacts from the oldest one
		contacts[startIndex] = contact;
		contacts[startIndex].setIndex(startIndex);
		startIndex = (startIndex + 1) % 8;
	}

	std::cout << "Contact added." << std::endl;
	if (currentSize == 8) {
		std::cout << "Phonebook is full. The oldest contact will be replaced from now on." << std::endl;
	}
	std::cout << std::endl;
}

/* -------------------------------- Searching ------------------------------- */

/**
 * @brief Searchs for a contact. Prompts the user if they want to search all the contacts or
 * a specific contact by index.  
 */
void Phonebook::search(void) {
	std::string userInput;
	Contact contact;

	std::cout << "Type \"ALL\" to view all contacts or an index number: ";
	std::getline(std::cin, userInput);
	if (userInput.compare("ALL") == 0) {
		printRow("Index", "First Name", "Last Name", "Nickname");
		displayContacts();
	}
	else if (isValidIndex(userInput, contact)) {
		contact.displayContact();
	}
	else
		std::cout << "Invalid input or index. Try again." << std::endl;
}

/**
 * @brief Displays all the stored conatcts formatted.
 */
void Phonebook::displayContacts(void) {
	if (currentSize > 0)
	{
		for (int i = 0; i < currentSize; i++) {
			printRow(contacts[i].getIndex(),
				contacts[i].getFirstName(),
				contacts[i].getLastName(),
				contacts[i].getNickname());
		}
	}
	else
		std::cout << "No contacts have been added yet!" << std::endl;
}

/**
 * @brief Checks if the given index is valid or not.
 * @param idx The index to check for.
 * @param contact A pointer to a contact variable. If the index exists,
 * assign the contact to the conact at the index
 * @return True if the index exists otherwise false. 
 */
bool Phonebook::isValidIndex(const std::string& idx, Contact& contact)
{
	int index = std::atoi(idx.c_str());
	
	for (int i = 0; i < currentSize; i++) {
		if (std::atoi(contacts[i].getIndex().c_str()) == index)
		{
			contact = contacts[i];
			return (true);
		}
	}
	return (false);
}

/* -------------------------------- Printing -------------------------------- */


/**
 * @brief Prints a given row, formatted correctly.
 * @param col1 First column text
 * @param col2 Second column text
 * @param col3 Third column text
 * @param col4 Forth column text
 */
void printRow(const std::string& col1, const std::string& col2, const std::string& col3, const std::string& col4) {
	std::cout << std::right
			  << std::setw(10) << formatCell(col1) << "|"
			  << std::setw(10) << formatCell(col2) << "|"
			  << std::setw(10) << formatCell(col3) << "|"
			  << std::setw(10) << formatCell(col4) << "|"
			  << std::endl;
}

/**
 * @brief Formats the given `text` and checks if it should be truncated or not.
 * @param text The text to possibly truncate
 * @return The formated text.
 */
std::string formatCell(const std::string& text) {
	if (text.length() > 9)
		return (text.substr(0,9) + ".");
	else
		return (text);
}

/**
 * @brief Initialize some values and basic user instructions 
 */
void Phonebook::startMessage(void) {
	currentSize = 0;
	startIndex = 0;
	std::cout << "Welcome to the phonebook!" << std::endl;
	std::cout << "Type \"ADD\" to add a new contract" << std::endl;
	std::cout << "Type \"SEARCH\" to search for a contract" << std::endl;
	std::cout << "Type \"EXIT\" to exit the program" << std::endl << std::endl;
}
