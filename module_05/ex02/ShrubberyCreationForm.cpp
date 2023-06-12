#include "ShrubberyCreationForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ShrubberyCreationForm::ShrubberyCreationForm() {
	print_description("Default constructor called", ORANGE);

}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm & src ) {
	*this = src;
	print_description("Copy constructor called", ORANGE);
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ShrubberyCreationForm::~ShrubberyCreationForm() {
	print_description("Destructor called", ORANGE);
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ShrubberyCreationForm	&ShrubberyCreationForm::operator=( ShrubberyCreationForm const &rhs )
{
	print_description("Copy assignment operator called", ORANGE);
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void					ShrubberyCreationForm::print_description(std::string str, std::string color) {
	std::cout << color << "Presidential Pardon Form" << RES 
			  << " = " 
			  << str
			  << std::endl;
}	

void					ShrubberyCreationForm::execute( Bureaucrat const &executor ) const {
	
}

/* ************************************************************************** */