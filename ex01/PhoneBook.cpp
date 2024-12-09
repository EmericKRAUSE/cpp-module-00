#include "PhoneBook.hpp"

// Constructor
PhoneBook::PhoneBook(int maxContacts): _maxContacts(maxContacts) {}

// Destructor
PhoneBook::~PhoneBook() {}

// Methodes
bool PhoneBook::isEmptyInformations(const std::string value) const
{
	if (value.empty())
	{
		std::cout << RED << "Input cannot be empty" << RESET << std::endl;
		return (true);
	}
	return (false);
}

bool PhoneBook::isValidNumber(const std::string phoneNumber) const
{
	for (int i = 0; phoneNumber[i]; i++)
	{
		if (!std::isdigit(phoneNumber[i]))
		{
			std::cout << RED << "Phone number must be only composed of numbers" << RESET << std::endl;
			return (false);
		}
	}
	if (phoneNumber.size() != 10)
	{
		std::cout << RED << "Phone number size must be 10" << RESET << std::endl;
		return (false);
	}
	return (true);
}

bool PhoneBook::isSpaceInString(const std::string str) const
{
	for (int i = 0; str[i]; i++)
	{
		if (isspace(str[i]))
		{
			std::cout << RED << "Input cannot contain spaces" << RESET << std::endl;
			return (true);
		}
	}
	return (false);
}

std::string PhoneBook::getInput(const std::string prompt, bool numberVerification) const
{
	std::string input;

	while (true)
	{
		std::cout << prompt << std::endl;
		if (!std::getline(std::cin, input))
			exit(EXIT_FAILURE);
		if (isEmptyInformations(input) || isSpaceInString(input))
			continue;
		if (numberVerification && !isValidNumber(input))
			continue;
		break;
	}
	return (input);
}

void PhoneBook::addContact(int index)
{
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;
	int			circularIndex;

	std::cout << CYAN << "Creation of a new contact" << RESET << std::endl;

	firstName = getInput("Enter the contacts's First name:", false);
	lastName = getInput("Enter the contacts's Last name:", false);
	nickname = getInput("Enter the contacts's Nickname:", false);
	phoneNumber = getInput("Enter the contacts's Phone number:", true);
	darkestSecret = getInput("Enter the contacts's Darkest secret:", false);

	circularIndex = index % _maxContacts;
	_contacts[circularIndex].createNewContact(firstName,
											  lastName,
											  nickname,
											  phoneNumber,
											  darkestSecret);

	std::cout << GREEN << "Contact added successfully" << RESET << std::endl;
}

void PhoneBook::truncateAndAppend(std::string &string, int maxLen)
{
	if (string.size() > maxLen)
	{
		string = string.substr(0, maxLen - 1);
		string.append(".");
	}
}

void PhoneBook::displayContact(int index) const
{
	std::cout << "First Name: " << _contacts[index].getFirstName() << std::endl;
	std::cout << "Last Name: " << _contacts[index].getLastName() << std::endl;
	std::cout << "Nickname: " << _contacts[index].getNickname() << std::endl;
	std::cout << "Phone Number: " << _contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << _contacts[index].getDarkestSecret() << std::endl;
}

void PhoneBook::searchContact()
{
	int			index;
	bool		isValid;
	std::string userIndex;
	std::string firstName;
	std::string lastName;
	std::string nickname;

	std::cout << "---------------------------------------------" << std::endl
			  << "|"
			  << std::setw(10) << "INDEX" << "|"
			  << std::setw(10) << "FIRST NAME" << "|"
			  << std::setw(10) << "LAST NAME" << "|"
			  << std::setw(10) << "NICKNAME" << "|"
			  << std::endl
			  << "+----------+----------+----------+----------+" << std::endl;

	for (int i = 0; i < _maxContacts; i++)
	{
		firstName = _contacts[i].getFirstName();
		truncateAndAppend(firstName, 10);

		lastName = _contacts[i].getLastName();
		truncateAndAppend(lastName, 10);

		nickname = _contacts[i].getNickname();
		truncateAndAppend(nickname, 10);

		std::cout << "|"
				  << std::setw(10) << i + 1 << "|"
				  << std::setw(10) << firstName << "|"
				  << std::setw(10) << lastName << "|"
				  << std::setw(10) << nickname << "|" << std::endl;
	}

	std::cout << "---------------------------------------------" << std::endl;

	isValid = false;
	index = 0;

	while (!isValid)
	{
		std::cout << "Enter the index" << std::endl;
		if (!std::getline(std::cin, userIndex))
			exit(EXIT_FAILURE);

		if (userIndex.size() < 9)
			index = atoi(userIndex.c_str());
		else
			std::cout << PURPLE << "Stop trying to break atoi" << RESET << std::endl;
		if (index > 0 && index <= _maxContacts)
			isValid = true;
		else
			std::cout << RED << "Index number must be between 1 and " << _maxContacts << RESET << std::endl;
	}
	displayContact(index - 1);
}
