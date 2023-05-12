#ifndef PHONE_BOOK_H
# define PHONE_BOOK_H

#include "Contact.hpp"
#include <iomanip>
#include <string>

struct PhoneBook
{
	public:
		PhoneBook ( void );
		~PhoneBook ( void );
		void					add_contact( void );
		void					search_contact( void );
		void					display_menu( int option );
		void					display_header( void );
		void					display_list( void );
		void					display_index( void );
		std::string				truncated_str( std::string str );
		void					fill_contacts(std::string input[], int id);
		bool					create_input( std::string cmd, std::string &input, 
											bool (*is_valid)(std::string) );

	private:
		Contact					_contacts[8];
		int						_size;
		int						_oldest;
};

#endif