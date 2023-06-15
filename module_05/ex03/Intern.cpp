#include "Intern.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Intern::Intern() {
	this->_funcions[0].name = "shrubbery creation";
	this->_funcions[0].form = &Intern::_makePresidentialPardonForm;
	this->_funcions[1].name = "robotomy request";
	this->_funcions[1].form = &Intern::_makeRobotomyRequestForm;
	this->_funcions[2].name = "presidential pardon";
	this->_funcions[2].form = &Intern::_makeShrubberyCreationForm;
}

Intern::Intern( const Intern & src ) {
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Intern::~Intern() { }


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Intern &				Intern::operator=( Intern const & rhs )
{
	if ( this != &rhs )
	{
		for (int i = 0; i < NUM_FORMS; i++) 
		{
			this->_funcions[i].name = rhs._funcions[i].name;
			this->_funcions[i].form = rhs._funcions[i].form;
		}
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

AForm		*Intern::_makeShrubberyCreationForm( std::string target, std::string name )
{
	std::cout << "Intern creates " << name << std::endl;
	return new ShrubberyCreationForm(target);
}

AForm		*Intern::_makeRobotomyRequestForm( std::string target, std::string name )
{
	std::cout << "Intern creates " << name << std::endl;
	return new RobotomyRequestForm(target);
}

AForm		*Intern::_makePresidentialPardonForm( std::string target, std::string name )
{
	std::cout << "Intern creates " << name << std::endl;
	return new PresidentialPardonForm(target);
}

AForm		*Intern::makeForm( std::string name, std::string target )
{
	int index;

	index = 0;
	while (index < NUM_FORMS && name != this->_funcions[index].name)
		index++;
	if (index < NUM_FORMS)
		return ((this->*_funcions[index].form)(target, name));
	std::cout << GREY << "Error creating form" << RES << std::endl;
	return(NULL);
}


/* ************************************************************************** */