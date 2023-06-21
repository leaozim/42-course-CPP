#include  "Array.hpp"

void print_header(std::string str, char marker)
{
	std::cout << std::string(58, marker) << std::endl
			  << BLUE << str << RES
			  << std::endl
			  << std::string(58, marker) << std::endl;
}

void print_separator(void)
{
	std::cout << CYAN << std::string(58, '-') << RES << std::endl;
}

void	print_array_int( Array<int> &array, int delimiter)
{
	std::cout <<  "Memory address = " << &array << std::endl;
	for (int i = 0; i < SIZE_MAX; i++)
		array[i] = i + delimiter;
	for (int i = 0; i < SIZE_MAX; i++)
		std::cout << array[i] << " ";
	std::cout << std::endl;
}

void	print_array_str( Array<std::string> &array, std::string value )
{
	std::cout <<  "Memory address = " << &array << std::endl;
	for (int i = 0; i < SIZE_MAX; i++)
		array[i] = value;
	for (int i = 0; i < SIZE_MAX; i++)
		std::cout << array[i] << " ";
	std::cout << std::endl;
}

int main( void ) 
{
	{
		print_header("ARRAY INT", '=');
		Array<int> defaultArray; 
		Array<int> 	defaultArrayVAlue(SIZE_MAX); 
		Array<int> CopyArray(defaultArrayVAlue); 
		defaultArray = defaultArrayVAlue;

		print_header("Construction with an unsigned int", '~');
		print_array_int(defaultArrayVAlue, 1);

		print_header("Construction by copy operator", '~');
		print_array_int(CopyArray, 2);

		print_header("Value passed by assignment operator", '~');
		print_array_int(defaultArray, 3);

		print_header("operator [] with error", '~');
		try {
			std::cout << &defaultArrayVAlue[SIZE_OUT_OF_LIMITS] << std::endl;
		}
		catch(const std::exception& e) {
			std::cerr << e.what() <<  RANGE << "Added value "  << SIZE_OUT_OF_LIMITS << '\n';
		}
		try {
			std::cout << &CopyArray[SIZE_MAX] << std::endl;
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << RANGE << "Added value " << SIZE_MAX << '\n';
		}
		try {
			std::cout << &defaultArray[NEGATIVE_VALUE] << std::endl;
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << RANGE << "Added value " << NEGATIVE_VALUE << '\n';
		}
		print_separator();
	}
	{
		print_header("ARRAY STRING", '=');
		Array<std::string>	defaultArray; 
		Array<std::string>	defaultArrayVAlue(SIZE_MAX); 
		Array<std::string>	CopyArray(defaultArrayVAlue); 
		defaultArray = defaultArrayVAlue;

		print_header("Construction with an unsigned int", '~');
		print_array_str(defaultArrayVAlue, "Ola");

		print_header("Construction by copy operator", '~');
		print_array_str(CopyArray, "mundo");

		print_header("Value passed by assignment operator", '~');
		print_array_str(defaultArray, "!");

		print_header("operator [] with error", '~');
			try {
			std::cout << &defaultArrayVAlue[SIZE_OUT_OF_LIMITS] << std::endl;
		}
		catch(const std::exception& e) {
			std::cerr << e.what() <<  RANGE << "Added value "  << SIZE_OUT_OF_LIMITS << '\n';
		}
		try {
			std::cout << &CopyArray[SIZE_MAX] << std::endl;
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << RANGE << "Added value " << SIZE_MAX << '\n';
		}
		try {
			std::cout << &defaultArray[NEGATIVE_VALUE] << std::endl;
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << RANGE << "Added value " << NEGATIVE_VALUE << '\n';
		}
		print_separator();
	}

}
