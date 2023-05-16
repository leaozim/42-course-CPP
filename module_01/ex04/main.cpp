#include <iostream>
#include <fstream>


int	main(int argc, char **argv) 
{
	std::cout <<  argc << std::endl;
	if (argc != 4)
		return (1);
	std::ifstream	file;
	file.open(argv[1]);
	if(!file.is_open())
	{
		std::cout <<  "Error opening file!" << std::endl;
		return (2);
	}
	std::cout <<  "assou" << std::endl;
	return (0);
}