#pragma once

#include <iostream>

class Contact
{
private:

public:
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	secret;
	Contact(
		std::string	first_name,
		std::string	last_name,
		std::string	nickname,
		std::string	phone_number,
		std::string	secret
	);
	Contact(
		char	*first_name,
		char	*last_name,
		char	*nickname,
		char	*phone_number,
		char	*secret
	);
	Contact(void);
	~Contact();
};