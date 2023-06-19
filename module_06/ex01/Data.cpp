#include "Data.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Data::Data() : _name("cavalinho andando na chuva") { }

Data::Data( const Data & src ) { *this = src; }


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Data::~Data() { }


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Data &				Data::operator=( Data const &rhs )
{
	if ( this != &rhs )	{ }
	return (*this);
}

std::ostream			&operator<<( std::ostream &o, Data const &i ) {
	o << i.getName() ;
	return (o);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string			Data::getName( void ) const { return (_name); };


/* ************************************************************************** */