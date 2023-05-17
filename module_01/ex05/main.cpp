#include "Harl.hpp"

static	void print_format(std::string level)
{
	std::cout << std::string(150, '-') << std::endl;
	std::cout << YELLOW << level << " :" << RES << std::endl;

}

int	main(void)
{
	Harl harl;

	print_format("DEBUG");
	harl.complain("DEBUG");

	print_format("INFO");
	harl.complain("INFO");

	print_format("WARNING");
	harl.complain("WARNING");

	print_format("ERROR");
	harl.complain("ERROR");

	print_format("INVALID");
	harl.complain("INVALID");
}
