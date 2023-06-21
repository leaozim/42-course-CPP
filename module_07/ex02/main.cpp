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

void assigIntValues( Array<int> &array, int delimiter )
{
	for (int i = 0; i < SIZE_MAX; i++)
		array[i] = i + delimiter;
}

void	printArrayInt( Array<int> &array )
{
	std::cout <<  "Memory address = " << &array << std::endl;
	for (int i = 0; i < SIZE_MAX; i++)
		std::cout << array[i] << " ";
	std::cout << std::endl;
}

void	assigArrayValues( Array<std::string> &array, std::string value )
{
	std::cout <<  "Memory address = " << &array << std::endl;
	for (int i = 0; i < SIZE_MAX; i++)
		array[i] = value;
}

void	printArrayStr( Array<std::string> &array )
{
	for (int i = 0; i < SIZE_MAX; i++)
		std::cout << array[i] << " ";
	std::cout << std::endl;
}

int main( void ) 
{
	{
		print_header("ARRAY INT", '=');
		Array<int>		defaultArray; 
		Array<int>		defaultArrayValue(SIZE_MAX); 
		Array<int>		CopyArray(defaultArrayValue); 
		defaultArray = defaultArrayValue;

		print_header("Construction with an unsigned int", '~');
		assigIntValues(defaultArrayValue, 1);
		printArrayInt(defaultArrayValue);

		print_header("Construction by copy operator", '~');
		assigIntValues(CopyArray, 2);
		printArrayInt(CopyArray);

		print_header("Value passed by assignment operator", '~');
		assigIntValues(defaultArray, 3);
		printArrayInt(defaultArray);

		print_header("operator [] with error", '~');
		try {
			std::cout << &defaultArrayValue[SIZE_OUT_OF_LIMITS] << std::endl;
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
		Array<std::string>		defaultArray; 
		Array<std::string>		defaultArrayValue(SIZE_MAX); 
		Array<std::string>		CopyArray(defaultArrayValue); 
		defaultArray = defaultArrayValue;

		print_header("Construction with an unsigned int", '~');
		assigArrayValues(defaultArrayValue, "Ola");
		printArrayStr(defaultArrayValue);

		print_header("Construction by copy operator", '~');
		assigArrayValues(CopyArray, "mundo");
		printArrayStr(CopyArray);

		print_header("Value passed by assignment operator", '~');
		assigArrayValues(defaultArray, "!");
		printArrayStr(defaultArray);

		print_header("operator [] with error", '~');
			try {
			std::cout << &defaultArrayValue[SIZE_OUT_OF_LIMITS] << std::endl;
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
