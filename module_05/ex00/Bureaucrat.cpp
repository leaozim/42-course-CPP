#include "Bureaucrat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Bureaucrat::Bureaucrat() : _name("Zé"),  _grade(66) 
{
	print_description("Default constructor called", YELLOW);
}

Bureaucrat::Bureaucrat( const Bureaucrat &src )
{
	*this = src;
	print_description("Copy constructor called", YELLOW);

}

Bureaucrat::Bureaucrat( std::string name, int grade ) 
{
	if (grade < MAX_GRADE) { throw GradeTooHighException(); }
	else if (grade > MIN_GRADE) { throw GradeTooLowException(); }
	const_cast<std::string&>(this->_name) = name;
	this->_grade = grade;
	print_description("Name and Grade constructor called", YELLOW);
}
/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Bureaucrat::~Bureaucrat()
{
	print_description("Destructor called", YELLOW);
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Bureaucrat				&Bureaucrat::operator=( Bureaucrat const &rhs )
{
	if ( this != &rhs )
	{
		this->_grade = rhs.getGrade();
		const_cast<std::string&>(this->_name) = rhs.getName();
		print_description("Copy assignment operator called", YELLOW);
	}
	return (*this);
}

std::ostream			&operator<<( std::ostream &o, Bureaucrat const &i )
{
	o << i.getName() << ", bureaucrat grade " << i.getGrade() << ".";
	return (o);
}



/*
** --------------------------------- METHODS ----------------------------------
*/

const char*	Bureaucrat::GradeTooHighException::what( void ) const throw() {
	return ("Grade Too High Exception");
}

const char*	Bureaucrat::GradeTooLowException::what( void ) const throw() {
	return ("Grade Too Low Exception");
}

void	Bureaucrat::increment( void ){

	if (this->_grade == MIN_GRADE) { throw GradeTooLowException(); }
	this->_grade++;
}

void	Bureaucrat::decrement( void ){

	if (this->_grade == MAX_GRADE) { throw GradeTooHighException(); }
	this->_grade--;
}


void	Bureaucrat::print_description(std::string str, std::string color) {
	std::cout << color << "Bureaucrat" << RES 
			  << " = " 
			  << str
			  << std::endl;
}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string				Bureaucrat::getName( void ) const { return (this->_name); }

int						Bureaucrat::getGrade( void ) const { return (this->_grade); }

/* ************************************************************************** */