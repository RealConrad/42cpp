#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include "Contact.hpp"

class Phonebook {
	private:
		Contact contacts[8];
		int		currentSize;
		int		startIndex;

	public:
		void addContact(const Contact& contact);
		void displayContacts(void);
		void search(void);
		void startMessage(void);
		bool isValidIndex(const std::string& idx, Contact& contact);

};

#endif