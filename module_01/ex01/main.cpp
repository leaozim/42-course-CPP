#include  "Zombie.hpp"

int main()
{
	Zombie	*walkingDead;
	int		size = 6;
	
	walkingDead = zombieHorde(size, "Michone");
	for (int i = 0; i < size; i++)
		walkingDead[i].announce();
	delete [] walkingDead;
	return (0);
}
