#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap( std::string const name );
		ScavTrap( const ClapTrap &rhs );
		ScavTrap( ScavTrap const &rhs );
		~ScavTrap();

		ScavTrap	&operator=( ScavTrap const &rhs );

		void		guardGate( void );
};

std::ostream		&operator<<( std::ostream &output, ScavTrap const &i );

#endif /* ******************************************************** SCAVTRAP_H */