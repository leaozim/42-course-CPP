#include "Brain.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Brain::Brain() {
	std::cout << YELLOW << "Brain = " << RES << "Default constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = "Don't have ideas";
}

Brain::Brain( const Brain &src ) {
	std::cout << YELLOW << "Brain = " << RES << "Copy constructor called" << std::endl;
	*this = src;
}



/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Brain::~Brain() {
	std::cout << YELLOW << "Brain = " << RES << "Destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Brain					&Brain::operator=( Brain const &rhs ) {
	if ( this != &rhs ) {
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = rhs._ideas[i];
		std::cout << YELLOW <<  "Brain = " << RES 
			<< "Copy assignment operator called"
			<< std::endl;
	}
	return (*this);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string			Brain::getIdeas( int index ) const {
	if (index >= 0 && index < MAX_IDEAS)
		return (_ideas[index]);
	return (NULL);
}

void				Brain::setIdeas( int index, std::string idea ) {
	if (index >= 0 && index < MAX_IDEAS) {
        _ideas[index] = idea;
    }
}

/* ************************************************************************** */