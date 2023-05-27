#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>
#include <iostream>

class Weapon 
{
	public:
		Weapon( );
		Weapon( std::string type );
		~Weapon( );
		std::string const	&getType( void ) const;
		void				setType( std::string type);

	private:
		std::string			_type;
};

#endif