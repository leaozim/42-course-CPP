#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <unistd.h>
#include <iostream>
#include <map>
#include  <stdlib.h>
#include <ctime>


# define MAGENTA "\033[35m"
# define RED "\x1b[38;5;88m"
# define GREEN "\x1b[38;5;40m"
# define BLUE "\x1b[38;5;25m"
# define YELLOW "\x1b[38;5;220m"
# define ORANGE	"\033[0;38;5;166m"
# define LIGHT_PURPLE "\033[1;35m"
# define CYAN "\001\e[0;36m\002"
# define RES "\x1b[0m"
# define BAD_INPUT RED "Error: bad input => " RES
# define OLD_DATE RED "Error: bitcoin mining emerged from 2009/03/01." RES
# define FUTURE_DATE RED "Error: the date is in the future." RES
# define ERROR_ARGC RED "Error: invalid number of arguments!" RES
# define ERROR_FILE RED "Error: could not open file." RES
# define NEGATIVE_NUMBER RED "Error: not a positive number." RES
# define LARGE_NUMBER RED "Error: too large a number." RES
# define EMPTY_LINE RED "Error: empty line." RES

class BitcoinExchange
{

	public:

		BitcoinExchange();
		BitcoinExchange( std::string txtFile );
		BitcoinExchange( BitcoinExchange const & src );
		~BitcoinExchange();
		BitcoinExchange		&operator=( BitcoinExchange const & rhs );

		bool				check_arguments( int argc, char **file );
		int					exchange( int argc, char **file );
		void				getBitcoinPriceOverTime( void ) ;
		void				getInputFile( std::string file ) ;
		void				getCurrentDate( int& day, int& month, int& year );
		int					defineValue( const std::string& dateStr, int startPos, int length );
		bool				checkValidDateBaseFormat( const std::string& line );
		bool				isValidValue( const std::string& valueStr );
		bool				isValidNumericFormat( const std::string& valueStr, std::string numberMap );
		bool				isValidChar( std::string tmp, std::string c );
		bool				isValidDate( const std::string& dateStr );
		bool				isLeapYear( int year );
		bool				isValidDateFormat( const std::string& dateStr );
		bool				isValidYear( int year );
		bool				isValidMonth(int month);
		bool				isValidDay( int day, int month, int year );	

	private:
		std::map<std::string, float>	_dataMap;
		float							_value;
		std::string						_date;
		std::string						_line;



};

std::ostream &			operator<<( std::ostream & o, BitcoinExchange const & i );

#endif /* ************************************************* BITCOINEXCHANGE_H */