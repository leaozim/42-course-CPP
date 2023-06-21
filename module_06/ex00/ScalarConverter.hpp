#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <climits>
#include <sstream>

#define MAGENTA "\033[35m"
#define RED "\x1b[38;5;88m"
#define GREEN "\x1b[38;5;40m"
#define BLUE "\x1b[38;5;25m"
#define YELLOW "\x1b[38;5;220m"
#define ORANGE	"\033[0;38;5;166m"
#define LIGHT_PURPLE "\033[1;35m"
#define CYAN "\001\e[0;36m\002"
#define RES "\x1b[0m"

struct dataType 
{
	char		_char;
	int			_int;
	float		_float;
	double		_double;
};
class ScalarConverter
{

	public:
		static void					convert( std::string arg );
	
	private:
		ScalarConverter();
		ScalarConverter( ScalarConverter const & src );
		~ScalarConverter();
		ScalarConverter		&operator=( ScalarConverter const & rhs );

		static void			_convertChar( const std::string &str, dataType &type );
		static void			_convertInt( const std::string  &str, dataType &type );
		static void			_convertFloat( const std::string&str, dataType &type );
		static void			_convertDouble( const std::string&str, dataType &type );
		static void			_print( long long num, dataType &type );
		static void			_printImpossible( void );
		static bool			_isDoubleValid( std::string str );
		static bool			_isFloatValid( std::string str );
		static bool			_isNumericValid( std::string str , std::string numberMap );


};


#endif /* ************************************************* SCALARCONVERTER_H */