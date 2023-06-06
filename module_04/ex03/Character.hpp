#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

#define MAX_MATERIAS 4 

class Character
{

	public:

		Character();
		Character( std::string name );
		Character( Character const &src );
		virtual ~Character();

		Character			&operator=( Character const &rhs );

		std::string const	&getName(void) const;
		void 				setName(std::string name);
		void				equip(AMateria* m);
		void				unequip(int idx);
		void				use(int idx, ICharacter& target);

	private:
		AMateria				*_inventory[MAX_MATERIAS];
		std::string				_name;

};

std::ostream				&operator<<( std::ostream & o, Character const & i );

#endif /* ******************************************************* CHARACTER_H */