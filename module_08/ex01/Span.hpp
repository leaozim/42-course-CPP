#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <set>
# include <cstdlib>
# include <limits>

# define MAGENTA "\033[35m"
# define RED "\x1b[38;5;88m"
# define GREEN "\x1b[38;5;40m"
# define BLUE "\x1b[38;5;25m"
# define YELLOW "\x1b[38;5;220m"
# define ORANGE	"\033[0;38;5;166m"
# define LIGHT_PURPLE "\033[1;35m"
# define CYAN "\001\e[0;36m\002"
# define RES "\x1b[0m"

class Span
{

	public:

		Span();
		Span( Span const & src );
		Span ( unsigned int n );
		~Span();

		Span &				operator=( Span const & rhs );

		void				addNumber( int element );
		unsigned int		shortestSpan( void );
		unsigned int		longestSpan( void );
		void				addManyNumbers(std::set<int>::iterator first, std::set<int>::iterator last);


	private:
		unsigned int		_numberOfElements;
		std::multiset<int>	_set;


};

#endif /* ************************************************************ SPAN_H */