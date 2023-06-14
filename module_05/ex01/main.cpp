#include "Bureaucrat.hpp"
#include "Form.hpp"

static void print_header( std::string str )
{
	std::cout << std::string(70, '=') << std::endl
			  << BLUE << str  << RES
			  << std::endl
			  << std::string(70, '=') << std::endl;
}

static void print_separator( void )
{
	std::cout << CYAN << std::string(70, '-') << RES << std::endl;
}

void	test_constructors( void )
{
	print_header("CONSTRUCTORS");
	Form		f("Sign", 10, 15);
	Bureaucrat	b("João", 5);
	print_separator();
	std::cout << f << std::endl;
	print_separator();
	std::cout << b << std::endl;
	print_header("DESTRUCTORS");
}

void	test_copy_constructor( void )
{
		print_header("CONSTRUCTORS - COPY");
		Form       f1("Sign", 10, 20);
		print_separator();
		Form       f2(f1);
		print_separator();
		Form       f3 = f1;
		print_separator();
		Bureaucrat b1("Josefa", 5);
		print_separator();
		Bureaucrat b2("Adenia", 15);
		print_separator();
		b1.signForm(f1);
		b2.signForm(f2);
		print_header("DESTRUCTORS");
}

void	test_constructors_with_error( void )
{
	print_header("CONSTRUCTORS - GradeTooHighException");
	try {
		Form f("Sign", 0, 10);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	print_header("CONSTRUCTORS - GradeTooLowException");
	try {
		Form f("Sign", 1, 151);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

int main()
{
	test_constructors();
	test_copy_constructor();
	test_constructors_with_error();
	return (0);
}
