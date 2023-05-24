#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

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
	ScavTrap	robot1Copy(robot1);
	ScavTrap	robot2 = robot1Copy;
	ScavTrap	robot3("R2-D2");
	ScavTrap	robot4;

	print_header("FIGHT SCAV TRAP");
	robot1.attack(robot2.getName());
	robot2.takeDamage(robot1.getAttackDamage());
	robot2.beRepaired(6);

	std::cout << std::endl << std::string(60, '-') << std::endl;

	for (int i = 0; i < 10; i++) 
		robot3.attack(robot4.getName());
	robot3.attack(robot4.getName());
	robot3.beRepaired(6);

	print_header("DESTRUCTORS");
	return(0);
}