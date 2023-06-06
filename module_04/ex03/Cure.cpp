#include "Cure.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cure::Cure() : AMateria() {
	std::cout << ORANGE << "Cure = " << RES << "Default constructor called" << std::endl;

}

Cure::Cure( const Cure &src ) : AMateria(src) {
	std::cout << ORANGE << "Cure = " << RES << "Copy constructor called" << std::endl;
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cure::~Cure() {
	std::cout << ORANGE << "Cure = " << RES << "Destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Cure					&Cure::operator=( Cure const &rhs ) {
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

AMateria			*Cure::clone( void ) const {
	return new Cure(*this);
}

void				Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */