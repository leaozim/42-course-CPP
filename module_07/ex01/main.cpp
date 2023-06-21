#include  "iter.hpp"

int main( void ) 
{
	print_header("NUMERIC DATA TYPES", '~');
	{
		const int	array[4] = { 1, 2, 3, 5 };
		std::cout << MAGENTA <<"Int: " << RES;
		::iter(array, 4, printValue);
	}
	print_separator();
	{
		float		array[3] = { 2, 3.0, 4 };
		std::cout << MAGENTA <<"Float: " << RES;
		::iter(array, 3, printNumber);
	}
	print_separator();
	{
		double		array[3] = { 2, 3.0, 4 };
		std::cout << MAGENTA <<"Double: " << RES;
		::iter(array, 3, printNumber);
	}
	print_header("STRING", '~');
	{
		std::string	array[3] = { "oLa,", "MuNdO", "!" };
		std::cout << MAGENTA <<"String: " << RES;
		::iter(array, 3, printValue);
	}
	print_separator();
	{
		std::string	array[3] = { "oLa,", "MuNdO", "!" };
		std::cout << MAGENTA <<"String: " << RES;
		::iter(array, 3, upperCase);
	}
	print_separator();
	{
		std::string	array[3] = { "oLa,", "MuNdO", "!" };
		std::cout << MAGENTA <<"String: " << RES;
		::iter(array, 3, lowerCase);
		for (int i = 0; i < 3; i++)
			printValue(array[i]);
	}
	print_header("TEST WITH FUNCTIONS WITH THROWING ERROR", '~');
	{
		const double		array[3] = { 2, 3.0, 4 };
		::iter(array, 3, upperCase);
	}
	print_separator();
	{
		int			array[3] = { 2, 3, 4 };
		::iter(array, 3, lowerCase);
	}
	return 0;
}