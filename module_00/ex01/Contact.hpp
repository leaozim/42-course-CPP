#ifndef CONTACT_H
# define CONTACT_H

#include <iostream>
#include <stdlib.h>
struct Contact
{
	public:
		Contact( void );
		Contact(std::string name, std::string last_name, std::string nickname, 
			std::string phone_number, std::string darkest_secret);
		~Contact ( void );
		std::string			get_first_name( void ) const;
		std::string			get_last_name( void ) const;
		std::string			get_nickname( void ) const;
		std::string			get_phone_number( void ) const;
		std::string			get_darkest_secret( void ) const;
		static Contact		create_contatc(void);

	private:
		std::string			_first_name;
		std::string			_last_name;
		std::string			_nickname;
		std::string			_phone_number;
		std::string			_darkest_secret;
};

#endif