#include "Character.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Character::Character() {
	std::cout << YELLOW << "Character = " << RES << "Default constructor called" << std::endl;

}

Character::Character( std::string name ) : _name(name) {
	std::cout << YELLOW << "Character = " << RES << "Name constructor called" << std::endl;
}

Character::Character( const Character &src ) {
	std::cout << YELLOW << "Character = " << RES << "Copy constructor called" << std::endl;
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Character::~Character() {
	std::cout << YELLOW << "Character = " << RES << "Type constructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Character			&Character::operator=( Character const &rhs )
{
	if ( this != &rhs )
	{
			std::cout << YELLOW << "Character" << RES 
			<< " = Copy assignment operator called"
			<< std::endl;
		this->_name = rhs.getName();
	}
	return *this;
}

std::ostream		&operator<<( std::ostream &o, Character const &i )
{
	o << "Value = " << i.getName();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

std::string const	&Character::getName(void) const { return (this->_name); }
	
void 				Character::setName(std::string name) { this->_name = name; }

void				Character::equip(AMateria *m) {
	for (int i = 0; i < MAX_MATERIAS; i++) {
		if (!this->_inventory[i])
		{
			this->_inventory[i] = m;
			return;
		}
	}
}

void				Character::unequip(int idx){
	if (this->_inventory[idx])
		this->_inventory[idx] = NULL;
}

void				Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx > MAX_MATERIAS)
		return ;
	if (!this->_inventory[idx])
		return ; 
	this->_inventory[idx]->use(target);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */