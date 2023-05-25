#include "ClapTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ClapTrap::ClapTrap() 
	: _name("C-3PO"), _hitPoints(10),  _energyPoints(10), _attackDamage(0) {
	std::cout << YELLOW << "ClapTrap = " << RES
			  << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap( std::string name ) 
	: _name(name), _hitPoints(10),  _energyPoints(10), _attackDamage(0)  {
	std::cout << YELLOW << "ClapTrap = " << RES
			  << "Constructor with name passed as parameter" << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap & src ) {
	std::cout << YELLOW << "ClapTrap = " << RES
			  << "Copy constructor called" << std::endl;
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ClapTrap::~ClapTrap() {
	std::cout << YELLOW << "ClapTrap = " << RES
			  << "Destructor called" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ClapTrap &		ClapTrap::operator=( ClapTrap const & rhs ) {
	
	if ( this != &rhs )
	{	std::cout << YELLOW << "ClapTrap = " << RES;
		std::cout << "Copy assignment operator called" << std::endl;
		this->_name = rhs.getName();
		this->_hitPoints = rhs.getHitPoints();
		this->_energyPoints = rhs.getEnergyPoints();
		this->_attackDamage = rhs.getAttackDamage();
	}
	return (*this);
}

std::ostream &	operator<<( std::ostream & o, ClapTrap const & clapTrap )
{
	o << clapTrap.getName();
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void			ClapTrap::attack(const std::string& target) {
	if (this->_energyPoints > 0)
	{
		_energyPoints--;
		std::cout << GREEN << "ClapTrap = " << RES
				  << this->_name 
				  << " attacks " 
				  << target
				  << ", causing " 
				  << this->_attackDamage 
				  << " points of damage!"
				  <<  " hit points!" 
				  <<  " [HP = " 
				  << this->_hitPoints <<  "]"
				  <<  " [EP = " 
				  << this->_energyPoints <<  "]"
		<< std::endl;
	}
	else if (this->_hitPoints <= 0 || this->_energyPoints <= 0)
	{
		std::cout << GREEN << "ClapTrap = " << RES
				  << this->_name
				  << " can't attack!"
		<< std::endl;
	}
}

void			ClapTrap::takeDamage(unsigned int amount) {
	if (_hitPoints > 0)
	{
		this->_hitPoints -= amount;
		std::cout << GREEN << "ClapTrap = " << RES
				  << this->_name 
				  << " has taken " 
				  << amount 
				  << " of damage!" 
				  << "  [HP = " 
				  << this->_hitPoints <<  "]"
				  <<  " [EP = " 
				<< this->_energyPoints <<  "]"
		<< std::endl;
		if (_hitPoints == 0)
		{
			std::cout << GREEN << "ClapTrap = " << RES
					  << this->_name 
					  << " is dead!" 
			<< std::endl;
		}
	}
	else 
	{
		std::cout << GREEN << "ClapTrap = " << RES
				  << this->_name
				  << " is already dead!" 
		<< std::endl;
	}
}

void			ClapTrap::beRepaired(unsigned int amount) {

	if (this->_energyPoints <=0)
	{
		std::cout << GREEN << "ClapTrap = " << RES
				  << this->_name 
				  << " already without energy!" 
		<< std::endl;
		return ;
	}
	if (this->_hitPoints <= 0)		
	{
		std::cout << GREEN << "ClapTrap = " << RES
				  << this->_name 
				  << " is already dead!" 
		<< std::endl;
		return ;
	}
	this->_energyPoints--;
	this->_hitPoints += amount;
	std::cout << GREEN << "ClapTrap = " << RES
				<< this->_name 
				<< " recovered " 
				<< amount 
				<<  " hit points!" 
				<<  " [HP = " 
				<< this->_hitPoints <<  "]"
				<<  " [EP = " 
				<< this->_energyPoints <<  "]"
	<< std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string	ClapTrap::getName(void) const { return this->_name; }

int			ClapTrap::getHitPoints(void) const { return this->_hitPoints; }

int			ClapTrap::getEnergyPoints(void) const { return this->_energyPoints; }

int			ClapTrap::getAttackDamage(void) const { return this->_attackDamage; }

/* ************************************************************************** */