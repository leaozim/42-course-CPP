#include "ShrubberyCreationForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ShrubberyCreationForm::ShrubberyCreationForm() 
	: AForm("Shrubbery Creation Form", 145, 137) , _target("Undefined") {
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ) 
	: AForm("Shrubbery Creation Form", 145, 137), _target(target) {
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm & src ) :
	AForm("Shrubbery Creation Form", 145, 137) {
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ShrubberyCreationForm::~ShrubberyCreationForm() { }


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ShrubberyCreationForm	&ShrubberyCreationForm::operator=( ShrubberyCreationForm const &rhs )
{
	if (this != &rhs) {
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void					ShrubberyCreationForm::execute( Bureaucrat const &executor ) const {
	std::ofstream	ofs;
	std::string		outFile; 
	
	checkExecute(executor);
	outFile = this->_target + "_shrubbery";
	ofs.open(outFile.c_str());
	if (ofs.fail())
		return ;
	ofs <<
	"    oxoxoo    ooxooz\n"
	" ooxoxo oo  oxoxooo\n"
	" oooo xxoxoo ooo ooox\n"
	" oxo o oxoxo  xoxxoxo\n"
	"  oxo xooxoooo o ooo\n"
	"    ooo\\oo\\  /o/o\n"
	"        \\  \\/ /\n"
	"         |   /\n"
	"         |  |\n"
	"         |  |\n"
	"         |  |\n"
	"         |  |\n"
	"  ______/____\\____\n"
	<< std::endl;
}

/* ************************************************************************** */