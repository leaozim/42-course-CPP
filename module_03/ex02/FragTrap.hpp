#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap();
		FragTrap( std::string const name );
		FragTrap( const ClapTrap &rhs );
		FragTrap( FragTrap const &rhs );
		~FragTrap();

		FragTrap	&operator=( FragTrap const &rhs );

		void		highFivesGuys( void );
};

std::ostream		&operator<<( std::ostream &output, FragTrap const &i );

#endif /* ******************************************************** FRAGTRAP_H */