#pragma once

#include <iostream>

#include "all.hpp"

class ScalarConverter
{
	private:
		//...

	public:
	/* -Constructors- */
		ScalarConverter();
		ScalarConverter(const ScalarConverter &_other);

	/* -Destructors-  */
		~ScalarConverter();

	/*    -Getter-    */
		//...

	/*    -Setter-    */
		//...

	/*  -Operators-   */
		ScalarConverter &operator=(const ScalarConverter &_other);

	/*  -Methodes-    */
		static void	convert(const std::string &_input);
};
