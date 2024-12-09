#ifndef CONTACTS_HPP
# define CONTACTS_HPP

# include <string>

class Contact
{
	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickname;
		std::string	_phoneNumber;
		std::string	_darkestSecret;

	public:
		// Constructor
		Contact();

		// Destructor
		~Contact();

		// Getters
		std::string	getFirstName() const;
		std::string	getLastName() const;
		std::string	getNickname() const;
		std::string	getPhoneNumber() const;
		std::string	getDarkestSecret() const;

		// Methodes
		void		createNewContact(const std::string firstName,
									 const std::string lastName,
									 const std::string nickname,
									 const std::string phoneNumber,
									 const std::string darkestSecret);
};

#endif