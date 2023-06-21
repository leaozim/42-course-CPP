#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

#define MAGENTA "\033[35m"
#define RED "\x1b[38;5;88m"
#define GREEN "\x1b[38;5;40m"
#define BLUE "\x1b[38;5;25m"
#define YELLOW "\x1b[38;5;220m"
#define ORANGE	"\033[0;38;5;166m"
#define LIGHT_PURPLE "\033[1;35m"
#define CYAN "\001\e[0;36m\002"
#define RES "\x1b[0m"

/*
** --------------------------------- METHODS ----------------------------------
*/

template <typename T>
void	iter( T const *array, size_t lenArray, void (*func)(T const &) )
{
	if (!array || !func )
		return ;
	for(size_t i = 0; i < lenArray; i++)
		func(array[i]);
}

template <typename T>
void	iter( T *array, size_t lenArray, void (*func)(T &) )
{
	if (!array || !func )
		return ;
	for(size_t i = 0; i < lenArray; i++)
		func(array[i]);
}

/*
** ---------------------------------- UTEIS ------------------------------------
*/

template<typename T>
void	printValue( const T &value )
{
	std::cout << value << " ";
};

void	printNumber( const float &value )
{
	std::cout.precision(2); std::cout << std::fixed << value << "f ";
}

void	printNumber( double &value )
{
	std::cout.precision(2); std::cout << std::fixed << value << " ";
}

void	upperCase( std::string &str )
{
	for (int i = 0; str[i]; i++)
		str[i] = std::toupper(str[i]);
	printValue(str);
}

template<typename T>
void	upperCase( T &str )
{
	(void)str;
	std::cout << "error: type incompatible with function. \n";
}

template<typename T>
void	lowerCase( T &str )
{
	(void)str;
	std::cout << "error: type incompatible with function. \n";
}

template<>
void	lowerCase( std::string &str )
{
	for (int i = 0; str[i]; i++)
		str[i] = std::tolower(str[i]);
}

void print_separator( void )
{
	std::cout << std::endl << CYAN << std::string(40, '-') << RES << std::endl;
}

void print_header( std::string str, char marker )
{
	std::cout << std::endl << 
			  std::string(40, marker) << std::endl
			  << BLUE << str << RES
			  << std::endl
			  << std::string(40, marker) << std::endl;
}

#endif /* ******************************************************** ITER	_H */