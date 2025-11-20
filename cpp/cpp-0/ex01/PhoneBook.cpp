#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
	: _nb_contacts(0)
{

}

PhoneBook::~PhoneBook()
{
}

Contact	&PhoneBook::getContact(
	const int _index
)
{
	if (__glibc_unlikely(_index < 0 || _index > 7))
		return (this->_contacts[0]);
	else
		return (this->_contacts[_index]);
}

int	&PhoneBook::getNbContacts(void)
{
	return (this->_nb_contacts);
}

void	PhoneBook::setContact(
	const int _index,
	Contact &_contact
)
{
	if (__glibc_unlikely(_index < 0 || _index > 7))
		return ;
	else
		this->_contacts[_index] = _contact;
}

int	PhoneBook::add_contact(
	Contact contact
)
{
	static int	_index = 0;

	this->_contacts[_index] = contact;

	_index = (_index + 1) % 8;
	this->_nb_contacts = std::min(this->_nb_contacts + 1, 8);
	return (_index);
}
