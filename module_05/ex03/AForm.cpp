#include "AForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

AForm::AForm() : _name("Chico"), _isSigned(false), _gradeSign(5), _gradeExecute(5) { }

AForm::AForm( const AForm &src ) 
	: _name(src.getName()), _isSigned(src.getGradeSign()), _gradeSign(src.getGradeSign()), _gradeExecute(src.getGradeExecute()) {
	*this = src;
}

AForm::AForm(std::string name, int gradeSign, int gradeExecute) 
	: _name(name), _isSigned(false), _gradeSign(gradeSign), _gradeExecute(gradeExecute) {
	if (gradeSign < MAX_GRADE || gradeExecute < MAX_GRADE) { 
		throw GradeTooHighException(); }
	else if (gradeSign > MIN_GRADE || gradeExecute > MIN_GRADE) { 
		throw GradeTooLowException(); }
	const_cast<std::string&>(this->_name) = name;
	const_cast<int&>(this->_gradeSign) = gradeSign;
	const_cast<int&>(this->_gradeExecute) = gradeExecute;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AForm::~AForm() { }


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

AForm &				AForm::operator=( AForm const &rhs ) {
	if ( this != &rhs )
	{
		const_cast<std::string&>(this->_name) = getName();
		const_cast<int&>(this->_gradeSign) = getGradeSign();
		const_cast<int&>(this->_gradeExecute) = getGradeExecute();
	}
	return *this;
}

std::ostream		&operator<<( std::ostream &o, AForm const &i ) {
	o	<< "Form name                 = " << i.getName() << std::endl
		<< "Required Grade to Sign    = " << i.getGradeSign() << std::endl
		<< "Required Grade to Execute = " << i.getGradeExecute() << std::endl
		<< "Status                    = " << (i.getIsSigned() ? "Signed" : "Not Signed");
	return (o);
}


/*
** --------------------------------- METHODS ----------------------------------
*/

const char*				AForm::GradeTooHighException::what( void ) const throw() {
	return ("Grade Too High Exception");
}

const char*				AForm::GradeTooLowException::what( void ) const throw() {
	return ("Grade Too Low Exception");
}

const char*				AForm::NotSignedException::what( void ) const throw() {
	return ("Not signed");
}

const char*				AForm::AlreadySignedException::what( void ) const throw() {
	return ("Already signed");
}

void					AForm::beSigned( Bureaucrat &bureaucrat ) {
	if (bureaucrat.getGrade() > this->_gradeSign) { throw GradeTooLowException(); }
	if (this->_isSigned == true) { throw AlreadySignedException(); }
	this->_isSigned = true;
}

void					AForm::checkExecute( Bureaucrat const &executor)  const {
	if (executor.getGrade() > this->_gradeExecute) { throw GradeTooHighException(); }
	if (!getIsSigned()) { throw NotSignedException(); }
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string				AForm::getName( void ) const { return (this->_name); }

int						AForm::getGradeSign( void ) const { return (this->_gradeSign); }

int						AForm::getGradeExecute( void ) const { return (this->_gradeExecute); }

bool					AForm::getIsSigned( void ) const { return (this->_isSigned) ;}


/* ************************************************************************** */