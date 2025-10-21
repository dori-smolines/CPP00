#ifndef Contact_HPP
# define Contact_HPP


class Contact {

private :
    std::string _name;
    std::string _lastname;
    std::string _nickname;
    std::string _phone_number;
    std::string _darkest_secret;
	
public :

    Contact(void);
    ~Contact(void);
	void		PrintNewContact(void);
	std::string	get_info (std::string title, std::string var);
	void		SetName(std::string s);
	void		SetLastName(std::string s);
	void		SetNickName(std::string s);
	void 		SetPhone(std::string s);
	void 		SetSecret(std::string s);
	std::string	GetSecret(void);
	std::string GetName(void);
	std::string GetLastName(void);
	std::string GetNickName(void);
	std::string GetPhone(void);
};

#endif

