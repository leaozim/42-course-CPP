#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"

 void print_header(std::string str)
{
	std::cout << std::string(70, '=') << std::endl
			  << BLUE << str << RES
			  << std::endl
			  << std::string(70, '=') << std::endl;
}

static void print_separator(void)
{
	std::cout << CYAN << std::string(70, '-') << RES << std::endl;
}

// void test_constructors(void)
// {
// 	print_header("CONSTRUCTORS");
// 	AForm f("Sign", 10, 15);
// 	Bureaucrat b("João", 5);
// 	print_separator();
// 	std::cout << f << std::endl;
// 	print_separator();
// 	std::cout << b << std::endl;
// 	print_header("DESTRUCTORS");
// }

// void test_copy_constructor(void)
// {
// 	print_header("CONSTRUCTORS");
// 	AForm f1("Sign", 10, 20);
// 	print_separator();
// 	AForm f2(f1);
// 	print_separator();
// 	AForm f3 = f1;
// 	print_separator();
// 	Bureaucrat b1("Josefa", 5);
// 	print_separator();
// 	Bureaucrat b2("Adenia", 15);
// 	print_separator();
// 	Bureaucrat b3("Tereza", 25);
// 	print_separator();
// 	b1.signForm(f1);
// 	b2.signForm(f2);
// 	b3.signForm(f3);
// 	print_header("DESTRUCTORS");
// }

// void test_constructors_with_error(void)
// {
// 	print_header("CONSTRUCTORS - GradeTooHighException");
// 	try
// 	{
// 		AForm f("Sign", MAX_GRADE - 1, 10);
// 	}
// 	catch (std::exception &e)
// 	{
// 		std::cout << e.what() << std::endl;
// 	}
// 	print_header("CONSTRUCTORS - GradeTooLowException");
// 	try
// 	{
// 		AForm f("Sign", 1, 150 + 1);
// 	}
// 	catch (std::exception &e)
// 	{
// 		std::cout << e.what() << std::endl;
// 	}
// }

int main()
{
	Bureaucrat	b1("Josefa", 2);
	AForm		*presi;
	
	print_separator();
	presi = new PresidentialPardonForm();
	print_separator();
	b1.signForm(*presi);
	print_separator();
	b1.executeForm(*presi);
	print_separator();
	return (0);
}
