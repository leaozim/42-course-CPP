#include "Span.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Span::Span() : _numberOfElements(0) { }

Span::Span( unsigned int n ) : _numberOfElements( n ) { }

Span::Span( const Span & src ) { 
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Span::~Span() { }


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Span &				Span::operator=( Span const & rhs )
{
	if ( this != &rhs )
		this->_numberOfElements = rhs._numberOfElements;
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/
void	Span::addNumber( int element )
{
	if (_set.size() >=_numberOfElements)
		throw  std::out_of_range("exceeded limit");
	_set.insert(element);
}

void	Span::addManyNumbers(std::multiset<int>::iterator first, std::multiset<int>::iterator last)
{
	if (_set.size() + std::distance(first, last) > _numberOfElements)
		throw  std::out_of_range("exceeded limit");
	_set.insert(first, last);
}

unsigned int Span::shortestSpan( void )
{
	 int	distance = std::numeric_limits<int>::max();
	 int	previousValue = distance;
	 int	dif;

	if (_set.empty())
		return 1;
	for (std::multiset<int>::iterator it = _set.begin(); it != _set.end(); ++it) {
		dif = abs(*it - previousValue);
		if (dif < distance) 
			distance = dif;
		previousValue = *it;
	}
	return (distance);
}

unsigned int Span::longestSpan(void)
{
	if (_set.empty())
		return 0;
	unsigned int	first = *(_set.begin());
	unsigned int	last = *(_set.rbegin());
	return (last - first);
}


/* ************************************************************************** */