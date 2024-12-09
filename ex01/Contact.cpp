#include "Contact.hpp"

// Constructor
Contact::Contact() {}

// Destructor
Contact::~Contact() {}

// Getters
std::string	Contact::getFirstName() const { return (this->_firstName); }

std::string Contact::getLastName() const { return (this->_lastName); }

std::string Contact::getNickname() const { return (this->_nickname); }

std::string Contact::getPhoneNumber() const { return (this->_phoneNumber); }

std::string Contact::getDarkestSecret() const { return (this->_darkestSecret); }

void Contact::createNewContact(const std::string firstName,
							   const std::string lastName,
							   const std::string nickName,
							   const std::string phoneNumber,
							   const std::string darkestSecret)
{
	this->_firstName = firstName;
	this->_lastName = lastName;
	this->_nickname = nickName;
	this->_phoneNumber = phoneNumber;
	this->_darkestSecret = darkestSecret;
}