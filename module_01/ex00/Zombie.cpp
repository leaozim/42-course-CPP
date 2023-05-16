#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name) {}

Zombie::~Zombie()
{
	std::cout << std::endl << "Zombie " << this->_name << " destroyed " << std::endl;
}

void	Zombie::announce( void )
{
	std::cout << this->get_zombie_name() <<  ": BraiiiiiiinnnzzzZ..." << std::endl;
}

std::string 	Zombie::get_zombie_name(void) {return this->_name; }
