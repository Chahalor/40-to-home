#pragma once

#include <exception>
#include <algorithm>
#include <vector>

#include "all.hpp"

class Span
{
	private:
		std::vector<int>	_storage;
		unsigned int		_capacity;
		unsigned int		_idx;

	public:
	/* -Constructors- */
		Span(const unsigned int &_capacity);
		Span(const Span &_other);

	/* -Destructors-  */
		~Span();

	/*    -Getter-    */
		const std::vector<int>	&getStorage(void) const;
		const unsigned int		&getCapacity(void) const;
		const unsigned int		&getIdx(void) const;

	/*    -Setter-    */
		void	addNumber(const int &_nbr);
		void	addRange(const int &_val1, const int &_val2);
		void	fillRandom(const int &_nb_values);

	/*  -Operators-   */
		Span &operator=(const Span &_other);

	/*  -Methodes-    */
		int	shortestSpan(void) const;
		int	longestSpan(void) const;

	/*  -Exeptions-   */
		class EmptySpanExeption: virtual public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

		class NotEnoughDataExeption: virtual public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

		class NoSpanFoundExeption: virtual public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

		class SpanFullExeption: virtual public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &os, const Span &_target);
