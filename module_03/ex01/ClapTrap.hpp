#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

# define MAGENTA "\033[35m"
# define RED "\x1b[38;5;88m"
# define GREEN "\x1b[38;5;40m"
# define BLUE "\x1b[38;5;25m"
# define ORANGE	"\033[0;38;5;166m"
# define LIGHT_PURPLE "\033[1;35m"
# define YELLOW "\x1b[38;5;220m"
# define CYAN "\001\e[0;36m\002"
# define RES "\x1b[0m"

class ClapTrap
{

	public:

		ClapTrap();
		ClapTrap( std::string name );
		ClapTrap( ClapTrap const &rhs );
		~ClapTrap();

		ClapTrap		&operator=( ClapTrap const &rhs );
		void			attack( const std::string &target );
		void			takeDamage( unsigned int amount );
		void			beRepaired( unsigned int amount );

		std::string		getType( void ) const;
		std::string		getName( void ) const;
		int				getHitPoints( void ) const;
		int				getEnergyPoints( void ) const;
		int				getAttackDamage( void ) const;

		void			setType( std::string value );
		void			setHitPoints( unsigned int value );
		void			setEnergyPoints( unsigned int value );
		void			setAttackDamage( unsigned int value );

	protected:
		std::string		_name;
		int				_hitPoints;
		int				_energyPoints;
		int 			_attackDamage;
		std::string		_type;

};

std::ostream &			operator<<( std::ostream &output, ClapTrap const &i );

#endif /* ******************************************************** CLAPTRAP_H */