#pragma once

#include "AForm.hpp"

class PresidentialPardonForm: public virtual AForm
{
	private:
		static const int	_signGrade = 25;
		static const int	_execGrade = 5;
		std::string			_target;

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
		void	execute(const Bureaucrat &_executor) const;

	/*  -Operators-   */
		PresidentialPardonForm &operator=(const PresidentialPardonForm &_other);
};
