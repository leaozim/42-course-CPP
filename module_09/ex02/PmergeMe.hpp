#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
#include <cstring>
#include <list>
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
# define BAD_INPUT RED "Error" RES

class PmergeMe
{

	public:

		PmergeMe();
		PmergeMe( PmergeMe const & src );
		~PmergeMe();

		PmergeMe &		operator=( PmergeMe const & rhs );

		int			fjmi_sort( int argc, char **input );
		bool		checkArguments( int argc, char **input );
		// bool		isValidExpressionFormat( const std::string& valueStr, std::string numberMap );
		bool 		isValidInput( char** input );

	private:
	  	std::list<int> mainChain;
        std::list<int> pend;

};

std::ostream &			operator<<( std::ostream & o, PmergeMe const & i );

#endif /* ******************************************************** PMERGEME_H */