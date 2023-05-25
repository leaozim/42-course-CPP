#include "ClapTrap.hpp"
#include "FragTrap.hpp"

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
	FragTrap	robot1Copy(robot1);
	FragTrap	robot2 = robot1Copy;
	FragTrap	robot3("R2-D2");
	FragTrap	robot4;
	FragTrap	robot5("Nico");

	print_header("FIGHT");
	robot1.attack(robot2.getName());
	robot2.takeDamage(robot1.getAttackDamage());
	robot2.beRepaired(6);
	robot2.highFivesGuys();

	std::cout << std::endl << std::string(93, '-') << std::endl;

	robot1Copy.highFivesGuys();
	robot2.highFivesGuys();
	robot4.highFivesGuys();

	std::cout << std::endl << std::string(93, '-') << std::endl;

	for (int i = 0; i < 100; i++) 
		robot3.attack(robot4.getName());
	robot3.attack(robot4.getName());
	robot3.beRepaired(6);

	std::cout << std::endl << std::string(93, '-') << std::endl;

	robot5.highFivesGuys();
	robot5.takeDamage(100);
	robot5.highFivesGuys();

	print_header("DESTRUCTORS");
	return(0);
}