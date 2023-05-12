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
		void					add_contact( Contact contact );
		void					search_contact(void);
		std::string				truncated_str(std::string str);
		void					display_menu(int option);
		void					display_header(void);
		void					display_list(void);
		void					display_index(void);

	private:
		Contact					_contacts[8];
		int						_size;
		int						_oldest;
};

#endif