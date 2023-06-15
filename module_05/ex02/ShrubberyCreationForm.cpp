#include "ShrubberyCreationForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ShrubberyCreationForm::ShrubberyCreationForm() 
	: AForm("Shrubbery Creation Form", 145, 137) , _target("Undefined") {
	print_description("Default constructor called", ORANGE);
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ) 
	: AForm("Shrubbery Creation Form", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm & src ) :
	AForm("Shrubbery Creation Form", 145, 137) {
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
	if (this != &rhs) {
		print_description("Copy assignment operator called", ORANGE);
	}
	return (*this);
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void					ShrubberyCreationForm::print_description(std::string str, std::string color) {
	std::cout << color << "Shrubbery Creation Form" << RES 
			  << " = " 
			  << str
			  << std::endl;
}	

void					ShrubberyCreationForm::execute( Bureaucrat const &executor ) const {
	std::ofstream	ofs;
	std::string		outFile; 
	
	checkExecute(executor);
	outFile = this->_target + "_shrubbery";
	ofs.open(outFile.c_str());
	if (ofs.fail())
		return ;
	ofs <<
			"               ,@@@@@@@,\n"
			<< "       ,,,.   ,@@@@@@/@@,  .oo8888o.\n" 
			<< "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n" 
			<< "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n" 
			<< "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n" 
			<< "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n" 
			<< "   `&%\\ ` /%&'    |.|         | |\n" 
			<< "       |o|        | |         | |\n" 
			<< "       |.|        | |         | |\n" 
			<< "//__\\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_\n";
	ofs.close();
}

/* ************************************************************************** */