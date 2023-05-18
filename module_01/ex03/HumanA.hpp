#ifndef HUMANA_HPP
#define HUMANA_HPP

#include  "Weapon.hpp"
#include <string>
#include <iostream>

class HumanA 
{
	public:
		HumanA( std::string name, Weapon const& weapon );
		~HumanA();
		void	attack( void );

	private:
		std::string		_name;
		Weapon const&	_weapon;
};

#endif
