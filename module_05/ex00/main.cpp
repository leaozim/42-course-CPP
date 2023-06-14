#include "Bureaucrat.hpp"

void print_header( std::string str )
{
	std::cout << std::string(70, '=') << std::endl
			  << BLUE << str  << RES
			  << std::endl
			  << std::string(70, '=') << std::endl;
}

void	test_constructors( void )
{
	try	{
		print_header("CONSTRUCTORS");
		Bureaucrat	bureaucrat1 = Bureaucrat();
		Bureaucrat 	bureaucrat2("Manel", 5 );
		Bureaucrat 	bureaucrat3("Maria", 149 );
		std::cout << CYAN << std::string(70, '-') << RES << std::endl;
		bureaucrat1.increment();
		bureaucrat2.increment();
		bureaucrat3.increment();
		std::cout << bureaucrat1 << std::endl;
		std::cout << bureaucrat2 << std::endl;
		std::cout << bureaucrat3 << std::endl;
		bureaucrat1.decrement();
		bureaucrat2.decrement();
		bureaucrat3.decrement();
		std::cout << CYAN << std::string(70, '-') << RES << std::endl;
		std::cout << bureaucrat1 << std::endl;
		std::cout << bureaucrat2 << std::endl;
		std::cout << bureaucrat3 << std::endl;
		print_header("DESTRUCTORS");
	}
	catch (std::exception &e) {
		std::cout << e.what() << '\n';
	}
}

void	test_copy_constructor( void )
{
	try	{
		print_header("COPY CONSTRUCTOR");
		Bureaucrat	bureaucrat1 = Bureaucrat();
		Bureaucrat 	bureaucrat2(bureaucrat1);
		std::cout << CYAN << std::string(70, '-') << RES << std::endl;
		Bureaucrat 	bureaucrat3 = Bureaucrat();
		Bureaucrat 	bureaucrat4 = bureaucrat3;
		std::cout << CYAN << std::string(70, '-') << RES << std::endl;
		std::cout << bureaucrat1 << std::endl;
		std::cout << bureaucrat2 << std::endl;
		std::cout << bureaucrat3 << std::endl;
		std::cout << bureaucrat4 << std::endl;
		bureaucrat1.increment();
		bureaucrat2.decrement();
		bureaucrat3.increment();
		bureaucrat4.decrement();
		std::cout << CYAN << std::string(70, '-') << RES << std::endl;
		std::cout << bureaucrat1 << std::endl;
		std::cout << bureaucrat2 << std::endl;
		std::cout << bureaucrat3 << std::endl;
		std::cout << bureaucrat4 << std::endl;
		print_header("DESTRUCTORS");
	}
	catch (std::exception &e) {
		std::cout << e.what() << '\n';
	}
}

void	test_increment_and_decrement_with_errpr( void )
{
	try	{
		print_header("INCREMENT - High Exception");
		Bureaucrat	bureaucrat1("Zefa", 1);
		bureaucrat1.increment();
	}
	catch (std::exception &e) {
		std::cout << CYAN << std::string(70, '-') << RES << std::endl;
		std::cout << e.what() << '\n';
	}
	try	{
		print_header("DECREMENT - Low Exception");
		Bureaucrat	bureaucrat1("Zefa", 150);
		bureaucrat1.decrement();
	}
	catch (std::exception &e) {
		std::cout << CYAN << std::string(70, '-') << RES << std::endl;
		std::cout << e.what() << '\n';
	}
}

void	test_constructors_with_error( void )
{
	try	{
		print_header("CONSTRUCTOR - High Exception");
		Bureaucrat 	bureaucrat1("Sebastião", 0);
	}
	catch (std::exception &e) {
		std::cout << e.what() << '\n';
	}
	try	{
		print_header("CONSTRUCTOR - Low Exception");
		Bureaucrat	bureaucrat1("Zefa", 151);
	}
	catch (std::exception &e) {
		std::cout << e.what() << '\n';
	}
}

int main ( void ) 
{
	test_constructors();
	test_copy_constructor();
	test_increment_and_decrement_with_errpr();
	test_constructors_with_error();
	return (0);
}
