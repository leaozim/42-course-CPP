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
		Zombie();
		Zombie( std::string name );
		~Zombie();
		std::string		get_zombie_name( void );
		void			set_zombie_name( std::string name);
		void			announce( void );

	private:
		std::string		_name;
};

Zombie* zombieHorde( int N, std::string name );

#endif
