#include "ClapTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ClapTrap::ClapTrap() 
	: _name("Claptrappington"), _energyPoints(10), _hitPoints(10), _attackDamage(10) {
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap( std::string name ) : _name(name) { 
	std::cout << "String constructor called" << std::endl;

}

ClapTrap::ClapTrap( const ClapTrap & src ) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ClapTrap::~ClapTrap() {
	std::cout << "Destructor called" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ClapTrap &				ClapTrap::operator=( ClapTrap const & rhs ) {
	if ( this != &rhs )
	{
		this->_name = rhs.getName();
		this->_hitPoints = rhs.getHitPoints();
		this->_energyPoints = rhs.getEnergyPoints();
		this->_attackDamage = rhs.getAttackDamage();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, ClapTrap const & clapTrap )
{
	o << clapTrap.getName();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	ClapTrap::attack(const std::string& target) {
	
}

void	ClapTrap::takeDamage(unsigned int amount) {
	

}

void	ClapTrap::beRepaired(unsigned int amount) {

	
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string ClapTrap::getName(void) const { return this->_name; }

int ClapTrap::getHitPoints(void) const { return this->_hitPoints; }

int ClapTrap::getEnergyPoints(void) const { return this->_energyPoints; }

int ClapTrap::getAttackDamage(void) const { return this->_attackDamage; }


/* ************************************************************************** */