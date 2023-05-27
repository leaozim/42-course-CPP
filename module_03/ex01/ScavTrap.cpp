#include "ScavTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ScavTrap::ScavTrap() : ClapTrap() {
	std::cout << LIGHT_PURPLE << "ScavTrap = " << RES << "Default constructor called" << std::endl;
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
	this->setType("ScavTrap");
}

ScavTrap::ScavTrap( std::string const name ) : ClapTrap(name) {
	std::cout << LIGHT_PURPLE << "ScavTrap = " << RES << "Default constructor called" << std::endl;
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
	this->setType("ScavTrap");

}

ScavTrap::ScavTrap( const ClapTrap &rhs ) : ClapTrap(rhs) {
	this->_hitPoints = rhs.getHitPoints();
	this->_energyPoints = rhs.getEnergyPoints();
	this->_attackDamage = rhs.getAttackDamage();
}

ScavTrap::ScavTrap( const ScavTrap &rhs ) : ClapTrap(rhs) {
	std::cout << LIGHT_PURPLE << "ScavTrap = " << RES << "Copy constructor called" << std::endl;
	*this = rhs;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ScavTrap::~ScavTrap() {
	std::cout << LIGHT_PURPLE << "ScavTrap = " << RES << "Destructor called" << std::endl;

}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ScavTrap		&ScavTrap::operator=( ScavTrap const &rhs ) {
	if (this != &rhs) {
		std::cout << LIGHT_PURPLE <<"ScavTrap = " << RES
				  << "Copy assignment operator called" 
				  << std::endl;
		this->_name = rhs.getName();
		this->_hitPoints = rhs.getHitPoints();
		this->_energyPoints = rhs.getEnergyPoints();
		this->_attackDamage = rhs.getAttackDamage();
		this->_type = "ScavTrap";
	}
	return (*this);
}

std::ostream	&operator<<( std::ostream &output, ScavTrap const &i ) {
	output << i.getName();
	return (output);
}

/*
** --------------------------------- METHODS ----------------------------------
*/
	
void			ScavTrap::guardGate( void ) {
	if (this->_hitPoints <= 0) {
		std::cout << CYAN << "ScavTrap = " << RES 
				  << "Can't guard Gate, he is death! :c" 
				  << std::endl;
	}
	else {
		std::cout << CYAN << "ScavTrap = " << RES 
				  << this->_name
				  << " is now in Gate keeper mode." 
				  << std::endl;
	}
}


/* ************************************************************************** */