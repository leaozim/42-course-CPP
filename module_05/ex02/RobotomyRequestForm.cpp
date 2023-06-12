#include "RobotomyRequestForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

RobotomyRequestForm::RobotomyRequestForm() {
	print_description("Default constructor called", ORANGE);

}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm & src ) {
	*this = src;
	print_description("Copy constructor called", ORANGE);
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

RobotomyRequestForm::~RobotomyRequestForm() {
	print_description("Destructor called", ORANGE);
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

RobotomyRequestForm	&RobotomyRequestForm::operator=( RobotomyRequestForm const &rhs )
{
	print_description("Copy assignment operator called", ORANGE);
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void					RobotomyRequestForm::print_description(std::string str, std::string color) {
	std::cout << color << "Presidential Pardon Form" << RES 
			  << " = " 
			  << str
			  << std::endl;
}	

// void					RobotomyRequestForm::execute( Bureaucrat const &executor ) const {
	
// }

/* ************************************************************************** */