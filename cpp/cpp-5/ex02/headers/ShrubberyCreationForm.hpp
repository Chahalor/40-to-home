#pragma once

#include "AForm.hpp"

class ShrubberyCreationForm
{
	private:
		//...
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
		void	execute(const Bureaucrat &_executor);

	/*  -Operators-   */
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &_other);
};
