#include "ScalarConverter.hpp"

// int main( int argc, char **argv )
// {
// 	if (argc != 2)
// 		return (std::cout <<  "Invalid number of arguments!" << std::endl, 1);
// 	ScalarConverter::convert(argv[1]);
// }

// void print_header( std::string str, char marker )
// {
// 	std::cout << std::endl << 
// 			  std::string(20, marker) << std::endl
// 			  << str
// 			  << std::endl
// 			  << std::string(20, marker) << std::endl;
// }

// void print_separator( void )
// {
// 	std::cout << std::endl << CYAN << std::string(20, '-') << RES << std::endl;
// }

// int	main (void)
// {
// 	const char*		char_tests[] = {"a", "#",  "", "-", "+","ola", NULL };
// 	const char*		int_tests[] = {"2147483648", "-2147483649", "42", "0", "-0", "+10", "127", "666", NULL };
// 	const char*		float_tests[] = {"-2.2f", "nanf", "-inff", "+inff", "1...0f", NULL };
// 	const char*		double_tests[] = {"1.54546465", "0.65454154544","4.2", "-4.2", "nan", "-inf", "+inf", "42.42", "1...0f", NULL };

// 	print_header("CHAR", '=');
// 	for (int i = 0; char_tests[i]; i++)
// 	{
// 		std::cout << "[" << char_tests[i] << "]\n";
// 		ScalarConverter::convert(char_tests[i]);
// 		print_separator();
// 	}

// 	print_header("INT", '=');
// 	for (int i = 0; int_tests[i]; i++)
// 	{
// 		ScalarConverter::convert(int_tests[i]);
// 		print_separator();
// 	}

// 	print_header("FLOAT", '=');
// 	for (int i = 0; float_tests[i]; i++)
// 	{
// 		std::cout << "[" << float_tests[i] << "]\n";
// 		ScalarConverter::convert(float_tests[i]);
// 		print_separator();
// 	}

// 	print_header("DOUBLE", '=');
// 	for (int i = 0; double_tests[i]; i++)
// 	{
// 		std::cout << "[" << double_tests[i] << "]\n";
// 		ScalarConverter::convert(double_tests[i]);
// 		print_separator();
// 	}
// 	return (0);
// }
