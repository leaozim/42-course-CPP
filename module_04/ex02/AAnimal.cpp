#include "AAnimal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

AAnimal::AAnimal() : _type("AAnimal") { 
	std::cout << YELLOW << "AAnimal = " << RES << "Default constructor called" << std::endl;
}

AAnimal::AAnimal( const AAnimal &rhs ): _type("AAnimal") {
	std::cout << YELLOW << "AAnimal = " << RES << "Copy constructor called" << std::endl;
	*this = rhs;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AAnimal::~AAnimal() {
	std::cout << YELLOW << "AAnimal = " << RES << "Destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

AAnimal 				&AAnimal::operator=( AAnimal const &rhs ) {
	if ( this != &rhs ) {
		this->_type = rhs.getType();
		std::cout << YELLOW << "AAnimal = " << RES 
				  << " = Copy assignment operator called"
				  << std::endl;
	}
	return (*this);
}

std::ostream 		&operator<<( std::ostream &o, AAnimal const &i )
{	
	o << "Value = " << i.getType();
	return (o);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

void				AAnimal::setType( std::string value ) { this->_type = value; }

std::string			AAnimal::getType( void ) const { return this->_type; }

/* ************************************************************************** */