#include "ScalarConverter.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

char   ScalarConverter::_char = 0;
int    ScalarConverter::_int = 0;
float  ScalarConverter::_float = 0;
double ScalarConverter::_double = 0;

ScalarConverter::ScalarConverter() {
}

ScalarConverter::ScalarConverter( const ScalarConverter & src )
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ScalarConverter::~ScalarConverter()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ScalarConverter					&ScalarConverter::operator=( ScalarConverter const &rhs )
{
	if ( this != &rhs )
	{
	}
	return (*this);
}

std::ostream					&operator<<( std::ostream &o, ScalarConverter const &i )
{
	//o << "Value = " << i.getValue();
	(void)i;
	return (o);
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void ScalarConverter::_convertChar( const std::string &str )
{
	_char = static_cast<char>(*str.begin());
	_int = static_cast<int>(_char);
	_float = static_cast<float>(_char);
	_double = static_cast<double>(_char);
}

void ScalarConverter::_convertInt( const std::string&str )
{
	_int = static_cast<int>(atoi(str.c_str()));
	_char = static_cast<char>(_int);
	_float = static_cast<float>(_int);
	_double = static_cast<double>(_int);
}

void ScalarConverter::_convertFloat( const std::string&str )
{
	_float = static_cast<float>(atof(str.c_str()));
	_char = static_cast<char>(_float);
	_int = static_cast<int>(_float);
	_double = static_cast<double>(_float);
}

void ScalarConverter::_convertDouble( const std::string&str )
{
	_double = static_cast<double>(atof(str.c_str()));
	_float = static_cast<float>(_double);
	_char = static_cast<char>(_double);
	_int = static_cast<int>(_double);
}

static bool isNumericValid( std::string str , std::string numberMap ) 
{
	bool	isNumeric;

	if (str[0] == '-' || str[0] == '+')
		str.erase(0, 1);
	isNumeric = !str.empty() && str.find_first_not_of(numberMap) == std::string::npos ;
	return (isNumeric);
}

static bool isFloatValid( std::string str ) 
{
	bool		isFloat;
	size_t		index = str.find("f");
	size_t		len = str.length();

	isFloat = str[len - 1] == 'f' && index == len - 1 && isNumericValid(str, "0123456789.f");
	return (isFloat);
}

static bool isDoubleValid( std::string str ) 
{
	bool		isFloat;
	size_t		index = str.find(".");
	size_t		len = str.length();

	isFloat = std::string::npos != index  && str[len - 1] != '.' && isNumericValid(str, "0123456789.");
	return (isFloat);
}

static bool isPeseudoLiterais( std::string str , std::string negInf, std::string posInf, std::string notNum )
{
	bool	isPeseudoLiteral;

	isPeseudoLiteral = !str.compare(negInf) || !str.compare(posInf) || !str.compare(notNum);
	return (isPeseudoLiteral);
}



void ScalarConverter::convert( std::string strConvert )
{
	long long int num = atoll(strConvert.c_str());

	if(strConvert.length() == 1 && isprint(strConvert[0]) && !isdigit(strConvert[0]))
	{
		std::cout << "CHAR" << std::endl;
		_convertChar(strConvert);
		std::cout << "char: " << _char << std::endl;
		std::cout << "int: " << _int << std::endl;
		std::cout << std::fixed << std::setprecision(2) << "float: " << _float << "f" << std::endl;
		std::cout << std::fixed << std::setprecision(2)<< "double: " << _double << std::endl;

	}
	else if (isNumericValid(strConvert, "0123456789") && num >= INT_MIN && num <= INT_MAX)
	{
		std::cout << "INT" << std::endl;
		_convertInt(strConvert);
		if (isprint(_char))
			std::cout << "char: " << _char << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
		std::cout << "int: " << _int << std::endl;
		std::cout << std::fixed << std::setprecision(2) << "float: " << _float << "f" << std::endl;
		std::cout << std::fixed << std::setprecision(2) << "double: " << _double << std::endl;
	}
	else if (isDoubleValid(strConvert) || isPeseudoLiterais(strConvert, "-inf", "+inf", "nan"))
	{
		_convertDouble(strConvert);

		if (isprint(_char))
			std::cout << "char: " << _char << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
		if (num >= INT_MIN && num <= INT_MAX)
			std::cout << "int: " << _int << std::endl;
		else
			std::cout << "int: " <<  "impossible" << std::endl;

		std::cout << std::fixed << std::setprecision(2) << "float: " << _float << "f" << std::endl;
		std::cout << std::fixed << std::setprecision(2) << "double: " << _double << std::endl;
		std::cout << "DOUBLE = " << strConvert << std::endl;
	}
	else if (isFloatValid(strConvert) || isPeseudoLiterais(strConvert, "-inff", "+inff", "nanf"))
	{
		_convertFloat(strConvert);
		if (isprint(_char))
			std::cout << "char: " << _char << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
		if (num >= INT_MIN && num <= INT_MAX)
			std::cout << "int: " << _int << std::endl;
		else
			std::cout << "int: " <<  "impossible" << std::endl;
		std::cout << std::fixed << std::setprecision(2) << "float: " << _float << "f" << std::endl;
		std::cout << std::fixed << std::setprecision(2) << "double: " << _double << std::endl;
	}
	else 
	{
		std::cout << "INVALID " << std::endl;
	}
	return;
}
// 2147483647
//  –2147483648 
/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */