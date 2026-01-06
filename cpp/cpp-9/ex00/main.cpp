#include "BitcoinExchange.hpp"

int	main(const int argc, const char *argv[])
{
	std::string					_filename;
	std::ifstream				_file;
	std::ifstream				_db;
	std::map<std::string, int>	_map;

	if (argc != 2)
	{
		std::cerr << "usage: " << argv[1] << " <filename>" << std::endl;
		return (EXIT_FAILURE);
	}
	else
		_filename = argv[1];

	_db.open("data.csv");
	if (unlikely(!_db.is_open()))
	{
		std::perror("cannot find data.csv");
		return (EXIT_FAILURE);
	}

	_file.open(_filename);
	if (unlikely(!_file.is_open()))
	{
		_db.close();
		std::perror("invalid file");
		return (EXIT_FAILURE);
	}

	_map.insert({"key", 10})


}