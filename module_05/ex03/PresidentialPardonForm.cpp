#include "PresidentialPardonForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PresidentialPardonForm::PresidentialPardonForm() 
	: AForm("Presidential Pardon Form", 25, 5) , _target("Undefined") {
}

PresidentialPardonForm::PresidentialPardonForm( std::string target ) 
	: AForm("Presidential Pardon Form", 25, 5), _target(target) {
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm & src ) :
	AForm("Presidential Pardon Form", 25, 5) {
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

PresidentialPardonForm::~PresidentialPardonForm() { }


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

PresidentialPardonForm	&PresidentialPardonForm::operator=( PresidentialPardonForm const &rhs )
{
	if (this != &rhs) {
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void					PresidentialPardonForm::execute( Bureaucrat const &executor ) const {
	checkExecute(executor);
	std::cout << MAGENTA << this->_target  << " has been pardoned by Zaphod Beeblebrox." << RES 
				<< std::endl;
}


/* ************************************************************************** */