#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <sstream>
#include <stack> 
#include <cstdlib>
#include <cctype>

# define MAGENTA "\033[35m"
# define RED "\x1b[38;5;88m"
# define GREEN "\x1b[38;5;40m"
# define BLUE "\x1b[38;5;25m"
# define YELLOW "\x1b[38;5;220m"
# define ORANGE	"\033[0;38;5;166m"
# define LIGHT_PURPLE "\033[1;35m"
# define CYAN "\001\e[0;36m\002"
# define RES "\x1b[0m"
# define ERROR_ARGC RED "Error: invalid number of arguments!" RES
# define BAD_INPUT RED "Error" RES


class RPN
{

	public:

		RPN();
		RPN( RPN const & src );
		~RPN();

		RPN &		operator=( RPN const & rhs );

		int			invertedPolish( int argc, char **input );
		bool		checkArguments( int argc, char **input );
		bool		isValidExpressionFormat( const std::string& valueStr, std::string numberMap );
		int			mathematicalOperationInvertedPolish( std::string input );
		float		operation( float a, float b, char mathOperator );

		bool		isOperator( const std::string& str );
		int 		executeMathOperation( char mathOperator );
		bool		addTokenToStack( std::string strToken );
		void 		endResultOfExpression( int quantityOfOperators, int  quantityOfNumbers );

	private:

		std::stack<int>	_stack;
		bool			_divByZero;

};


#endif /* ******************************************************** RPN_H */