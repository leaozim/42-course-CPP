#include  "Zombie.hpp"

int main( void )
{
	Zombie	*walkingDead;
	
	walkingDead = newZombie("Rick");
	std::cout << DEAD_HEAP << std::endl;
	walkingDead->announce();
	std::cout << std::endl << DEAD_STACK <<std::endl;
	randomChump("Michonne");
	delete walkingDead;
	std::cout  << std::endl << DESTROYED <<std::endl;
	return (0);
}
