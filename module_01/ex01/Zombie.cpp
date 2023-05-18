#include "Zombie.hpp"

Zombie::Zombie( ){ std::cout << std::endl << "Zombie " <<  "created" << std::endl; }

Zombie::Zombie( std::string name ) : _name(name) {}

Zombie::~Zombie( )
{
	std::cout << std::endl << "Zombie " << this->_name << " destroyed " << std::endl;
}

void	Zombie::announce( void )
{
	std::cout << std::endl << this->getZombieName() <<  ": BraiiiiiiinnnzzzZ..." << std::endl;
}

std::string	Zombie::getZombieName( void ) { return this->_name; }

void		Zombie::setZombieName( std::string name ) { this->_name = name; }
