#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <iomanip>


#define MAGENTA "\033[35m"
#define RED "\x1b[38;5;88m"
#define GREEN "\x1b[38;5;40m"
#define BLUE "\x1b[38;5;25m"
#define YELLOW "\x1b[38;5;220m"
#define ORANGE	"\033[0;38;5;166m"
#define LIGHT_PURPLE "\033[1;35m"
#define CYAN "\001\e[0;36m\002"
#define RES "\x1b[0m"


template <typename T>
class MutantStack : public std::stack<T>
{

	public:

		MutantStack() { }
		MutantStack( MutantStack const & src ) : std::stack<T>(src) { *this = src; }
		~MutantStack() { }
		MutantStack &		operator=( MutantStack const & rhs ) { ;
			if (this != &rhs) { std::stack<T>::operator=(rhs); }
			return (*this);
		}

		typedef	typename std::stack<T>::container_type::iterator				iterator;
		typedef	typename std::stack<T>::container_type::reverse_iterator		reverse_iterator;
		typedef	typename std::stack<T>::container_type::const_iterator			const_iterator;
		typedef	typename std::stack<T>::container_type::const_reverse_iterator	const_reverse_iterator;

		iterator				begin( void ) { return this->c.begin(); }
		iterator				end( void ) { return this->c.end(); }
		reverse_iterator		rbegin( void ) { return this->c.rbegin(); }
		reverse_iterator		rend( void ) { return this->c.rend(); }

		const_iterator			begin( void ) const { return this->c.begin(); }
		const_iterator			end( void ) const { return this->c.end(); }
		const_reverse_iterator	rbegin( void ) const { return this->c.rbegin(); }
		const_reverse_iterator	rend( void ) const { return this->c.rend(); }

};

template <typename T>
void printStackOrder(const T& stack)
{
    typename T::const_reverse_iterator it = stack.rbegin();
    typename T::const_reverse_iterator ite = stack.rend();

    while (it != ite) {
		std::cout << " | "<< *it << "  "<<std::endl;
        ++it;
    }
}

template <typename T>
void printStack(const T& stack)
{
    typename T::const_iterator it = stack.begin();
    typename T::const_iterator ite = stack.end();

    while (it != ite) {
		std::cout << " | "<< *it << "  "<<std::endl;
        ++it;
    }
}

void printHeader(const std::string& str, char marker, const char* color)
{
    int padding = 4;
    int totalWidth = 60;
    int strWidth = str.size();
    int margin = (totalWidth - strWidth - 2 * padding) / 2;

    std::string marginStr(margin, ' ');

    std::cout << std::string(totalWidth, marker) << std::endl
              << marginStr << std::string(padding, ' ') 
			  << color << str << "\033[0m" << std::string(padding, ' ') 
			  << marginStr << std::endl
              << std::string(totalWidth, marker) << std::endl;
}

void printSeparator(void)
{
	std::cout << CYAN << std::string(60, '-') << RES << std::endl;
}

#endif /* ******************************************************** MUTANTSTACK_H */