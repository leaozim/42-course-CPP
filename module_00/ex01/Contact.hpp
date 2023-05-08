#ifndef CONTACT_H
# define CONTACT_H

#include <iostream>

struct Contact
{
	public:
		Contact( void );
		~Contact ( void );

		void set_first_name( std::string _first_name );
		void set_last_name( std::string _last_name );
		void set_nickname( std::string _nickname );
		void set_phone_number( std::string _phone_number );
		void set_darkest_secret( std::string _darkest_secret );

		std::string get_first_name( void );
		std::string get_last_name( void );
		std::string get_nickname( void );
		std::string get_phone_number( void );
		std::string get_darkest_secret( void );

	private:
		std::string	_first_name;
		std::string	_last_name;
		std::string	_nickname;
		std::string	_phone_number;
		std::string	_darkest_secret;
};

#endif