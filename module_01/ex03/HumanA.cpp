#include "HumanA.hpp"

HumanA::HumanA( std::string name, Weapon const& weapon ) : _name(name), _weapon(weapon ) {}

HumanA::~HumanA( ){}

void	HumanA::attack(void)
{
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}
