#include "Dog.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Dog::Dog() {
	this->setType("Dog");
	std::cout << ORANGE << this->_type << RES << " = Default constructor called" << std::endl;
	this->_brain = new Brain();
}

Dog::Dog( const Dog &src ): Animal(src) {
	this->setType("Dog");
	*this = src;
	_brain = new Brain(*src._brain);
	std::cout << ORANGE << this->_type << RES << " = Copy constructor called" << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Dog::~Dog() {
	std::cout << ORANGE <<  this->_type << RES << " = Destructor called" << std::endl;
	delete this->_brain;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Dog					&Dog::operator=( Dog const &rhs ) {
	if ( this != &rhs ) {
		this->_type = "Dog";
		this->_brain = new Brain(*rhs._brain);
		std::cout << ORANGE << this->_type << RES 
				  << " = Copy assignment operator called"
				  << std::endl;
	}
	return (*this);
}

std::ostream		&operator<<( std::ostream &o, Dog const &i )
{
	o << "Value = " << i.getType();
	return (o);
}


/*
** --------------------------------- METHODS ----------------------------------
*/
void				Dog::makeSound( void ) const {
	std::cout << GREEN << "Woof woof" << RES << std::endl;
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

Brain				*Dog::getBrain(void) const { return this->_brain; }


/* ************************************************************************** */