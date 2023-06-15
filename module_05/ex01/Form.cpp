#include "Form.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Form::Form() : _name("Chico"), _isSigned(false), _gradeSign(2), _gradeExecute(2)
{
	print_description("Default constructor called", ORANGE);
}

Form::Form( const Form &src ) 
	: _name(src.getName()), _isSigned(src.getGradeSign()), _gradeSign(src.getGradeSign()), _gradeExecute(src.getGradeExecute())
{
	*this = src;
	print_description("Copy constructor called", ORANGE);
}

Form::Form(std::string name, int gradeSign, int gradeExecute) 
	: _name(name), _isSigned(false), _gradeSign(gradeSign), _gradeExecute(gradeExecute)
{
	if (gradeSign < MAX_GRADE || gradeExecute < MAX_GRADE) { throw GradeTooHighException(); }
	else if (gradeSign > MIN_GRADE || gradeExecute > MIN_GRADE) { throw GradeTooLowException(); }
	print_description("Name and Grades constructor called", ORANGE);
	const_cast<std::string&>(this->_name) = name;
	const_cast<int&>(this->_gradeSign) = gradeSign;
	const_cast<int&>(this->_gradeExecute) = gradeExecute;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Form::~Form()
{
	print_description("Destructor called", ORANGE);
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Form &				Form::operator=( Form const &rhs )
{
	if ( this != &rhs )
	{
		const_cast<std::string&>(this->_name) = getName();
		const_cast<int&>(this->_gradeSign) = getGradeSign();
		const_cast<int&>(this->_gradeExecute) = getGradeExecute();
		print_description("Copy assignment operator called", ORANGE);
	}
	return (*this);
}

std::ostream		&operator<<( std::ostream &o, Form const &i )
{
	o	<< "Form name                 = " 
		<< i.getName() 
		<< std::endl
		<<"Required Grade to Sign    = " 
		<< i.getGradeSign() 
		<< std::endl
		<<"Required Grade to Execute = " 
		<< i.getGradeExecute() 
		<< std::endl
		<< "Status                    = " 
		<< (i.getIsSigned() ? "Signed" : "Not Signed");
	return (o);
}


/*
** --------------------------------- METHODS ----------------------------------
*/

const char				*Form::GradeTooHighException::what( void ) const throw() {
	return ("Grade Too High Exception");
}

const char				*Form::GradeTooLowException::what( void ) const throw() {
	return ("Grade Too Low Exception");
}

const char				*Form::AlreadySignedException::what( void ) const throw() {
	return ("Already signed");
}

void					Form::beSigned( Bureaucrat &bureaucrat ) {
	if (bureaucrat.getGrade() > this->_gradeSign) { throw GradeTooLowException(); }
	if (this->_isSigned == true) { throw AlreadySignedException(); }
	this->_isSigned = true;
}


void					Form::print_description(std::string str, std::string color) {
	std::cout << color << "Form" << RES 
			  << " = " 
			  << str
			  << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string				Form::getName( void ) const { return (this->_name); }

int						Form::getGradeSign( void ) const { return (this->_gradeSign); }

int						Form::getGradeExecute( void ) const { return (this->_gradeExecute); }

bool					Form::getIsSigned( void ) const { return (this->_isSigned) ;}


/* ************************************************************************** */