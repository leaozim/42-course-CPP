#include "WrongAnimal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

WrongAnimal::WrongAnimal() :_type("WrongAnimal") {
	std::cout << YELLOW << "WrongAnimal = " << RES << " = Default constructor called" << std::endl;

}

WrongAnimal::WrongAnimal( const WrongAnimal & src ) {
	std::cout << YELLOW << "WrongAnimal = " << RES << " = Copy constructor called" << std::endl;
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

WrongAnimal::~WrongAnimal() {
	std::cout << YELLOW << "WrongAnimal = " << RES << "Destructor called" << std::endl;

}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

WrongAnimal			&WrongAnimal::operator=( WrongAnimal const &rhs ) {
	if ( this != &rhs )	{
		this->_type = rhs.getType();
		std::cout << YELLOW << "WrongAnimal = " << RES 
				  << " = Copy assignment operator called"
				  << std::endl;
	}
	return (*this);
}

std::ostream		&operator<<( std::ostream &o, WrongAnimal const &i ) {
	o << "Value = " << i.getType();
	return (o);
}


/*
** --------------------------------- METHODS ----------------------------------
*/
void				WrongAnimal::makeSound( void ) const {
	std::cout << GREEN << "pitchiu pitchun" << RES << std::endl;
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

void				WrongAnimal::setType( std::string value ) { this->_type = value; }

std::string			WrongAnimal::getType( void ) const { return this->_type; }


/* ************************************************************************** */