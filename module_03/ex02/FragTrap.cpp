#include "FragTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

FragTrap::FragTrap() {
	std::cout << ORANGE << "FragTrap = " << RES << "Default constructor called" << std::endl;
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
	this->setType("FragTrap");
}

FragTrap::FragTrap(std::string const name) : ClapTrap(name) {
	std::cout << ORANGE << "FragTrap = " << RES << "Default constructor called" << std::endl;
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
	this->setType("FragTrap");
}

FragTrap::FragTrap( const ClapTrap &rhs ) : ClapTrap(rhs) {
	this->_hitPoints = rhs.getHitPoints();
	this->_energyPoints = rhs.getEnergyPoints();
	this->_attackDamage = rhs.getAttackDamage();
}

FragTrap::FragTrap( const FragTrap &rhs ) : ClapTrap(rhs) {
	std::cout << ORANGE << "FragTrap = " << RES << "Copy constructor called" << std::endl;
	*this = rhs;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

FragTrap::~FragTrap() {
	std::cout << ORANGE << "FragTrap = " << RES << "Destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

FragTrap		&FragTrap::operator=( FragTrap const &rhs ) {
	if (this != &rhs) {
		std::cout << ORANGE <<"FragTrap = " << RES 
				  << "Copy assignment operator called"
				  << std::endl;
		this->_name = rhs.getName();
		this->_hitPoints = rhs.getHitPoints();
		this->_energyPoints = rhs.getEnergyPoints();
		this->_attackDamage = rhs.getAttackDamage();
		this->_type = "FragTrap";
	}
	return (*this);
}

std::ostream	&operator<<( std::ostream &output, FragTrap const &i ) {
	output << i.getName();
	return (output);
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void			FragTrap::highFivesGuys( void ) {
	if (this->_hitPoints <= 0) {
		std::cout << CYAN << "FragTrap = " << RES 
				  << "It is offensive to greet a dead roboot! :x" 
				  << std::endl;
	}
	else {
		std::cout << CYAN << "FragTrap = " << RES 
				  << "High fives! o/\\o" 
				  << std::endl;
	}
}

/* ************************************************************************** */