#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include  "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

void	print_header(std::string str, char marker)
{
	std::cout << std::string(80, marker) << std::endl
			  << BLUE << str << RES
			  << std::endl
			  << std::string(80, marker) << std::endl;
}

void	print_separator(void)
{
	std::cout << CYAN << std::string(80, '-') << RES << std::endl;
}


void	print_make_robotomy( void )
{
	{
		print_header("ROBOTOMY - MAKE FORME", '=');
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		Bureaucrat b("Zé", 1);
		b.signForm(*rrf);
		b.executeForm(*rrf);
		delete rrf;
	}
}

void print_make_shrubbert( void ) 
{
	{
		print_header("SHRUBBERT - MAKE FORME", '=');
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
		Bureaucrat b("Zé", 1);
		b.signForm(*rrf);
		b.executeForm(*rrf);
		delete rrf;
	}
}

void	print_make_presidential( void )
{
	{
		print_header("PRESIDENTIAL - MAKE FORME", '=');
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
		Bureaucrat b("Zé", 1);
		b.signForm(*rrf);
		b.executeForm(*rrf);
		delete rrf;
	}
}

void	print_make_error( void )
{
	{
		print_header("KO - MAKE FORME", '=');
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("some random name", "Bender");
		delete rrf;
	}
}

int main()
{
	print_make_robotomy();
	print_make_shrubbert();
	print_make_presidential();
	print_make_error();
	return (0);
}
