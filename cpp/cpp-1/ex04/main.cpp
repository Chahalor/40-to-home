#include <iostream>
#include <fstream>
#include <string>

#include "all.hpp"

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
		return (std::perror("failed to open in_file"), 1);

	std::ofstream	out_file((std::string(argv[1]) + ".replace").c_str());
	if (unlikely(!out_file.is_open()))
	{
		in_file.close();
		return (std::perror("failed to open out_file"), 1);
	}

	while (std::getline(in_file, line))
	{
		size_t			pos = 0;
		register size_t	i = 0;

		if (likely(!in_file.eof()))
			line.push_back('\n');

		pos = line.find(_target);
		if (pos == std::string::npos)
		{
			out_file.write(line.c_str(), line.size());
			continue;
		}
		line.erase(pos, _target.length());
		while (i < _replace.length())
		{
			line.insert(pos + i, 1, _replace[i]);
			i++;
		}
		out_file.write(line.c_str(), line.size());
	}

	in_file.close();
	out_file.close();
	return (0);
}
