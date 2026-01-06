#include "BitcoinExchange.hpp"

int	LoadDB(
	std::map<std::string, int> &_map,
	std::ifstream _db
)
{
	std::string	_header;

	_db.getline(_db, _header);
}