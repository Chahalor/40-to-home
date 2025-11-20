#include <iostream>
#include <fstream>
#include <string>

#include "all.hpp"

void	des(
	std::ifstream &_inFile,
	std::ofstream &_outFile,
	const std::string &_target,
	const std::string &_replace
)
{
	std::string	_line;

	while (std::getline(_inFile, _line))
	{
		size_t			pos = 0;
		register size_t	i = 0;

		if (likely(!_inFile.eof()))
			_line.push_back('\n');

		pos = _line.find(_target);
		if (pos == std::string::npos)
		{
			_outFile.write(_line.c_str(), _line.size());
			continue;
		}
		_line.erase(pos, _target.length());
		while (i < _replace.length())
		{
			_line.insert(pos + i, 1, _replace[i]);
			i++;
		}
		_outFile.write(_line.c_str(), _line.size());
	}
}

int	main(int argc, const char *argv[])
{
	if (argc != 4)
	{
		std::cerr << "wrong args numbers. " << argv[0] << " <filename> <string 1> <string 2>" << std::endl;
		return (1);
	}

	std::string	_target(argv[2]);
	std::string	_replace(argv[3]);
	std::string	line;

	if (unlikely(_target.empty() || _replace.empty()))
	{
		std::cerr << "string 1 or string 2 must not be empty" << std::endl;
		return (1);
	}
	
	std::ifstream	in_file(argv[1]);
	if (unlikely(!in_file.is_open()))
		return (std::perror((std::string("failed to open: ") + std::string(argv[1])).c_str()), 1);

	std::ofstream	_outFile((std::string(argv[1]) + ".replace").c_str());
	if (unlikely(!_outFile.is_open()))
	{
		in_file.close();
		return (std::perror("failed to open _outFile"), 1);
	}

	des(in_file, _outFile, _target, _replace);

	in_file.close();
	_outFile.close();
	return (0);
}
