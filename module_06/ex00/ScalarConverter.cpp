#include "ScalarConverter.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ScalarConverter::ScalarConverter() { }

ScalarConverter::ScalarConverter( const ScalarConverter & src ) { *this = src; }


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ScalarConverter::~ScalarConverter(){ }


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ScalarConverter			&ScalarConverter::operator=( ScalarConverter const &rhs )
{
	if ( this != &rhs )	{
	}
	return (*this);
}


/*
** --------------------------------- METHODS ----------------------------------
*/

bool		ScalarConverter::_isNumericValid( std::string str , std::string numberMap ) 
{
	bool	isNumeric;
	size_t pos = str.find(".");
	size_t count = 0;
	
	if (str[0] == '-' || str[0] == '+')
		str.erase(0, 1);
	for (count = 0; pos != std::string::npos; count++)
		pos = str.find(".", pos + 1);
	if (count > 1)
		return (isNumeric = false, isNumeric);
	isNumeric = !str.empty() && str.find_first_not_of(numberMap) == std::string::npos ;
	return (isNumeric);
}

bool		ScalarConverter::_isFloatValid( std::string str ) 
{
	bool		isFloat;
	size_t		index = str.find("f");
	size_t		len = str.length();

	isFloat = str[len - 1] == 'f' && index == len - 1 && _isNumericValid(str, "0123456789.f");
	return (isFloat);
}

bool		ScalarConverter::_isDoubleValid( std::string str ) 
{
	bool		isFloat;
	size_t		index = str.find(".");

	isFloat = std::string::npos != index && _isNumericValid(str, "0123456789.");
	return (isFloat);
}

static bool		isPeseudoLiterais( std::string str , std::string negInf, 
								   std::string posInf, std::string notNum )
{
	bool	isPeseudoLiteral;

	isPeseudoLiteral = !str.compare(negInf) || !str.compare(posInf) || !str.compare(notNum);
	return (isPeseudoLiteral);
}

void		ScalarConverter::_print( long long num, dataType &type )
{
	if (!isascii(type._int))
		std::cout << "char: impossible" << std::endl;
	else if (isprint(type._char))
		std::cout << "char: " << type._char  << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	if (num >= INT_MIN && num <= INT_MAX && 
		!(std::isnan(type._float) || std::isnan(type._double) || std::isinf(type._float) || std::isinf(type._double)))
		std::cout << "int: " << type._int << std::endl;
	else
		std::cout << "int: " <<  "impossible" << std::endl;
	std::cout.precision(2); std::cout << std::fixed << "float: " << type._float << "f" << std::endl;
	std::cout.precision(2); std::cout << std::fixed << "double: " << type._double << std::endl;
}

void		ScalarConverter::_printImpossible( void )
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

void ScalarConverter::_convertChar( const std::string &str, dataType &type )
{
	type._char = static_cast<char>(*str.begin());
	type._int = static_cast<int>(type._char);
	type._float = static_cast<float>(type._char);
	type._double = static_cast<double>(type._char);
}

void ScalarConverter::_convertInt( const std::string&str, dataType &type )
{
	type._int = static_cast<int>(atoi(str.c_str()));
	type._char = static_cast<char>(type._int);
	type._float = static_cast<float>(type._int);
	type._double = static_cast<double>(type._int);
}

void ScalarConverter::_convertFloat( const std::string&str, dataType &type )
{
	type._float  = static_cast<float>(atof(str.c_str()));
	type._char = static_cast<char>(type._float);
	type._int = static_cast<int>(type._float);
	type._double = static_cast<double>(type._float);
}

void ScalarConverter::_convertDouble( const std::string&str, dataType &type )
{
	type._double = static_cast<double>(atof(str.c_str()));
	type._float = static_cast<float>(type._double);
	type._char = static_cast<char>(type._double);
	type._int = static_cast<int>(type._double);
}

void ScalarConverter::convert( std::string input )
{
	dataType	type = {0, 0, 0.0f, 0.0};
	long long	num = atoll(input.c_str());

	if(input.length() == 1 && isprint(input[0]) && !isdigit(input[0])) {
		_convertChar(input, type);
		_print(num, type);
	}
	else if (_isNumericValid(input, "0123456789") && num >= INT_MIN && num <= INT_MAX) {
		_convertInt(input, type);
		_print(num, type);
	}
	else if (_isDoubleValid(input) || isPeseudoLiterais(input, "-inf", "+inf", "nan")) {
		_convertDouble(input, type);
		_print(num, type);
	}
	else if (_isFloatValid(input) || isPeseudoLiterais(input, "-inff", "+inff", "nanf")) {
		_convertFloat(input, type);
		_print(num, type);
	}
	else 
		_printImpossible();
}

/* ************************************************************************** */