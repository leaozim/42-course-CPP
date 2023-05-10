#include "PhoneBook.hpp"
#include <cstdio>
PhoneBook::PhoneBook(void) : _oldest(0) {}

PhoneBook::~PhoneBook(void) { return ; }

void PhoneBook::add_contact(Contact contact)
{
	if (_contacts.size() == 8) {
		if (_oldest == 8)
			_oldest = 0;
		_contacts[_oldest] = contact;
		_oldest++;
		std::cout << contact.get_first_name() << " - " << contact.get_last_name() << "Your contact has been added successfully!" << std::endl;
		return ;
	}
	_contacts[_contacts.size()] = contact;
	std::cout << contact.get_first_name() << " - " << contact.get_last_name() << "Your contact has been added successfully!" << std::endl;
}


void	PhoneBook::search_contact(void)
{
	std::string title = BLUE " CONTACTS LIST" RES;
    std::string separator = "=";

	if (_contacts.size() == 0)
	{
		std::cout << "Sorry, your phone book is empty!" << std::endl;
		return ;
	}
	std::cout << std::endl;
	std::cout << "|" << std::setfill('=') << std::setw(65) << "|" << std::endl;
    std::cout << std::setw(52) << std::setfill(' ') << title << std::endl;
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
	for (ContactMap::iterator it = _contacts.begin(); it != _contacts.end(); ++it) {
		int index = std::distance(_contacts.begin(), it);
		std::cout 
		<< std::setw(10) << std::setfill(' ') << index << "|"
        << std::setw(10) << std::setfill(' ') << it->second.get_first_name()  << "|"
        << std::setw(10) << std::setfill(' ') << it->second.get_last_name() << "|"
        << std::setw(10) << std::setfill(' ') << it->second.get_nickname() << "|"
        << std::setw(10) << std::setfill(' ') << it->second.get_phone_number() <<  "|"
        << std::setw(10) << std::setfill(' ') << it->second.get_darkest_secret() 
		<< std::endl
		<< std::setw(65) << std::setfill('-') << "-"
        << std::endl;
	}

}
