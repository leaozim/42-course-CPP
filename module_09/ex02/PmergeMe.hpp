#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
#include <cstring>
#include <deque>
#include <vector>
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

		PmergeMe( void );
		PmergeMe( PmergeMe const & src );
		~PmergeMe( void );

		PmergeMe &		operator=( PmergeMe const & rhs );

		int				fjmi_sort( int argc, char **input );
		bool			checkArguments( int argc, char **input );
		void			printUnsorted(char **argv);
		void			printSorted( void );
		bool 			isValidInput( char** input );
		void			printTimeToProcess(void);

		void			fillDeque( int argc, char **input );
		void			inputSequenceIsOdd( void );
		void 			insertToMainChain( void );
		void			createMainChainAndPend( void );
		void			generatPositions( void );
		int				jacobsthal(int n);
		void 			generateJacobInsertionSequence( void );
		void			sortPairs( void );
		void			createListOrder( void );
		void			createPairs( void );
		void			mergeSort(int begin, int end);
		void			merge( std::deque<std::pair<int, int> >& pairs, int begin, int mid, int end );
		void			sortDeque( int argc, char **input );

		void			fillVector( int argc, char **input );
		void			inputSequenceIsOddVec( void );
		void 			insertToMainChainVec( void );
		void			createMainChainAndPendVec( void );
		void			generatPositionsVec( void );
		int				jacobsthalVec(int n);
		void 			generateJacobInsertionSequenceVec( void );
		void			sortPairsVec( void );
		void			createListOrderVec( void );
		void			createPairsVec( void );
		void			mergeSortVec(int begin, int end);
		void			mergeVec( std::vector<std::pair<int, int> >& pairs, int begin, int mid, int end );
		void			sortVec( int argc, char **input );

	
	private:
		std::deque<int> 					_inputSequence;
		std::deque<int>						_mainChain;
		std::deque<int> 					_pend;
		std::deque<int> 					_jacobSequence;
		std::deque<int> 					_positions;
		std::deque<std::pair<int, int> >	_pairs;
		int									_straggler;
		bool								_hasStraggler;

		std::vector<int> 					_inputSequenceVec;
		std::vector<int>					_mainChainVec;
		std::vector<int> 					_pendVec;
		std::vector<int> 					_jacobSequenceVec;
		std::vector<int> 					_positionsVec;
		std::vector<std::pair<int, int> >	_pairsVec;
		int									_stragglerVec;
		bool								_hasStragglerVec;

		struct timeval						_startVec;
		struct timeval						_endVec;
		struct timeval						_startDeq;
		struct timeval						_endDeq;

		clock_t timeVec;
		clock_t timeDeq;
		clock_t timeVecEnd;
		clock_t timeDeqEnd;
};

std::ostream &			operator<<( std::ostream & o, PmergeMe const & i );

#endif /* ******************************************************** PMERGEME_H */