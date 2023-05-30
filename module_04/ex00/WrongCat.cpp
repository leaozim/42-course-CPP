#include "WrongCat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

WrongCat::WrongCat() {
	this->setType("WrongCat");
	std::cout << RED << this->_type << RES << " = Default constructor called" << std::endl;
}

WrongCat::WrongCat( const WrongCat & src ) : WrongAnimal(src){
	*this = src;
	this->setType("WrongCat");
	std::cout << RED << this->_type << RES << " = Copy constructor called" << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

WrongCat::~WrongCat() {
	std::cout << RED << "WrongCat" << RES << " = Destructor called" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

WrongCat &				WrongCat::operator=( WrongCat const & rhs )
{
	if ( this != &rhs )
	{
		this->_type = "WrongCat";
		std::cout << RED << this->_type << RES 
				  << " = Copy assignment operator called"
				  << std::endl;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, WrongCat const & i )
{
	o << "Value = " << i.getType();
	return (o);
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	WrongCat::makeSound( void ) const {
	std::cout << GREEN << "Meow meow" << RES << std::endl;
}


/* ************************************************************************** */