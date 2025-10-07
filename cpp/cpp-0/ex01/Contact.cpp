#include "Contact.hpp"

Contact::Contact(void)
{
	first_name = "";
	last_name = "";
	nickname = "";
	phone_number = "";
	secret = "";
}

Contact::Contact(
	std::string	_first_name,
	std::string	_last_name,
	std::string	_nickname,
	std::string	_phone_number,
	std::string	_secret
)
{
	first_name = _first_name;
	last_name = _last_name;
	nickname = _nickname;
	phone_number = _phone_number;
	secret = _secret;
}

Contact::Contact(
	char	*_first_name,
	char	*_last_name,
	char	*_nickname,
	char	*_phone_number,
	char	*_secret
)
{
	first_name = _first_name;
	last_name = _last_name;
	nickname = _nickname;
	phone_number = _phone_number;
	secret = _secret;
}

Contact::~Contact()
{
}
