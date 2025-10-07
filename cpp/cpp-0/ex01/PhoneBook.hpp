#pragma once

#include "Contact.hpp"

class PhoneBook
{
private:

public:
	Contact	contacts[8];
	int		nb_contacts;

	int		add_contact(Contact constact);
	PhoneBook(void);
	~PhoneBook(void);
};
