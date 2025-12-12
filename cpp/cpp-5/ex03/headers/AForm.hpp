#pragma once

#include "all.hpp"
#include "Bureaucrat.hpp"

class	Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		const int			_signGrade;
		const int			_execGrade;
		bool				_signed;

	public:
	/* -Constructors- */
		AForm(const std::string &_name, const int _signGrade, const int _execGrade);
		AForm(const AForm &_other);

	/* -Destructors-  */
		virtual ~AForm();

	/*    -Getter-    */
		const std::string	&getName(void) const;
		bool				isSigned(void) const;

	/*    -Setter-    */
		//...
	/*  -Operators-   */
		//...

	/*    -Members-   */
		void			beSigned(const Bureaucrat &_executor);
		virtual void	execute(const Bureaucrat &_executor) const = 0;

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

		class	NotSigned: public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &os, const AForm &_target);
