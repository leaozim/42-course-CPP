#include "Serializer.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Serializer::Serializer() { }

Serializer::Serializer( const Serializer & src ) { *this = src; }


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Serializer::~Serializer() { }


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Serializer &				Serializer::operator=( Serializer const & rhs )
{
	if ( this != &rhs )	{
	}
	return (*this);
}


/*
** --------------------------------- METHODS ----------------------------------
*/
uintptr_t		Serializer::serialize( Data* ptr )
{
	return reinterpret_cast<uintptr_t>(ptr);
}
Data*				Serializer::deserialize( uintptr_t raw )
{
	return reinterpret_cast<Data *>(raw);
}


/* ************************************************************************** */