#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

#define RED "\x1b[38;5;88m"
#define YELLOW "\x1b[38;5;220m"
#define RES "\x1b[0m"
#define DEAD_HEAP RED << "Oh no! There is a walking dead in the heap!" << RES
#define DEAD_STACK RED << "Oh no! There is a walking dead in the stack!" << RES
#define DESTROYED YELLOW << "Phew! all were destroyed!" << RES

class Zombie 
{
	public:
		Zombie( std::string name );
		~Zombie();
		std::string 	get_zombie_name( void );
		void			announce( void );

	private:
		std::string		_name;
};

void	randomChump( std::string name );
Zombie	*newZombie( std::string name );

#endif
