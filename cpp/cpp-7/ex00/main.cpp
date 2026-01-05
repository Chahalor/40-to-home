#include "all.hpp"
#include "templates.hpp"

#define PART(title) do {outl(YELLOW BOLD UNDERLINE << title << RESET)} while (0);

template<typename T>
static std::string	to_string_value(
	const T &_value
)
{
	std::ostringstream	oss;

	oss << std::boolalpha << _value;
	return (oss.str());
}

static void	record_result(
	const bool _ok,
	const std::string &_label,
	const std::string &_detail,
	int &_nb_tests,
	int &_total
)
{
	_total++;
	if (likely(_ok))
		_nb_tests++;
	outl((_ok ? GREEN "OK" RESET : RED "KO" RESET) << " " << _label << " " << _detail);
}

template<typename T>
static void	test_swap(
	const std::string &_label,
	T _a,
	T _b,
	const T &expected_a,
	const T &expected_b,
	int &_nb_tests,
	int &_total
)
{
	swap(&_a, &_b);
	record_result(
		(_a == expected_a && _b == expected_b),
		_label,
		"got (" + to_string_value(_a) + ", " + to_string_value(_b)
			+ ") expected (" + to_string_value(expected_a) + ", " + to_string_value(expected_b) + ")",
		_nb_tests,
		_total
	);
}

template<typename T>
static void	test_min(
	const std::string &_label,
	const T &_a,
	const T &_b,
	const T &_expected,
	int &_nb_tests,
	int &_total
)
{
	const T	result = ::min(_a, _b);

	record_result(
		(result == _expected),
		_label,
		"got " + to_string_value(result) + " expected " + to_string_value(_expected),
		_nb_tests,
		_total
	);
}

template<typename T>
static void	test_max(
	const std::string &_label,
	const T &_a,
	const T &_b,
	const T &_expected,
	int &_nb_tests,
	int &_total
)
{
	const T	result = ::max(_a, _b);

	record_result(
		(result == _expected),
		_label,
		"got " + to_string_value(result) + " expected " + to_string_value(_expected),
		_nb_tests,
		_total
	);
}

int	main(void)
{
	int		_total = 0;
	int		_nb_tests = 0;
	char	*_colors;

	{
		PART("swap");
		test_swap<int>("swap int #1", 1, 2, 2, 1, _nb_tests, _total);
		test_swap<int>("swap int #2", -5, 42, 42, -5, _nb_tests, _total);
		test_swap<double>("swap double", 1.5, -2.25, -2.25, 1.5, _nb_tests, _total);
		test_swap<char>("swap char", 'a', 'z', 'z', 'a', _nb_tests, _total);
		test_swap<bool>("swap bool", true, false, false, true, _nb_tests, _total);
		test_swap<std::string>("swap string", std::string("foo"), std::string("bar"), std::string("bar"), std::string("foo"), _nb_tests, _total);
		test_swap<long>("swap long", 1000000L, 2000000L, 2000000L, 1000000L, _nb_tests, _total);
		test_swap<unsigned>("swap unsigned", 0u, 99u, 99u, 0u, _nb_tests, _total);
		test_swap<short>("swap short", static_cast<short>(-1), static_cast<short>(7), static_cast<short>(7), static_cast<short>(-1), _nb_tests, _total);
	}

	{
		int	_x = 1;
		int	_y = 2;
		int	*_px = &_x;
		int	*_py = &_y;

		test_swap<int *>("swap pointer", _px, _py, &_y, &_x, _nb_tests, _total);
	}

	{
		PART("min");
		test_min<int>("min int #1", 1, 2, 1, _nb_tests, _total);
		test_min<int>("min int #2", -1, 5, -1, _nb_tests, _total);
		test_min<int>("min int equal", 7, 7, 7, _nb_tests, _total);
		test_min<double>("min double", 1.5, -2.5, -2.5, _nb_tests, _total);
		test_min<char>("min char", 'a', 'b', 'a', _nb_tests, _total);
		test_min<std::string>("min string", std::string("abc"), std::string("abd"), std::string("abc"), _nb_tests, _total);
		test_min<unsigned>("min unsigned", 0u, 42u, 0u, _nb_tests, _total);
		test_min<long>("min long", 100L, 50L, 50L, _nb_tests, _total);
		test_min<float>("min float", 3.14f, 3.13f, 3.13f, _nb_tests, _total);
		test_min<short>("min short", static_cast<short>(-10), static_cast<short>(-20), static_cast<short>(-20), _nb_tests, _total);
	}

	{
		PART("max");
		test_max<int>("max int #1", 1, 2, 2, _nb_tests, _total);
		test_max<int>("max int #2", -1, 5, 5, _nb_tests, _total);
		test_max<int>("max int equal", 7, 7, 7, _nb_tests, _total);
		test_max<double>("max double", 1.5, -2.5, 1.5, _nb_tests, _total);
		test_max<char>("max char", 'a', 'b', 'b', _nb_tests, _total);
		test_max<std::string>("max string", std::string("abc"), std::string("abd"), std::string("abd"), _nb_tests, _total);
		test_max<unsigned>("max unsigned", 0u, 42u, 42u, _nb_tests, _total);
		test_max<long>("max long", 100L, 50L, 100L, _nb_tests, _total);
		test_max<float>("max float", 3.14f, 3.13f, 3.14f, _nb_tests, _total);
		test_max<short>("max short", static_cast<short>(-10), static_cast<short>(-20), static_cast<short>(-10), _nb_tests, _total);
	}

	if (likely(_nb_tests == _total))
		_colors = GREEN;
	else if (!_total)
		_colors = RED;
	else
		_colors = YELLOW;


	outl(BOLD << "Result: " << _colors << _nb_tests << "/" << _total << RESET);
	return (_nb_tests == _total ? 0 : 1);
}
