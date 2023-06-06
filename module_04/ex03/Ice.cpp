#include "Ice.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Ice::Ice() : AMateria() {
	std::cout << ORANGE << "Ice = " << RES << "Default constructor called" << std::endl;

}

Ice::Ice( const Ice &src ) : AMateria(src) {
	std::cout << ORANGE << "Ice = " << RES << "Copy constructor called" << std::endl;
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Ice::~Ice() {
	std::cout << ORANGE << "Ice = " << RES << "Destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Ice					&Ice::operator=( Ice const &rhs ) {
	if ( this != &rhs ) {
		std::cout << YELLOW << "AMateria" << RES 
			<< " = Copy assignment operator called"
			<< std::endl;
		this->_type = rhs._type;
	}
	return (*this);
}


/*
** --------------------------------- METHODS ----------------------------------
*/

AMateria			*Ice::clone( void ) const {
	return new Ice(*this);
}


void	Ice::use(ICharacter &target)
{
	std::cout	<< "* shoots an ice bolt at "
				<< target.getName()
				<< " *"
				<< std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */