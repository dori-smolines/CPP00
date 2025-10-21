#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
#include "Contact.hpp"

#define GREEN	"\033[32m"
#define RED		"\033[31m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"
#define RESET	"\033[0m"
#define BOLD	"\033[1m"
#define PINK	"\033[95m"
#define LPINK	"\033[38;5;218m"
#define PURPLE	"\033[35m"
#define LPURPLE "\033[38;5;141m"
#define RED		"\033[31m"

class PhoneBook {

private :
	int _index;
	int _size;
	Contact _rep[8];
	bool	IsValidPhone(std::string s);
public :
	PhoneBook(void);
    ~PhoneBook(void);
	void	AddContact(void);
	void	SearchContact(void);
	int		GetIndex();
	int		GetSize();
	void	Search(int index);
	void	Menu (void);
	void	AddName (void);
	void	AddLastName (void);
	void	AddNickName (void);
	void	AddNumber (void);
	void	AddSecret (void);
	void	DisplayContact(void);
};

#endif
