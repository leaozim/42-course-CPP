#include "PresidentialPardonForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PresidentialPardonForm::PresidentialPardonForm() 
	: AForm("Presidential Pardon Form", 25, 5) , _target("Undefined") {
	print_description("Default constructor called", ORANGE);
}

PresidentialPardonForm::PresidentialPardonForm( std::string target ) 
	: AForm("Presidential Pardon Form", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm & src ) :
	AForm("Presidential Pardon Form", 25, 5) {
	*this = src;
	print_description("Copy constructor called", ORANGE);
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

PresidentialPardonForm::~PresidentialPardonForm() {
	print_description("Destructor called", ORANGE);
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

PresidentialPardonForm	&PresidentialPardonForm::operator=( PresidentialPardonForm const &rhs )
{
	if (this != &rhs) {
		print_description("Copy assignment operator called", ORANGE);
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

void					PresidentialPardonForm::print_description( std::string str, std::string color ) {
	std::cout << color << "Presidential Pardon Form" << RES 
			  << " = " 
			  << str
			  << std::endl;
}


/* ************************************************************************** */