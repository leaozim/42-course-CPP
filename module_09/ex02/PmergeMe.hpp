#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
#include <cstring>
#include <list>
#include <deque>
#include <cstdlib>
#include <algorithm>
#include <sys/time.h>
#include <iomanip>

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

		int				fjmi_sort( int argc, char **input );
		bool			checkArguments( int argc, char **input );
		void			fillDeque( int argc, char **input );
		void			inputSequenceIsOdd( void );
		bool 			isValidInput( char** input );
		void 			insertToMainChain();
		void			createMainChainAndPend();
		void			generatPositions();
		int				jacobsthal(int n);
		void 			generateJacobInsertionSequence();
		void			sortPairs();
		void			createListOrder();
		void			createPairs();
		void			mergeSort(int begin, int end);
		void			merge(std::deque<std::pair<int, int> >& pairs, int begin, int mid, int end);
void	printTimeToProcess(void);
long int	elapsedTime(struct timeval start, struct timeval end);
void		sortDeque( int argc, char **input );
void	printUnsorted(char **argv);
void	printSorted(void);

	
	private:
		std::deque<int> 					_inputSequence;
	  	std::deque<int>						_mainChain;
        std::deque<int> 					_pend;
		std::deque<int> 					_jacobSequence;
		std::deque<int> 					_positions;
		std::deque<std::pair<int, int> >	_pairs;
		int 								_straggler;
		bool								_hasStraggler;
		struct timeval						_startVec;
		struct timeval						_endVec;
		struct timeval						_startDeq;
		struct timeval						_endDeq;



};

std::ostream &			operator<<( std::ostream & o, PmergeMe const & i );

#endif /* ******************************************************** PMERGEME_H */