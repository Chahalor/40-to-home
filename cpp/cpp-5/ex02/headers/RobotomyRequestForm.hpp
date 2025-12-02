#pragma once

#include "AForm.hpp"

class RobotomyRequestForm
{
	private:
		//...
	public:
	/* -Constructors- */
		RobotomyRequestForm(const std::string &_target);
		RobotomyRequestForm(const RobotomyRequestForm &_other);

	/* -Destructors-  */
		~RobotomyRequestForm();

	/*    -Getter-    */
		//...
	/*    -Setter-    */
		//...

	/*    -Members-   */
		void	beSigned(const Bureaucrat &_executor);

	/*  -Operators-   */
		RobotomyRequestForm &operator=(const RobotomyRequestForm &_other);
};
