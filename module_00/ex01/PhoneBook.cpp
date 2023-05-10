#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) : _size(0), _oldest(0) {}

PhoneBook::~PhoneBook(void) { return ; }


#define MAX_CONTACT 3
void PhoneBook::add_contact(Contact contact)
{
	if (this->_size == MAX_CONTACT) {
		if (this->_oldest == MAX_CONTACT)
			this->_oldest = 0;
		this->_contacts[_oldest] = contact;
		this->_oldest++;
		std::cout << contact.get_first_name() << " - " << contact.get_last_name() << "Your contact has been added successfully!" << std::endl;
		return ;
	}
	this->_contacts[this->_size++] = contact;
	std::cout << contact.get_first_name() << " - " << contact.get_last_name() << "Your contact has been added successfully!" << std::endl;
}


void	PhoneBook::search_contact(void)
{
	if (this->_size == 0)
	{
		std::cout << LIST_IS_EMPTY << std::endl;
		return ;
	}
	std::cout << std::endl;
	std::cout << "|" << std::setfill('=') << std::setw(65) << "|" << std::endl;
	std::cout << std::setw(52) << std::setfill(' ') << TITLE << std::endl;
	std::cout << "|" << std::setfill ('=') << std::setw(65) << "|" << std::endl;
	std::cout << RED << "     Index" << RES << "| ";
	std::cout << RED << "Firt name" << RES << "| ";
	std::cout << RED << "Last Name"  << RES << "|";
	std::cout << RED << "  Nickname" << RES << "| ";
	std::cout << RED << "   Number" << RES << "| ";
	std::cout << RED << "   Secret" << RES;
	std::cout << std::endl;
	std::cout << std::setw(65) << std::setfill('-') << "-";
	std::cout << std::endl;
	for (int i = 0; i < this->_size; i++) {
		std::cout 
		<< std::setw(10) << std::setfill(' ') << i << "|"
		<< std::setw(10) << std::setfill(' ') << this->_contacts[i].get_first_name()  << "|"
		<< std::setw(10) << std::setfill(' ') << this->_contacts[i].get_last_name() << "|"
		<< std::setw(10) << std::setfill(' ') << this->_contacts[i].get_nickname() << "|"
		<< std::setw(10) << std::setfill(' ') << this->_contacts[i].get_phone_number() <<  "|"
		<< std::setw(10) << std::setfill(' ') << this->_contacts[i].get_darkest_secret() 
		<< std::endl
		<< std::setw(65) << std::setfill('-') << "-"
		<< std::endl;
	}

}
