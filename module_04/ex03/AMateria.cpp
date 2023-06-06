#include "AMateria.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

AMateria::AMateria() { 
	std::cout << YELLOW << "AMateria = " << RES << "Default constructor called" << std::endl;
}

AMateria::AMateria( const AMateria &src ) {
	std::cout << YELLOW << "AMateria = " << RES << "Copy constructor called" << std::endl;
	*this = src;
}

AMateria::AMateria( std::string const &type ) : _type(type) {
	std::cout << YELLOW << "AMateria = " << RES << "Type constructor called" << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AMateria::~AMateria() {
	std::cout << YELLOW << "AMateria = " << RES << "Destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

AMateria				&AMateria::operator=( AMateria const &rhs ) {
	if ( this != &rhs ) {
		std::cout << YELLOW << "AMateria" << RES 
			<< " = Copy assignment operator called"
			<< std::endl;
		this->_type = rhs.getType();
	}
	return (*this);
}

std::ostream &			operator<<( std::ostream & o, AMateria const & i ) {
	o << "Value = " << i.getType();
	return (o);
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void		AMateria::use(ICharacter &target) {

	std::cout << YELLOW << this->_type << RES 
			<< " used on " 
			<< target.getName()
			<< std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string const	&AMateria::getType( void ) const { return (this->_type); }


/* ************************************************************************** */