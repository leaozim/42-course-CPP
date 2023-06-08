#ifndef BRAIN_HPP
# define BRAIN_HPP

# include "AAnimal.hpp"
#include <cstdlib>

#define MAX_IDEAS 100

class Brain
{

	public:

		Brain();
		Brain( Brain const &src );
		~Brain();

		Brain			&operator=( Brain const &rhs );
		std::string		getIdeas( int index ) const;
		void			setIdeas( int index, std::string idea );
	
	private:
		std::string			_ideas[MAX_IDEAS];

};

std::ostream			&operator<<( std::ostream &o, Brain const &i );

#endif /* *********************************************************** BRAIN_H */