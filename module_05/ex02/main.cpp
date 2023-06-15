#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

void print_header(std::string str, char marker)
{
	std::cout << std::string(80, marker) << std::endl
			  << BLUE << str << RES
			  << std::endl
			  << std::string(80, marker) << std::endl;
}

void print_separator(void)
{
	std::cout << CYAN << std::string(80, '-') << RES << std::endl;
}


void	print_construtors_presidencial( void ) {
	{
		print_header("CONSTRUCTORS PRESIDENTIAL", '=');
		Bureaucrat	b1("Josefa", 2);
		AForm		*Presidential;
		
		print_separator();
		Presidential = new PresidentialPardonForm();

		print_header("Presidential Pardon Form - OK", '~');
		b1.signForm(*Presidential);
		b1.executeForm(*Presidential);

		print_header("Presidential Pardon Form - KO", '~');
		b1.setGrade(6);
		b1.signForm(*Presidential);
		b1.executeForm(*Presidential);
		print_header("DESTRUCTORS",  '=');
	}
	print_separator();
	std::cout << std::endl << std::endl << std::endl;
}

void	print_construtors_shrubbery( void ) {
	{
		print_header("CONSTRUCTORS SHRUBBERY", '=');
		Bureaucrat	b1("Maria", 15);
		AForm		*Shrubbery;
	
		print_separator();
		Shrubbery = new ShrubberyCreationForm("file");
		print_header("Shrubbery Creation Form - OK", '~');
		b1.signForm(*Shrubbery);
		b1.executeForm(*Shrubbery);

		print_header("Shrubbery Creation Form - KO", '~');
		b1.setGrade(138);
		b1.signForm(*Shrubbery);
		b1.executeForm(*Shrubbery);
		print_header("DESTRUCTORS", '=');
	}
	print_separator();
	std::cout << std::endl << std::endl << std::endl;
}

void	print_construtors_robotomy( void ) {
	{
		print_header("CONSTRUCTORS ROBOTOMY", '=');
		Bureaucrat	b1("João", 45);
		AForm		*Robotomy;
	
		print_separator();
		Robotomy = new RobotomyRequestForm("Juju");
	
		print_header("Robotomy Request Form - OK", '~');
		b1.signForm(*Robotomy);
		b1.executeForm(*Robotomy);
		b1.executeForm(*Robotomy);
		b1.executeForm(*Robotomy);
		b1.executeForm(*Robotomy);

		print_header("Robotomy Request Form - KO", '~');
		b1.setGrade(46);
		b1.signForm(*Robotomy);	
		b1.executeForm(*Robotomy);
		print_header("DESTRUCTORS", '=');
	}
}

int main()
{
	print_construtors_presidencial();
	print_construtors_shrubbery();
	print_construtors_robotomy();
	return (0);
}
