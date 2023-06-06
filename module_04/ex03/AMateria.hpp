#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include "Character.hpp"
# include <iostream>
# include <string>

# define MAGENTA "\033[35m"
# define RED "\x1b[38;5;88m"
# define GREEN "\x1b[38;5;40m"
# define BLUE "\x1b[38;5;25m"
# define YELLOW "\x1b[38;5;220m"
# define ORANGE	"\033[0;38;5;166m"
# define LIGHT_PURPLE "\033[1;35m"
# define CYAN "\001\e[0;36m\002"
# define RES "\x1b[0m"
class ICharacter;

class AMateria
{

	public:

		AMateria();
		AMateria( AMateria const &src );
		AMateria( std::string const &type );
		~AMateria();

		AMateria &		operator=( AMateria const &rhs );
	
		std::string const	&getType() const;
		virtual AMateria	*clone() const = 0;
		virtual void		use(ICharacter &target);

	protected:

	std::string				_type;

};

std::ostream &			operator<<( std::ostream & o, AMateria const & i );

#endif /* ******************************************************** AMATERIA_H */