#ifndef PHONE_BOOK_H
# define PHONE_BOOK_H

#include "Contact.hpp"
#include "Validator.hpp"
#include <iomanip>
#include <map>

typedef std::map<int, Contact> ContactMap;
struct PhoneBook
{
	public: 
		PhoneBook ( void );
		~PhoneBook ( void );
		void					add_contact( Contact contact );
		void					search_contact(void);
		void					exit(void);

	private:
		std::map<int, Contact>	_contacts;
		int						_oldest;
};

#endif