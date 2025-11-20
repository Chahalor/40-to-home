#pragma once

#include <iostream>

class Contact
{
	private:
		std::string	_first_name;
		std::string	_last_name;
		std::string	_nickname;
		std::string	_phone_number;
		std::string	_secret;

	public:
		Contact(void);
		~Contact();

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

		std::string	&getFirstName(void);
		std::string	&getLastName(void);
		std::string	&getNickName(void);
		std::string	&getPhoneNumber(void);
		std::string	&getSecret(void);
};