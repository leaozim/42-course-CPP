#include "Cat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cat::Cat() {
	this->setType("Cat");
	std::cout << ORANGE << this->_type << RES << " = Default constructor called" << std::endl;
}

Cat::Cat( const Cat & src ) : Animal(src) {
	*this = src;
	this->setType("Cat");
	std::cout << ORANGE << this->_type << RES << " = Copy constructor called" << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cat::~Cat() {
	std::cout << ORANGE <<  this->_type << RES << " = Destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Cat &				Cat::operator=( Cat const & rhs ) {
	if ( this != &rhs ) {
		this->_type = "Cat";
		std::cout << ORANGE << this->_type << RES 
				  << " = Copy assignment operator called"
				  << std::endl;
	}
	return (*this);
}

std::ostream &			operator<<( std::ostream & o, Cat const & i ) {
	o << "Value = " << i.getType();
	return (o);
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	Cat::makeSound( void ) const {
	std::cout << GREEN << "Meow meow" << RES << std::endl;
}

/* ************************************************************************** */