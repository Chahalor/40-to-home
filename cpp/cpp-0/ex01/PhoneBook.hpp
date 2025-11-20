#pragma once

#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact	_contacts[8];
		int		_nb_contacts;

	public:
		PhoneBook(void);
		~PhoneBook(void);

		Contact &getContact(const int _index);
		int		&getNbContacts(void);
		void	setContact(const int _index, Contact &_contact);

		int	add_contact(Contact constact);
};
