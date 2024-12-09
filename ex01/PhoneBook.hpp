#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

# define RED "\033[31m"
# define GREEN "\033[32m"
# define PURPLE "\033[35m"
# define CYAN "\033[36m"
# define RESET "\033[0m"

# include "Contact.hpp"
# include <iostream>
# include <iomanip>
# include <algorithm>

class PhoneBook
{
	private:
		Contact _contacts[8];
		int		_maxContacts;

	public:
		// Constructor
		PhoneBook(int maxContacts);

		// Destructor
		~PhoneBook();

		// Methodes
		void		addContact(int index);
		void		searchContact();

		std::string	getInput(const std::string prompt, bool numberVerification) const;
		bool		isSpaceInString(const std::string str) const;
		bool		isEmptyInformations(const std::string information) const;
		bool		isValidNumber(const std::string phoneNumber) const;
		void		truncateAndAppend(std::string &string, int maxLen);
		void		displayContact(int index) const;
};

#endif