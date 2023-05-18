#include "Weapon.hpp"
#include  "HumanA.hpp"
#include  "HumanB.hpp"

int main( void )
{
	std::cout << std::string(48, '=') << std::endl;
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	std::cout << std::string(48, '-') << std::endl;
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.attack();
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	std::cout << std::string(48, '=') << std::endl;
	return 0;
}
