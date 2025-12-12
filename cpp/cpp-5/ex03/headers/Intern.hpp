#pragma once

#include "AForm.hpp"

class Intern
{
	private:
		//...

	public:
	/* -Constructors- */
		Intern();
		Intern(const Intern &_other);

	/* -Destructors-  */
		~Intern();
		//...
	/*    -Getter-    */
		//...
	/*    -Setter-    */
		//...
	/*  -Operators-   */
		Intern &operator=(const Intern &_other);

	/*  -Methodes-    */
		AForm	*makeForm(const std::string &_name, const std::string &_target);

	/*  -Exeptions-   */
		class	FormNotFound: public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &os, const Intern &_target);

typedef struct s_form
{
	std::string	name;
	AForm	*(*func)(const std::string &);
}	t_form;