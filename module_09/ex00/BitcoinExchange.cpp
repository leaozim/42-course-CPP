#include "BitcoinExchange.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

BitcoinExchange::BitcoinExchange() :  _dataMap(), _value(0.0), _date(""), _line("") { }

BitcoinExchange::BitcoinExchange( const BitcoinExchange & src ) {
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

BitcoinExchange::~BitcoinExchange() { }


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

BitcoinExchange &				BitcoinExchange::operator=( BitcoinExchange const & rhs )
{
	(void)rhs;
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

// ------------------------------- Validations ---------------------------------

void	BitcoinExchange::getCurrentDate( int& day, int& month, int& year )

{
	time_t	now; 
	tm*		currentDate;

	now = time(0);
	currentDate = localtime(&now);
	day = currentDate->tm_mday;
	month = currentDate->tm_mon + 1; 
	year = currentDate->tm_year + 1900;
}

bool	BitcoinExchange::isValidNumericFormat( const std::string& valueStr, std::string numberMap ) 
{
	if (valueStr.find_first_not_of(numberMap) != std::string::npos)
		return (false);
	return true;
}

bool	BitcoinExchange::isLeapYear( int year )
{
	return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

bool	BitcoinExchange::isValidDateFormat( const std::string& dateStr )
{
	if (dateStr.size() != 10 || dateStr[4] != '-' || dateStr[7] != '-')
		return false;
	return true;
}

bool	BitcoinExchange::isValidYear( int year )
{
	return (year >= 2008 && year <= 2023);
}

bool	BitcoinExchange::isValidMonth( int month )
{
	return (month >= 1 && month <= 12);
}

bool	BitcoinExchange::isValidDay( int day, int month, int year )
{
	bool	isLeap;
	int		maxDay;

	isLeap = isLeapYear(year);
	maxDay = (month == 2) ? (isLeap ? 29 : 28) : 31;
	return (day >= 1 && day <= maxDay);
}

int	BitcoinExchange::defineValue( const std::string& dateStr, int startPos, int length )
{
	std::string	valueStr;
	
	valueStr = dateStr.substr(startPos, length);
	if (!isValidNumericFormat(valueStr, "0123456789"))
		return 0;
	return  atoi(valueStr.c_str());
}

bool	BitcoinExchange::isValidChar( std::string tmp, std::string c )
{
	if (tmp != c)
		return (std::cout << BAD_INPUT << _line << std::endl, false);
	return (true);
}

bool BitcoinExchange::isValidValue( const std::string& line )
{
	std::string	valueStr;
	
	valueStr = line.substr(13, line.size() - _date.size());
	_value = atof(valueStr.c_str());
	if (!isValidNumericFormat(valueStr, "+-0123456789.") 
		|| ((valueStr[0] == '+' || valueStr[0] == '+') && valueStr.size() == 1))
		return (std::cout << BAD_INPUT << line << std::endl, false);
	if (_value < 0)
		return (std::cout << NEGATIVE_NUMBER << std::endl, false);
	if (_value > 1000)	
		return (std::cout << LARGE_NUMBER << std::endl, false);
	return(true);
}

bool BitcoinExchange::isValidDate( const std::string& line )
{
	int	year;
	int	month;
	int	day;
	int currentYear, currentMonth, currentDay;

	_date = line.substr(0, 10);
	year = defineValue(_date, 0, 4);
	month = defineValue(_date, 5, 2);
	day = defineValue(_date, 8, 2);
	getCurrentDate(currentDay, currentMonth, currentYear);
	if (!isValidDateFormat(_date))
		return (std::cout << BAD_INPUT << line << std::endl, false);
	if ((year == 2009) && (month == 1) && (day == 1))
		return (std::cout << OLD_DATE << std::endl, false);
	if (!isValidYear(year) || !isValidMonth(month) || !isValidDay(day, month, year))
		return (std::cout << BAD_INPUT << line << std::endl, false);
	if (year > currentYear || (year == currentYear && month > currentMonth) 
	|| (year == currentYear && month == currentMonth && day > currentDay))
		return (std::cout  << FUTURE_DATE << std::endl, false);
	return true;
}

bool BitcoinExchange::checkValidDateBaseFormat( const std::string &line  )
{
	std::string	tmp;

	if (!isValidDate(line))
		return (false);
	tmp = line.substr(10, 1);
	if (!isValidChar(tmp, " ") == 1)
		return (false);
	tmp = line.substr(11, 1);
	if (!isValidChar(tmp, "|") == 1)
		return (false);
	tmp = line.substr(12, 1);
	if (!isValidChar(tmp, " ") == 1)
		return (false);
	if 	(!isValidValue(line))
		return (false);
	return (true);
}

bool	BitcoinExchange::checkArguments( int argc, char **file )
{
	if (argc != 2)
		return (std::cout << ERROR_ARGC << std::endl, false);
	if (access(file[1], R_OK) != 0)
		return (std::cout << ERROR_FILE << std::endl, false);
	return (true);
}

// --------------------------------- Exchange ----------------------------------


void	BitcoinExchange::getInputFile( std::string file ) 
{
	std::map<std::string, float>::iterator	it;
	std::string								key;
	float									result;

	std::ifstream imputFile(file.c_str());
	std::getline(imputFile, _line, '\n');
	while (std::getline(imputFile, _line, '\n'))
	{
		if (_line.empty())
			std::cout << EMPTY_LINE << std::endl;
		else if (checkValidDateBaseFormat(_line))
		{
			it = _dataMap.upper_bound(_date);
			it--;
			result = _value * (*it).second;
			std::cout << BLUE << _date << RES 
					  << " => " 
					  << _value 
					  << " = " 
					  << result 
					  << std::endl;
		}
	}
}

void BitcoinExchange::getBitcoinPriceOverTime( void ) 
{
	std::string		key;
	std::string		value;
	std::string		line;
	
	std::ifstream imputFile("data.csv");
	if (!imputFile.is_open())
		std::cout << ERROR_FILE << std::endl;
	while (std::getline(imputFile, key, ',') && std::getline(imputFile, value, '\n'))
		this->_dataMap[key] = atof(value.c_str());;
}

int			BitcoinExchange::exchange( int argc, char **file )
{
	if (!checkArguments(argc, file))
		return (1);
	getBitcoinPriceOverTime();
	getInputFile(file[1]);
	return (0);
}

/* ************************************************************************** */