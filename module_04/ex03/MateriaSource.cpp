#include "MateriaSource.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

MateriaSource::MateriaSource()
{
}

MateriaSource::MateriaSource( const MateriaSource & src )
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

MateriaSource::~MateriaSource()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

MateriaSource &				MateriaSource::operator=( MateriaSource const & rhs )
{
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, MateriaSource const & i )
{
	//o << "Value = " << i.getValue();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void				MateriaSource::learnMateria(AMateria *materia) {
	for (int i = 0; i < MAX_MATERIAS; i++)
		{
			for(int i = 0; i < MAX_MATERIAS; i++)
		if (!this->_magicBook[i])
			return (_storeMateria(materia, i))	;
		}
}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */