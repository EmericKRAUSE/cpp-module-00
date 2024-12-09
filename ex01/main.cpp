#include "main.hpp"

bool is_command_valid(const std::string command)
{
	const std::string commands[] = {"ADD", "SEARCH", "EXIT"};

	for (int i = 0; i < 3; i++)
	{
		if (commands[i] == command)
			return (true);
	}

	return (false);
}

void display_header()
{
	std::system("clear");
	std::cout << CYAN << "Enter one of the following commands:" << RESET << std::endl;
	std::cout << "[ADD] [SEARCH] [EXIT]" << std::endl;
}

int main()
{
	PhoneBook	phoneBook(8);
	std::string command;
	int			index;

	index = 0;
	while (true)
	{
		while (!is_command_valid(command))
		{
			display_header();
			if (!std::getline(std::cin, command))
				exit(EXIT_FAILURE);
		}

		if (command == "ADD")
			phoneBook.addContact(index++);
		else if (command == "SEARCH")
			phoneBook.searchContact();
		else if (command == "EXIT")
			exit(EXIT_SUCCESS);

		std::cout << CYAN << "Press Enter to continue..." << CYAN << std::endl;
		if (!std::getline(std::cin, command))
			exit(EXIT_FAILURE);
		command.clear();
	}
	return (0);
}
