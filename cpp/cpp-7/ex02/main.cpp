#include <cstdlib>
#include <time.h>

#include "all.hpp"
#include "Array.hpp"

#define PART(title) do {outl(YELLOW BOLD UNDERLINE << title << RESET)} while (0);

template<typename T>
static std::string	to_string_value(
	const T &value
)
{
	std::ostringstream	oss;

	oss << std::boolalpha << value;
	return (oss.str());
}

static void	record_result(
	const bool ok,
	const std::string &label,
	const std::string &detail,
	int &passed,
	int &total
)
{
	total++;
	if (ok)
		passed++;
	outl((ok ? GREEN "OK" RESET : RED "KO" RESET) << " " << label << " " << detail);
}

template<typename T>
static void	expect_value(
	const std::string &label,
	const T &got,
	const T &expected,
	int &passed,
	int &total
)
{
	record_result(
		(got == expected),
		label,
		"got " + to_string_value(got) + " expected " + to_string_value(expected),
		passed,
		total
	);
}

template<typename T>
static void	fill_increment(
	Array<T> &arr,
	const T &start
)
{
	unsigned int	i;

	i = 0;
	while (i < arr.size())
	{
		arr[i] = static_cast<T>(start + i);
		i++;
	}
}

int	main(void)
{
	int	passed = 0;
	int	total = 0;

	PART("default constructor");
	{
		Array<int>	a;

		expect_value<unsigned int>("size == 0", a.size(), 0u, passed, total);
		try
		{
			(void)a[0];
			record_result(false, "access empty", "expected exception", passed, total);
		}
		catch (const std::exception &)
		{
			record_result(true, "access empty", "threw exception", passed, total);
		}
	}

	PART("sized constructor + values");
	{
		Array<int>	b(5);

		expect_value<unsigned int>("size == 5", b.size(), 5u, passed, total);
		fill_increment<int>(b, 10);
		expect_value<int>("b[0]", b[0], 10, passed, total);
		expect_value<int>("b[4]", b[4], 14, passed, total);
		try
		{
			(void)b[5];
			record_result(false, "out of bound", "expected exception", passed, total);
		}
		catch (const std::exception &)
		{
			record_result(true, "out of bound", "threw exception", passed, total);
		}
	}

	PART("copy constructor");
	{
		Array<int>	src(3);
		fill_increment<int>(src, 1);
		Array<int>	copy(src);

		src[0] = 99;
		expect_value<int>("copy[0] unchanged", copy[0], 1, passed, total);
	}

	PART("assignment operator");
	{
		Array<int>	src(4);
		fill_increment<int>(src, 5);
		Array<int>	dst;

		dst = src;
		src[1] = 42;
		expect_value<int>("dst[1] unchanged", dst[1], 6, passed, total);
	}

	PART("const access");
	{
		Array<int>	tmp(2);
		fill_increment<int>(tmp, 7);
		const Array<int>	cst(tmp);

		expect_value<int>("cst[1]", cst[1], 8, passed, total);
	}

	PART("string array");
	{
		Array<std::string>	s(3);

		s[0] = "alpha";
		s[1] = "beta";
		s[2] = "gamma";
		expect_value<std::string>("s[0]", s[0], "alpha", passed, total);
		expect_value<std::string>("s[2]", s[2], "gamma", passed, total);
	}

	outl(BOLD << "Result: " << passed << "/" << total << RESET);
	return (passed == total ? 0 : 1);
}
