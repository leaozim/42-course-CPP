#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

static void print_header(std::string str)
{
	std::cout << BLUE << std::string(93, '=') << RES << std::endl;
	std::cout << MAGENTA << str << RES << std::endl;
	std::cout << BLUE << std::string(93, '=') << RES << std::endl;
}

int main( void )
{
	print_header("CONSTRUCTORS");
	ClapTrap	robot1("Emily");
	ScavTrap	robot1Copy(robot1);
	ScavTrap	robot2 = robot1Copy;
	ScavTrap	robot3("R2-D2");
	ScavTrap	robot4;
	ScavTrap	robot5("Nico");

	print_header("FIGHT");
	robot1.attack(robot2.getName());
	robot2.takeDamage(robot1.getAttackDamage());
	robot2.beRepaired(6);
	robot2.guardGate();

	std::cout << std::endl << std::string(93, '-') << std::endl;

	robot1Copy.guardGate();
	robot2.guardGate();
	robot4.guardGate();

	std::cout << std::endl << std::string(93, '-') << std::endl;

	for (int i = 0; i < 50; i++) 
		robot3.attack(robot4.getName());
	robot3.attack(robot4.getName());
	robot3.beRepaired(6);
	
	std::cout << std::endl << std::string(93, '-') << std::endl;

	robot5.guardGate();
	robot5.takeDamage(100);
	robot5.guardGate();

	print_header("DESTRUCTORS");
	return(0);
}