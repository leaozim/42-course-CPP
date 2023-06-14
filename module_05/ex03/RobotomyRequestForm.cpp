#include "RobotomyRequestForm.hpp"

bool	RobotomyRequestForm::_seedHasBeenGenerated = false;

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

RobotomyRequestForm::RobotomyRequestForm() 
	: AForm("Robotomy Request Form", 72, 45) , _target("Undefined") {
}

RobotomyRequestForm::RobotomyRequestForm( std::string target ) 
	: AForm("Robotomy Request Form", 72, 45), _target(target) {
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm & src ) :
	AForm("Robotomy Request Form", 72, 45) {
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

RobotomyRequestForm::~RobotomyRequestForm() { }


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

RobotomyRequestForm	&RobotomyRequestForm::operator=( RobotomyRequestForm const &rhs )
{
	if (this != &rhs) {
	}
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/	

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