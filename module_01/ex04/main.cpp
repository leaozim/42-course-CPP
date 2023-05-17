#include "defines.h"

int	replace(std::string file, std::string s1, std::string s2)
{
	std::ifstream	ifs;
	std::ofstream	ofs;
	size_t			index;
	std::string		outFile;

	ifs.open(file.c_str());
	if(!ifs.is_open())
		return (ERROR_FILE);
	outFile = file + ".replace";
	ofs.open(outFile.c_str());
	if (ofs.fail())
		return (ERROR_WRITE);
	while (ifs.good())
	{
		std::getline(ifs, file);
		while (file.find(s1) != std::string::npos)
		{
			index = file.find(s1);
			if (index < file.length())
			{
				file.erase(index, s1.length());
				file.insert(index, s2);
			}
		}
		ofs << file << std::endl;
	}
	return (0);
}

int	main(int argc, char **argv) 
{
	int	status;

	if (argc != 4)
		return (1);
	status = replace(argv[1], argv[2], argv[3]);
	if (status == ERROR_FILE)
		std::cout << OPEN_FILE << std::endl;
	else if (status == ERROR_WRITE)
		std::cout << WRITE_FILE << std::endl;
	else
		std::cout << SUCCESS << std::endl;
	return (0);
}
