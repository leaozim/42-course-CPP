#include  "RPN.hpp"

// int main( int argc, char **argv )
// {
// 	RPN	rpn;

// 	rpn.invertedPolish(argc, argv);
// }

void printHeader(const std::string& str, char marker, const char* color)
{
	int	padding = 4;
	int	totalWidth = 60;
	int	strWidth = str.size();
	int	margin = (totalWidth - strWidth - 2 * padding) / 2;

	std::string marginStr(margin, ' ');

	std::cout << std::string(totalWidth, marker) << std::endl
			  << marginStr 
			  << std::string(padding, ' ') 
			  << color << str << RES 
			  << std::string(padding, ' ') 
			  << marginStr << std::endl
			  << std::string(totalWidth, marker) << std::endl;
}

void printSeparator(void)
{
	std::cout << CYAN << std::string(60, '-') << RES << std::endl;
}

void runTest(const std::string& input, const std::string& expectedResult) {
    RPN	rpn;
    char	*argv[] = {const_cast<char*>("program"), const_cast<char*>(input.c_str())};
    int		argc = sizeof(argv) / sizeof(argv[0]);

    std::cout << "Input: " << input << std::endl;
    std::cout << "Expected Result: " << expectedResult << std::endl;
    std::cout << "Actual Result: ";
    rpn.invertedPolish(argc, argv);
    printSeparator();
    std::cout << std::endl;

}

int main() {
	printHeader("Tets Subject", '=', ORANGE);
	runTest("8 9 * 9 - 9 - 9 - 4 - 1 +", "42");
	runTest("7 7 * 7 -", "42");
	runTest("1 2 * 2 / 2 * 2 4 - +", "0");
	runTest("(1 + 1)", "Error");


	printHeader("Valid expression", '=', ORANGE);    
	runTest("5 3 +", "8");
    runTest("5 2 -", "3");
    runTest("5 2 *", "10");
    runTest("4 2 * 3 - 5 +", "10");
	runTest("8 4 / 2 * 6 2 + -", "-4");

	printHeader("Invalid expression", '=', ORANGE);
    std::cout << "Invalid expression" << std::endl;
    runTest("5 +", "Error");

    std::cout << "Invalid number range" << std::endl;
    runTest("11 3 +", "Error");

	std::cout << "Invalid number range" << std::endl;
    runTest("11 -2 +", "Error");

    std::cout << "Empty expression" << std::endl;
    runTest("", "Error");

    std::cout << "Division by zero" << std::endl;
    runTest("5 0 /", "Error");
    return 0;
}