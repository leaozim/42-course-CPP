#include "Animal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Animal::Animal() : _type("Animal") { 
	std::cout << YELLOW << "Animal = " << RES << "Default constructor called" << std::endl;
}

Animal::Animal( const Animal & rhs ): _type("Animal") {
	std::cout << YELLOW << "Animal = " << RES << "Copy constructor called" << std::endl;
	*this = rhs;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Animal::~Animal() {
	std::cout << YELLOW << "Animal = " << RES << "Destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Animal &				Animal::operator=( Animal const &rhs ) {
	if ( this != &rhs ) {
		this->_type = rhs.getType();
	}
	return (*this);
}

std::ostream &			operator<<( std::ostream &o, Animal const &i )
{	
	o << "Value = " << i.getType();
	return (o);
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void	Animal::makeSound( void ) const {
	std::cout << GREEN 
			  << "This sound is not the sound of a recognized animal."
			  << RES 
			  << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

void		Animal::setType( std::string value ) { this->_type = value; }

std::string	Animal::getType( void ) const { return this->_type; }

/* ************************************************************************** */