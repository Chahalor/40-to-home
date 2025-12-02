#pragma once

#include "all.hpp"
#include "Bureaucrat.hpp"

class	Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		const int			_signGrade;
		const int			_execGrade;
		bool				_signed;

	public:
	/* -Constructors- */
		Form(const std::string &_name, const int _signGrade, const int _execGrade);
		Form(const Form &_other);

	/* -Destructors-  */
		~Form();

	/*    -Getter-    */
		const std::string	&getName(void) const;

	/*    -Setter-    */
		//...
	/*  -Operators-   */
		//...

	/*    -Members-   */
		void	beSigned(const Bureaucrat &_executor);

	/*  -Exeptions-   */
		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class	GradeTooLowException: public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &os, const Form &_target);
