#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
#include <sstream>

class Contact {
	private:
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string darkestSecret;
		std::string	phoneNumber;
		std::string	index;

	public:
		void inputContactDetails(void);
		void displayContact(void);
		void setIndex(int idx);
		std::string getFirstName(void);
		std::string getLastName(void);
		std::string getNickname(void);
		std::string getIndex(void);
};

#endif
