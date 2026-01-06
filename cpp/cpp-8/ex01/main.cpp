#include <cstdlib>
#include <time.h>
#include <vector>
#include <list>
#include <set>

#include "all.hpp"
#include "Span.hpp"

#define PART(title) do {outl(YELLOW BOLD UNDERLINE << title << RESET)} while (0);


int	main(const int argc, const char *argv[])
{
	const int			_dummy = 0;
	int					_size = 0;

	if (argc > 2)
	{
		std::cerr << "usage: " << argv[0] << " <size>" << std::endl;
		return (EXIT_FAILURE);
	}
	else if (argc > 1)
	{
		_size = std::atoi(argv[1]);
		if (_size <= 0)
		{
			std::cerr << "<size> must be a valid unsigned int" << std::endl;
			return (EXIT_FAILURE);
		}
	}

	SRAND(_dummy);

	if (_size)
	{
		try
		{
			Span	_span = Span(_size);
			_span.fillRandom(_size - 1);

			outl(_span << "\nshortest Span: " << _span.shortestSpan() << "\nlongest Span: " << _span.longestSpan());
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	else
	{
		Span	span(10);

		PART("10 numbers Span")
		span.addNumber(1);
		span.addNumber(8);
		span.addNumber(5);
		span.addNumber(11);
		span.addNumber(88);
		span.addNumber(55);
		span.addNumber(23);
		span.addNumber(27);
		span.addNumber(42);
		span.addNumber(15);

		outl(span << "\nshortest Span: " << span.shortestSpan() << "\nlongest Span: " << span.longestSpan());

		PART("no more space in Span")
		try
		{
			span.addNumber(69);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		PART("Empty Span")
		Span	empty(0);
		try
		{
			empty.shortestSpan();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() <<'\n';
		}
	}
	return (EXIT_SUCCESS);
}
