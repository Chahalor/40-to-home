#pragma once

#include "AForm.hpp"

class RobotomyRequestForm: virtual public AForm
{
	private:
		static const int	_signGrade = 72;
		static const int	_execGrade = 45;
		std::string			_target;

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
		void	execute(const Bureaucrat &_executor) const;

	/*  -Operators-   */
		RobotomyRequestForm &operator=(const RobotomyRequestForm &_other);
};
