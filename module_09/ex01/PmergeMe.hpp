#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <stack> 
#include <cstdlib>


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
# define BAD_INPUT RED "Error: invalid input. " RES


class PmergeMe
{

	public:

		PmergeMe();
		PmergeMe( PmergeMe const & src );
		~PmergeMe();

		PmergeMe &		operator=( PmergeMe const & rhs );

		int			invertedPolish( int argc, std::string input );
		bool		check_arguments( int argc, std::string input );

		bool		isValidExpressionFormat( const std::string& valueStr, std::string numberMap );
	private:

		std::stack< int>	stack;


	private:

};

std::ostream &			operator<<( std::ostream & o, PmergeMe const & i );

#endif /* ******************************************************** PMERGEME_H */