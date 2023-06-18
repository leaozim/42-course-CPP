#include "ScalarConverter.hpp"

int main( int argc, char **argv )
{
	ScalarConverter string;

	if (argc != 2)
		return (std::cout <<  "Invalid number of arguments!" << std::endl, 1);
	string.convert(argv[1]);
}