#pragma once

#include "AForm.hpp"

class PresidentialPardonForm: public virtual AForm
{
	private:
		//...
	public:
	/* -Constructors- */
		PresidentialPardonForm(const std::string &_target);
		PresidentialPardonForm(const PresidentialPardonForm &_other);

	/* -Destructors-  */
		~PresidentialPardonForm();

	/*    -Getter-    */
		//...
	/*    -Setter-    */
		//...

	/*    -Members-   */
		void	beSigned(const Bureaucrat &_executor);

	/*  -Operators-   */
		PresidentialPardonForm &operator=(const PresidentialPardonForm &_other);
};
