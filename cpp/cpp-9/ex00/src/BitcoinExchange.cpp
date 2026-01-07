#include "BitcoinExchange.hpp"

bool	is_integer(
	const std::string &s
)
{
	char	*_end;

	std::strtol(s.c_str(), &_end, 10);

	return (*_end == '\0');
}

bool	is_valid_sep(
	const std::string &_target
)
{
	return (_target.compare(10, 3, " | "));
}

static inline bool	is_date(
	const std::string &_str
)
{
	if (_str.size() != 10)
		return (false);

	return (std::isdigit(_str[0]) &&
			std::isdigit(_str[1]) &&
			std::isdigit(_str[2]) &&
			std::isdigit(_str[3]) &&
			_str[4] == '-' &&
			std::isdigit(_str[5]) &&
			std::isdigit(_str[6]) &&
			_str[7] == '-' &&
			std::isdigit(_str[8]) &&
			std::isdigit(_str[9]));
}

int	loadDB(
	std::map<std::string, float> &_map,
	std::ifstream &_db
)
{
	std::string	_header;
	std::string	_buff;
	std::string	_date;
	char		*_end;
	float		_value;
	int			_nb_lines = 0;
	int			_nb_errors = 0;

	_header = all::gnl(_db);
	all::trim(_header);
	if (unlikely(_header.empty() || _header != "date,exchange_rate"))
		return (1);
	
	while (!_db.eof())
	{
		_buff = all::gnl(_db);
		all::trim(_buff);
		_nb_lines++;

		if (unlikely(_buff.empty() && _db.eof()))
			break ;

		_date = _buff.substr(0, 10);
		if (unlikely(!is_date(_date)))
		{
			std::cerr << RED "Error: " RESET "invalid date on line " << _nb_lines << std::endl;
			_nb_errors++;
			continue ;
		}
		_value = std::strtof(_buff.substr(11).c_str(), &_end);
		if (unlikely(*_end))
		{
			std::cerr << RED "Error: " RESET "invalid interger (" << *_end << ") on line " << _nb_lines << std::endl;
			_nb_errors++;
			continue ;
		}

		_map[_date] = _value;
	}
	return (_nb_errors);
}

float	getValueByDate(
	const std::map<std::string, float> &_map,
	const std::string &_date
)
{
	std::map<std::string, float>::const_iterator	_it = _map.find(_date);

	if (likely(_it != _map.end()))
		return (_it->second);
	else
		return (_map.lower_bound(_date)->second);
}

int	BitcoinExchange(
	const std::map<std::string, float> &_map,
	std::ifstream &_file
)
{
	std::string	_header;
	std::string	_buff;
	std::string	_date;
	char		*_end;
	float		_value;
	int			_nb_lines = 0;
	int			_nb_errors = 0;

	_header = all::gnl(_file);
	all::trim(_header);
	if (unlikely(_header.empty() || _header != "date|value"))
		return (1);
	
	while (!_file.eof())
	{
		_buff = all::gnl(_file);
		all::trim(_buff);
		_nb_lines++;

		if (unlikely(!_buff.size() && _file.eof()))
			break ;

		// outl("buff(" << _nb_lines <<") " << _buff << " '" << static_cast<char>(_buff[10]) << "'")
		_date = _buff.substr(0, 10);
		if (unlikely(!is_date(_date)))
		{
			std::cerr << RED "Error: " RESET "invalid date on line " << _nb_lines << std::endl;
			_nb_errors++;
			continue ;
		}

		if (unlikely(_buff[10] != '|'))
		{
			std::cerr << RED "Error: " RESET "invalid separator on line " << _nb_lines << std::endl;
			_nb_errors++;
			continue ;
		}

		_value = std::strtof(_buff.substr(11).c_str(), &_end);
		if (unlikely(*_end || _value > 1000 || _value < 0))
		{
			std::cerr << RED "Error: " RESET "invalid interger on line " << _nb_lines << std::endl;
			_nb_errors++;
			continue ;
		}

		// std::map<std::string, float>::const_iterator	_it = _map.find(_date);
		outl(BLUE << _date << RESET
				" => " YELLOW << _value << RESET
				" = " GREEN << getValueByDate(_map, _date) * _value << RESET);
	}
	return (!_nb_errors && !_map.empty());
}