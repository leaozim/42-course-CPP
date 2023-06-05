#ifndef AANIMAL_HPP
# define AANIMAL_HPP

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

class AAnimal
{

	public:

		AAnimal();
		AAnimal( AAnimal const &src );
		virtual ~AAnimal();

		AAnimal			&operator=( AAnimal const &rhs );

		virtual void	makeSound( void ) const = 0;
		std::string		getType( void ) const ;
		void			setType( std::string value );

	protected:

		std::string		_type;

};

std::ostream			&operator<<( std::ostream &o, AAnimal const &i );

#endif /* ********************************************************** ANIMAL_H */