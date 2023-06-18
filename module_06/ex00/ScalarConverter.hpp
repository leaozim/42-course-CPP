#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <climits>

class ScalarConverter
{

	public:

		ScalarConverter();
		ScalarConverter( ScalarConverter const & src );
		~ScalarConverter();

		ScalarConverter &		operator=( ScalarConverter const & rhs );


		void					convert( std::string arg );
	
	private:

		void					_convertChar( const std::string &str );
		void					_convertInt( const std::string  &str );
		void					_convertFloat( const std::string&str );
		void					_convertDouble( const std::string&str );


		static char				_char;
		static int				_int;
		static float			_float;
		static double			_double;

};

std::ostream &			operator<<( std::ostream & o, ScalarConverter const & i );

#endif /* ************************************************* SCALARCONVERTER_H */