#include "ClapTrap.hpp"

static void print_header(std::string str)
{
	std::cout << BLUE << std::string(60, '=') << RES << std::endl;
	std::cout << MAGENTA << str << RES << std::endl;
	std::cout << BLUE << std::string(60, '=') << RES << std::endl;
}

int main( void )
{
	print_header("CONSTRUCTORS");
	ClapTrap	robot1("Emily");
	ClapTrap	robot2("Nico");
	ClapTrap	robot1Copy(robot1);
	ClapTrap	robot2Copy = robot2;
	ClapTrap	robot3("R2-D2");
	ClapTrap	robot4;


	print_header("FIGHT");
	robot1.attack(robot2.getName());
	robot2.takeDamage(robot1.getAttackDamage());
	robot2.beRepaired(6);

	std::cout << std::endl << std::string(60, '-') << std::endl;
	
	robot2Copy.attack(robot1Copy.getName());
	robot1Copy.takeDamage(robot2Copy.getAttackDamage());
	robot1Copy.beRepaired(3);

	std::cout << std::endl << std::string(60, '-') << std::endl;

	for (int i = 0; i < 10; i++) 
		robot3.attack(robot4.getName());
	robot3.attack(robot4.getName());
	robot3.beRepaired(6);

	print_header("DESTRUCTORS");
	return(0);
}