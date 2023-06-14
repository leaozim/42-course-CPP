#include "RobotomyRequestForm.hpp"

bool	RobotomyRequestForm::_seedHasBeenGenerated = false;

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

RobotomyRequestForm::RobotomyRequestForm() 
	: AForm("Robotomy Request Form", 72, 45) , _target("Undefined") {
	print_description("Default constructor called", ORANGE);
}

RobotomyRequestForm::RobotomyRequestForm( std::string target ) 
	: AForm("Robotomy Request Form", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm & src ) :
	AForm("Robotomy Request Form", 72, 45) {
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
	if (this != &rhs) {
		print_description("Copy assignment operator called", ORANGE);
	}
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void					RobotomyRequestForm::print_description(std::string str, std::string color) {
	std::cout << color << "Robotomy Request Form" << RES 
			  << " = " 
			  << str
			  << std::endl;
}	

void					RobotomyRequestForm::execute( Bureaucrat const &executor ) const {
	checkExecute(executor);
	if (!this->_seedHasBeenGenerated)
	{
		srand(time(NULL));
		_seedHasBeenGenerated = true;
	}
	std::cout << "Vrrrmmm Prrrrrrr Zzzzzzz Tchac-tchac-tchac Tink-tink-tink Krrrrrrr" << RES << std::endl;
	if (rand() % 2)
	{
		std::cout << MAGENTA << this->_target  << " has been robotomized." << RES 
		<< std::endl;
	}
	else {
		std::cout << MAGENTA << "Robotomy failed.." << RES 
		<< std::endl;
	}
}

/* ************************************************************************** */