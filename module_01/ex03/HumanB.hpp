#ifndef HUMANB_HPP
#define HUMANB_HPP

#include  "Weapon.hpp"
#include <string>
#include <iostream>

class HumanB 
{
	public:
		HumanB();
		HumanB( std::string name );
		~HumanB();
		void			setWeapon( Weapon& weapon );
		void			attack( void );

	private:
		std::string	_name;
		Weapon		*_weapon;

};

#endif
