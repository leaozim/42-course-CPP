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
		void					exit(void);
		std::string				truncated_str(std::string str);
		void					phonebook_header_print(void);
		void					phonebook_list_print(void);
		void					phonebook_index_print(void);

	private:
		Contact					_contacts[8];
		int						_size;
		int						_oldest;
};

#endif