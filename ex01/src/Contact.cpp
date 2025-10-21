#include <iostream>
#include "Contact.hpp"
#include "PhoneBook.hpp"

/////////////// CONSTRUCTORS///////////////

Contact::Contact(void) 
{
	return;
}

Contact::~Contact(void) 
{
	return;
}

/////////////// SETTERS ///////////////

void Contact::SetName(std::string s) 
{
	this->_name = s;
	return;
}

void Contact::SetLastName(std::string s) 
{
	this->_lastname = s;
	return;
}

void Contact::SetNickName(std::string s) 
{
	this->_nickname = s;
	return;
}

void Contact::SetPhone(std::string s) 
{
	this->_phone_number = s;
	return;
}

void Contact::SetSecret(std::string s) 
{
	this->_darkest_secret = s;
	return;
}

/////////////// GETTERS ///////////////

std::string Contact::GetName(void)  
{
	return (_name);
}

std::string Contact::GetLastName(void) 
{
	return (_lastname);
}

std::string Contact::GetNickName(void) 
{
	return (_nickname);
}

std::string Contact::GetPhone(void) 
{
	return (_phone_number);
}

std::string Contact::GetSecret(void) 
{
	return (_darkest_secret);
}

/////////////// METHODS ///////////////

void Contact::PrintNewContact(void) 
{
	if (!_name.empty())
	{
		std::cout << BLUE << BOLD <<"Name : " << RESET << BLUE << GetName() << RESET << std::endl;
		std::cout << BLUE << BOLD <<"Lastname : " << RESET << BLUE << GetLastName() << RESET << std::endl;
		std::cout << BLUE << BOLD <<"Nickname : " << RESET << BLUE << GetNickName() << RESET << std::endl;
		std::cout << BLUE << BOLD <<"Phone number : " << RESET << BLUE << GetPhone() << RESET << std::endl;
		std::cout << BLUE << BOLD <<"Darkest Secret : " << RESET << BLUE << GetSecret() << RESET << std::endl;
	}
	return;
}


