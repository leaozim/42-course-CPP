#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <climits>
#include <sstream>

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