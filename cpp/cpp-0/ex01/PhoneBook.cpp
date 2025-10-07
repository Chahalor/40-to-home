#include "PhoneBook.hpp"


int	PhoneBook::add_contact(Contact contact)
{
	static int	_index = 0;

	this->contacts[_index] = contact;

	_index = (_index + 1) % 8;
	this->nb_contacts = std::min(this->nb_contacts + 1, 8);
	return (_index);
}

PhoneBook::PhoneBook(void)
{
	nb_contacts = 0;
}

PhoneBook::~PhoneBook()
{
}
