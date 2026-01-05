#pragma once

#include "all.hpp"


template<typename T>
class Array
{
	private:
		T				*_array;
		unsigned int	_size;

	public:
	/* -Constructors- */
		Array();
		Array(const unsigned int);
		Array(const Array &_other);

	/* -Destructors-  */
		~Array();

	/*    -Getter-    */
		unsigned int	size(void) const;

	/*    -Setter-    */
		//...
	/*  -Operators-   */
		Array	&operator=(const Array &_other);
		T		&operator[](const unsigned int _index);
		const T	&operator[](const unsigned int _index) const;

	/*  -Exeptions-   */
		class	OutOfBoundExeption: public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
};

template<typename T>
std::ostream	&operator<<(std::ostream &os, const Array<T> &_target);

#include "Array.tpp"
