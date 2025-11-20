#include "Contact.hpp"

Contact::Contact(void)
	:	_first_name(""),
		_last_name(""),
		_nickname(""),
		_phone_number(""),
		_secret("")
{

}

Contact::Contact(
	std::string	_first_name,
	std::string	_last_name,
	std::string	_nickname,
	std::string	_phone_number,
	std::string	_secret
)
	:	_first_name(_first_name),
		_last_name(_last_name),
		_nickname(_nickname),
		_phone_number(_phone_number),
		_secret(_secret)
{

}

Contact::Contact(
	char	*_first_name,
	char	*_last_name,
	char	*_nickname,
	char	*_phone_number,
	char	*_secret
)
	:	_first_name(_first_name),
		_last_name(_last_name),
		_nickname(_nickname),
		_phone_number(_phone_number),
		_secret(_secret)
{

}

Contact::~Contact()
{
}

std::string	&Contact::getFirstName(void)
{
	return (this->_first_name);
}

std::string	&Contact::getLastName(void)
{
	return (this->_last_name);
}

std::string	&Contact::getNickName(void)
{
	return (this->_nickname);
}

std::string	&Contact::getPhoneNumber(void)
{
	return (this->_phone_number);
}

std::string	&Contact::getSecret(void)
{
	return (this->_secret);
}
