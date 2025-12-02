#pragma once

#include <iostream>

#include "all.hpp"
#include "AForm.hpp"

class	AForm;

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;

	public:
	/* -Constructors- */
		Bureaucrat(const std::string &_name, const int _grade);
		Bureaucrat(const Bureaucrat &_other);

	/* -Destructors-  */
		~Bureaucrat();

	/*    -Getter-    */
		const std::string	&getName(void) const;
		int					getGrade(void) const;

	/*    -Setter-    */
		void	incrementGrade(const int _value);
		void	decrementGrade(const int _value);

	/*  -Operators-   */
		Bureaucrat &operator=(const Bureaucrat &_other);

	/*    -Members-   */
		void	signForm(AForm &_form);
		void	executeForm(AForm const &_form);

	/*  -Exeptions-   */
		class	GradeTooHighException: public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

		class	GradeTooLowException: public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &os, const Bureaucrat &_target);