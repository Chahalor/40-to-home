#include <iostream>
#include <iomanip>

#include "all.hpp"
#include "PhoneBook.hpp"

static inline bool	_add(
	PhoneBook *const book
)
{
	std::string	_first_name;
	std::string	_last_name;
	std::string	_nickname;
	std::string	_phone_number;
	std::string	_secret;

	while (true)
	{
		if (all::readAscii("first name: ", &_first_name))
			return (false);
		if (_first_name.length())
			break ;
		outl("this field can t be empty");
	}
	while (true)
	{
		if (all::readAscii("last name: ", &_last_name))
			return (false);
		if (_last_name.length())
			break ;
		outl("this field can t be empty");
	}
	while (true)
	{
		if (all::readAscii("nickname: ", &_nickname))
			return (false);
		if (_nickname.length())
			break ;
		outl("this field can t be empty");
	}
	while (true)
	{
		if (all::readAscii("phone number: ", &_phone_number))
			return (false);
		if (_phone_number.length())
			break ;
		outl("this field can t be empty");
	}
	while (true)
	{
		if (all::readAscii("darkest secret: ", &_secret))
			return (false);
		if (_secret.length())
			break ;
		outl("this field can t be empty");
	}

	Contact	_new = Contact(_first_name, _last_name, _nickname, _phone_number, _secret);
	book->add_contact(_new);
	return (true);
}

static inline bool	_search(
	PhoneBook *const book
)
{
	int			_index = 0;
	std::string	input;

	outl("| index | first name | last name  |  nickname  |");
	outl("------------------------------------------------");
	while (_index < 8)
	{
		Contact	_current = book->contacts[_index];
		outl("|" << std::setw(4) << _index << std::string(3, ' ') \
			<< "|" << all::pad(_current.first_name, 12) \
			<< "|" << all::pad(_current.last_name, 12) \
			<< "|" << all::pad(_current.nickname, 12) \
			<< "|"
		);
		_index++;
	}
	if (all::readAscii("index >> ", &input))
		return (false);


	std::stringstream(input) >> _index;

	if (_index > book->nb_contacts || _index < 0 || _index >= 8)
	{
		outl("input out of bound");
		return (_search(book));
	}
	Contact	_target = book->contacts[_index];
	outl("first name: " << _target.first_name \
		<< "\nlast name: " << _target.last_name \
		<< "\nnickname: " << _target.nickname \
		<< "\nnumber: " << _target.phone_number \
		<< "\nsecrect: " << _target.secret
	);
	return (true);
}

int	main(void)
{
	PhoneBook	book = PhoneBook();
	bool		running = true;

	while (running)
	{
		std::string	action;
		outl("nb contacts: " << book.nb_contacts);	//TODO: rm
		if (all::readAscii("action >> ", &action))
		{
			outl("exiting :)");
			running = false;
		}
		else if (action == "ADD")
			running = _add(&book);
		else if (action == "SEARCH")
			running = _search(&book);
		else if (action == "EXIT")
			running = false;
		else
			outl("invalide input, choose one beteewn (ADD, SEARCH, EXIT)");
	}
	return (0);
}
