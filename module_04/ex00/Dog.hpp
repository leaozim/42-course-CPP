#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal 
{

	public:

		Dog();
		Dog( Dog const & src );
		~Dog();

		Dog &		operator=( Dog const & rhs );
		
		void		makeSound( void ) const;

	private:

};

std::ostream &			operator<<( std::ostream & o, Dog const & i );

#endif /* ************************************************************* DOG_H */