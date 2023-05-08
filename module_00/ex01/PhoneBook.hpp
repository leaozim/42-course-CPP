#ifndef PHONE_BOOK_H
# define PHONE_BOOK_H

# include "Contact.hpp"

struct PhoneBook
{
	public: 
		PhoneBook( void );
		~PhoneBook ( void );
		
		void	add_contac(void);
		void	search_contact(void);

	private:
		Contact	_contacts[8];
};

#endif