#include "PmergeMe.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PmergeMe::PmergeMe() : stack() { }

PmergeMe::PmergeMe( const PmergeMe & src ){ 
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

PmergeMe::~PmergeMe() { }


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

PmergeMe &				PmergeMe::operator=( PmergeMe const & rhs )
{
	if ( this != &rhs )
	{
	}
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

bool	PmergeMe::isValidExpressionFormat( const std::string& valueStr, std::string numberMap ) 
{
	if (valueStr.find_first_not_of(numberMap) != std::string::npos)
		return (false);
	return true;
}

bool	PmergeMe::checkArguments( int argc, std::string input)
{
	std::cout << input << std::endl;

	if (argc != 2)
		return (std::cout << ERROR_ARGC << std::endl, false);
	if (!isValidExpressionFormat(input, "0123456789+-/* "))
		return (std::cout << BAD_INPUT << std::endl, false);
	return (true);
}

bool isOperator(const std::string& str) {
	return (str.size() == 1 && (str[0] == '-' || str[0] == '+' || str[0] == '*' || str[0] == '/'));
}

float operation(float a, float b, char x){
	switch(x)
	{
		case '+':
			return a + b;
		case '-':
			return a - b;
		case '/':
			return a / b;
		case '*':
			return a * b;
		default:
			return 0;
	}
}


int			PmergeMe::invertedPolish( int argc, std::string input )
{
	if (!check_arguments(argc, input))
		return (1);

	std::istringstream	iss(input);
	std::string			strToken;
	int				token;
	int				n1, n2, result;
	int controlOperando = 0;
	 int controlNumber = 0;

	while (std::getline(iss, strToken, ' '))
	{
		if (strToken.empty()) 
			continue;
		if (isOperator(strToken) && stack.size() >= 2) {
			n1 = stack.top();
			stack.pop();
			n2 = stack.top();
			stack.pop();
			result = operation(n2, n1, strToken[0]);
			stack.push(result);
			controlOperando++;
		} else {
			token = std::atof(strToken.c_str());
			if (token > 10 || token < 0) 
				return (std::cout << BAD_INPUT << std::endl, 0);
			stack.push(token);
			controlNumber++;
		}
	}
	if (controlOperando == controlNumber - 1 && controlNumber >= 2 && stack.size() == 1) 
    	std::cout << "result " << stack.top() << std::endl;
	else 
		std::cout << "Invalid expression" << std::endl;
	return (0);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */