#include <iostream>
#include <string>
#define RED "\x1b[38;5;88m"
#define RES "\x1b[0m"

int	main( void ) {
	std::string	string =  "HI THIS IS BRAIN";
	std::string	*stringPTR = &string;
	std::string	&stringREF = string;

	std::cout 
			<< RED << "• The memory address of the string variable: " << RES << &string << std::endl
			<< RED << "• The memory address held by stringPTR: " << RES << &stringPTR << std::endl
			<< RED << "• The memory address held by stringREF: " << RES << &stringREF << std::endl;
	std::cout << std::endl
			 << RED << "• The value of the string variable: " << RES  << string << std::endl
			 << RED << "• The value pointed to by stringPTR: " << RES  << *stringPTR << std::endl
			 << RED << "• The value pointed to by stringREF: " << RES  << stringREF << std::endl;
	return (0);
}
