#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon 
{
	public:
		Weapon();
		Weapon( std::string name );
		~Weapon();
		std::string		get_zombie_name( void );
		void			set_zombie_name( std::string name);
		void			announce( void );

	private:
		std::string		_name;
};


#endif