#include <iostream>
#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <sstream>
#include <cctype>

//////////// CONSTRUCTORS ////////////

PhoneBook::PhoneBook(void)
{
	std::cout << BOLD << LPINK << "Welcome to your new personnal PhoneBook" << RESET << std::endl;
	_index = 0;
	_size = 0;
	return;
}

PhoneBook::~PhoneBook(void)
{
	return;
}

//////////// GETTERS ////////////

int PhoneBook::GetIndex()
{
	return (_index);
}

int PhoneBook::GetSize()
{
	return (_size);
}

//////////// METHODS ////////////

void PhoneBook::Menu (void)
{
    std::string choice;

    while (true)
	{
	    std::cout << PINK << "Please enter ADD, SEARCH or EXIT" << RESET << std::endl;
		if (!(std::cin >> choice))
			break;
		if (choice == "ADD")
			AddContact();
		else if (choice == "SEARCH")
			SearchContact();
		else if (choice == "EXIT")
			break;
		else
			std::cout << BOLD << RED << "Error : command " << choice << " is not valid" << RESET<< std::endl;
	}
}

void PhoneBook::AddContact()
{
	_rep[_index] = Contact();
	AddName();
	AddLastName();
	AddNickName();
	AddNumber();
	AddSecret();
	//	std::cout << " index = "<< _index << std::endl;
	std::cout << PURPLE << BOLD << "New contact bas been added at index " << _index << RESET << std::endl;
	_rep[_index].PrintNewContact();
	_index = (_index + 1) % 8;
	if (_size < 8)
		_size++;
	return;
}

void PhoneBook::AddName(void)
{
	std::string var;

	std::cout << " Enter a name : ";
	if (!std::getline(std::cin >> std::ws, var))
		exit(0);
	_rep[_index].SetName(var);
}

void PhoneBook::AddLastName(void)
{
	std::string var;

	std::cout << " Enter a last name : ";
	if (!std::getline(std::cin >> std::ws, var))
		exit(0);
	_rep[_index].SetLastName(var);
}

void PhoneBook::AddNickName(void)
{
	std::string var;

	std::cout << " Enter a nickname : ";
	if (!std::getline(std::cin >> std::ws, var))
		exit(0);
	_rep[_index].SetNickName(var);
}

bool PhoneBook::IsValidPhone(std::string s)
{
	if (s.length() != 10)
		return false;
	{
		for (std::string::size_type i = 0; i < s.length(); ++i)
		{
			if (!std::isdigit(s[i]))
				return false;
		}
		return true;
	}
}

void PhoneBook::AddSecret(void)
{
	std::string var;

	std::cout << " Enter a darkest secret : ";
	if (!std::getline(std::cin >> std::ws, var))
		exit(0);
	_rep[_index].SetSecret(var);
}

void PhoneBook::AddNumber(void)
{
	std::string var;

	std::cout << " Enter a Phone Number : ";
	if (!std::getline(std::cin >> std::ws, var))
		exit(0);
	while (!IsValidPhone(var))
	{
		std::cout << RED << " Invalid phone number. Try again : " << RESET;
		if (!std::getline(std::cin >> std::ws, var))
			exit(0);
	}
	_rep[_index].SetPhone(var);
}

void PhoneBook::DisplayContact(void)
{
	std::string input;
	int nb;
	while (true)
	{
		std::cout << "Enter an index number between 0 and 7" << std::endl;
		if (!std::getline(std::cin >> std::ws, input))
			exit(0);
		std::istringstream iss(input);
		if (!(iss >> nb) || !iss.eof() || nb < 0 || nb > 7)
		{
			std::cout << RED << "Invalid input. Please enter a number between 0 and 7" << RESET << std::endl;
			continue;
		}
		if (nb < (int)GetSize() && !_rep[nb].GetName().empty())
		{
			std::cout << PURPLE << BOLD << "Here is your contact : " << RESET << std::endl;
			_rep[nb].PrintNewContact();
		}
		else
			std::cout << "No contact stored at this index" << std::endl;
		break;
	}
}

void PhoneBook::SearchContact(void)
{
	std::cout << "+----------+----------+----------+----------+" << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;

	for (int i = 0; i < GetSize(); i++)
	{
		std::cout << "+----------+----------+----------+----------+" << std::endl;
		std::cout << "|" << std::setfill(' ') << std::setw(10) << i << "|";

		if (!_rep[i].GetName().empty())
		{
			if (_rep[i].GetName().length() > 10)
				std::cout << _rep[i].GetName().substr(0, 9) << ".";
			else
				std::cout << std::setfill(' ') << std::setw(10) << _rep[i].GetName();
			std::cout << "|";

			if (_rep[i].GetLastName().length() > 10)
				std::cout << _rep[i].GetLastName().substr(0, 9) << ".";
			else
				std::cout << std::setfill(' ') << std::setw(10) << _rep[i].GetLastName();
			std::cout << "|";

			if (_rep[i].GetNickName().length() > 10)
				std::cout << _rep[i].GetNickName().substr(0, 9) << ".";
			else
				std::cout << std::setfill(' ') << std::setw(10) << _rep[i].GetNickName();
			std::cout << "|";
		}
		std::cout << std::endl;
	}
	std::cout << "+----------+----------+----------+----------+" << std::endl;

	DisplayContact();
}



