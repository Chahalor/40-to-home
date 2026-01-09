#pragma once

/* ************************************************************************** */
/*                                 Headers                                    */
/* ************************************************************************** */

/* -----| Systems   |----- */
#include <exception>
#include <deque>
#include <vector>
#include <time.h>
#include <tuple>

/* -----| Globals   |----- */
#include "all.hpp"

/* -----| Internals |----- */
	//..

/* -----| Modules   |----- */
	//...

/* ************************************************************************** */
/*                                 Macros                                     */
/* ************************************************************************** */
	//...

/* ************************************************************************** */
/*                                 Typedefs                                   */
/* ************************************************************************** */
	//...

/* ************************************************************************** */
/*                                 Enums                                      */
/* ************************************************************************** */
	//...

/* ************************************************************************** */
/*                                 Unions                                     */
/* ************************************************************************** */
	//...

/* ************************************************************************** */
/*                                 Structs                                    */
/* ************************************************************************** */
	//...

/* ************************************************************************** */
/*                                 Class                                      */
/* ************************************************************************** */

#pragma once

class RPN
{
	private:
		//...
	public:
	/* -Constructors- */
		//...

	/* -Destructors-  */
		//...

	/*    -Getter-    */
		//...

	/*    -Setter-    */
		//...

	/*  -Operators-   */
		//...

	/*  -Methode-     */
		static int	evaluate(const std::string &_expr);

	/*  -Exeptions-   */

	class	InvalidCharExeption: virtual public std::exception
	{
		private:
			std::string	_msg;

		public:
			InvalidCharExeption();
			InvalidCharExeption(const char _c);
			virtual ~InvalidCharExeption() throw() {}
			const char	*what(void) const throw();
	};

	class	InvalidOperatorExeption: virtual public std::exception
	{
		private:
			std::string	_msg;

		public:
			InvalidOperatorExeption(void);
			InvalidOperatorExeption(const char _c);
			virtual ~InvalidOperatorExeption() throw() {}
			const char	*what(void) const throw();
	};

	class	InvalidNumberExeption: virtual public std::exception
	{
		private:
			std::string	_msg;

		public:
			InvalidNumberExeption(void);
			InvalidNumberExeption(const std::string &_s);
			virtual ~InvalidNumberExeption(void) throw() {}
			const char	*what(void) const throw();
	};
};

/* ************************************************************************** */
/*                                 Prototypes                                 */
/* ************************************************************************** */

