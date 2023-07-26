#include "RPN.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

RPN::RPN() : _stack(), _divByZero(false) { }

RPN::RPN( const RPN & src ){ 
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

RPN::~RPN() { }


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

RPN &				RPN::operator=( RPN const & rhs )
{
	(void)rhs;
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

bool		RPN::isValidExpressionFormat( const std::string& valueStr, std::string numberMap ) 
{
	if (valueStr.find_first_not_of(numberMap) != std::string::npos)
		return (false);
	return true;
}

bool		RPN::checkArguments( int argc, char **input )
{
	if (argc != 2)
		return (std::cout << ERROR_ARGC << std::endl, false);
	if (!isValidExpressionFormat(input[1], "0123456789+-/* "))
		return (std::cout << BAD_INPUT << std::endl, false);
	return (true);
}

bool		RPN::isOperator(const std::string& str) {
	return (str.size() == 1 && (str[0] == '-' || str[0] == '+' || str[0] == '*' || str[0] == '/'));
}

void 	RPN::endResultOfExpression( int quantityOfOperators, int  quantityOfNumbers )
{
	if (quantityOfOperators == quantityOfNumbers - 1 && 
		quantityOfNumbers >= 2 &&
		_stack.size() == 1 &&
		_divByZero == false) 
		std::cout << _stack.top() << std::endl;
	else 
		std::cout << BAD_INPUT << std::endl;
	
}

bool			RPN::addTokenToStack( std::string strToken )
{
	int	token;

	token = std::atof(strToken.c_str());
	if (token > 9 || token < 0) 
		return (false);
	_stack.push(token);
	return (true);
}

float		RPN::operation(float a, float b, char mathOperator)
{
	switch(mathOperator)
	{
		case '+':
			return a + b;
		case '-':
			return a - b;
		case '*':
			return a * b;
		case '/':
			if (b == 0)
				_divByZero = true;
			return a / b;
		default:
			return 0;
	}
}

int 		RPN::executeMathOperation(char mathOperator)
{
	int					n1, n2, result;

	n1 = _stack.top();
	_stack.pop();
	n2 = _stack.top();
	_stack.pop();
	result = operation(n2, n1, mathOperator);
	_stack.push(result);
	return (0);
}

int			RPN::mathematicalOperationInvertedPolish( std::string input )
{
	std::istringstream	iss(input);
	std::string			strToken;
	int 				quantityOfOperators = 0;
	int 				quantityOfNumbers = 0;

	while (std::getline(iss, strToken, ' '))
	{
		if (strToken.empty()) 
			continue;
		if (isOperator(strToken) && _stack.size() >= 2) {
			if (executeMathOperation(strToken[0]))
				return (std::cout << BAD_INPUT << std::endl, 1);
			quantityOfOperators++;
		} 
		else 
		{
			if (!addTokenToStack(strToken))
				return (std::cout << BAD_INPUT << std::endl, 1);
			quantityOfNumbers++;
		}
	}
	endResultOfExpression(quantityOfOperators, quantityOfNumbers);
	return (0);
}

int			RPN::invertedPolish( int argc, char **input )
{
	if (!checkArguments(argc, input))
		return (1);
	if (!mathematicalOperationInvertedPolish(input[1]))
		return (1);
	return (0);
}


/* ************************************************************************** */