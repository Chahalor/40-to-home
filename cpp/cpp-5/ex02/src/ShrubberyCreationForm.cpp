#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(
	const std::string &_target
)
	:	AForm("ShrubberyCreationForm", this->_signGrade, this->_execGrade),
		_target(_target)
{
	all::logs("ShrubberyCreationForm constructor called");
}

ShrubberyCreationForm::ShrubberyCreationForm(
	const ShrubberyCreationForm &_other
)
	:	AForm(_other),
		_target(_other._target)
{
	all::logs("ShrubberyCreationForm copy constructor called");
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	all::logs("ShrubberyCreationForm destructor called");
}

void	ShrubberyCreationForm::execute(
	const Bureaucrat &_executor
) const
{
	if (unlikely(_executor.getGrade() > this->_execGrade))
		throw ShrubberyCreationForm::GradeTooLowException();
	else if (unlikely(!this->isSigned()))
		throw AForm::NotSigned();
	else
	{
		outl("      *             ,\n"							\
			"                  _/^\\_\n"						\
			"                 <     >\n"						\
			"*                 /.-.\\         *\n"				\
			"         *        `/&\\`                   *\n"	\
			"                 ,@.*;@,\n"						\
			"                /_o.I %_\\    *\n"					\
			"   *           (`'--:o(_@;\n"						\
			"              /`;--.,__ `')             *\n"		\
			"             ;@`o % O,*`'`&\\\n"					\
			"       *    (`'--)_@ ;o %'()\\      *\n"			\
			"            /`;--._`''--._O'@;\n"					\
			"           /&*,()~o`;-.,_ `\"\"`)\n"				\
			"*          /`,@ ;+& () o*`;-';\\\n"				\
			"          (`\"\"--.,_0 +% @' &()\\\n"				\
			"          /-.,_    ``''--....-'`)  *\n"			\
			"     *    /@%;o`:;'--,.__   __.'\\\n"				\
			"         ;*,&(); @ % &^;~`\"`o;@();         *\n"	\
			"         /(); o^~; & ().o@*&`;&%O\\\n"				\
			"   jgs   `\"=\"==\"\"==,,,.,=\"==\"===\"`\n"		\
			"      __.----.(\\-''#####---...___...-----._\n"	\
			"    '`         \\)_`\"\"\"\"\"`\n"					\
			"            .--' ')\n"								\
			"          o(  )_-\\\n"								\
			"            `\"\"\"` `\n");
	}
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(
	const ShrubberyCreationForm &_other
)
{
	this->_target = _other._target;
	return (*this);
}
