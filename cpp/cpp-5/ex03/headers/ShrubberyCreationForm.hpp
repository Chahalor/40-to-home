#pragma once

#include "AForm.hpp"

class ShrubberyCreationForm: virtual public AForm
{
	private:
		static const int	_signGrade = 145;
		static const int	_execGrade = 137;
		std::string			_target;

	public:
	/* -Constructors- */
		ShrubberyCreationForm(const std::string &_target);
		ShrubberyCreationForm(const ShrubberyCreationForm &_other);

	/* -Destructors-  */
		~ShrubberyCreationForm();

	/*    -Getter-    */
		//...
	/*    -Setter-    */
		//...

	/*    -Members-   */
		void	beSigned(const Bureaucrat &_executor);
		void	execute(const Bureaucrat &_executor) const;

	/*  -Operators-   */
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &_other);
};
