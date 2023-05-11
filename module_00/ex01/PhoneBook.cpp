#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) : _size(0), _oldest(0) {}

PhoneBook::~PhoneBook(void) { return ; }

void	PhoneBook::add_contact(Contact contact)
{
	if (this->_size == MAX_CONTACTS) {
		if (this->_oldest == MAX_CONTACTS)
			this->_oldest = 0;
		this->_contacts[_oldest] = contact;
		this->_oldest++;
		std::cout << contact.get_first_name() << " - " << CONTATCT_ADD << std::endl;
		return ;
	}
	this->_contacts[this->_size++] = contact;
	std::cout << contact.get_first_name() << " - " << CONTATCT_ADD << std::endl;
}

std::string	PhoneBook::truncated_str(std::string str)
{
	if (str.length() > 10)
	{
		str.insert(9, ".");
		str.erase(str.begin() + 10, str.end());
	}
	return (str);
}

void	PhoneBook::phonebook_header_print(void)
{
	std::cout << "|" << std::string(63, '=') << "|" << "\n";
	std::cout << std::setw(52) << std::setfill(' ') << TITLE << "\n";
	std::cout << "|" << std::string(63, '=') << "|" << "\n";
	std::cout << RED
			  << std::setw(10) << "Index" << "|"
			  << std::setw(10) << "First name" << "|"
			  << std::setw(10) << "Last Name"  << "|"
			  << std::setw(10) << "Nickname" << "|"
			  << std::setw(10) << "Number" << "|"
			  << std::setw(10) << "Secret"
			  << RES 
			  << "\n";
	std::cout << std::string(65, '-')  << "\n";
}

void	PhoneBook::phonebook_list_print(void)
{
	for (int i = 0; i < this->_size; i++) {
		std::cout << std::setw(10) << i << "|"
				  << std::setw(10) << truncated_str(this->_contacts[i].get_first_name()) << "|"
				  << std::setw(10) << truncated_str(this->_contacts[i].get_last_name()) << "|"
				  << std::setw(10) << truncated_str(this->_contacts[i].get_nickname()) << "|"
				  << std::setw(10) << truncated_str(this->_contacts[i].get_phone_number()) << "|"
				  << std::setw(10) << truncated_str(this->_contacts[i].get_darkest_secret()) 
				  << "\n"
				  << std::string(65, '-')
				  << "\n";
	}
}
void	PhoneBook::phonebook_index_print(void)
{
	std::string	index_str;
	int			index;

	std::cout << INDEX_TO_SEE;
	std::cin >> index_str;

	index = index_str[0] - '0';
	if (index < this->_size && index >=0) {
		std::cout << std::string(65, '-')  << "\n";
		std::cout << INDEX  << index << "\n"
				  << NAME   << this->_contacts[index].get_first_name()     << "\n"
				  << L_NAME << this->_contacts[index].get_last_name()      << "\n"
				  << NICK   << this->_contacts[index].get_nickname()       << "\n"
				  << NUMBER << this->_contacts[index].get_phone_number()   << "\n"
				  << SECRET << this->_contacts[index].get_darkest_secret() << "\n";
		std::cout << std::string(65, '-')  << "\n";
	}
	else 
		std::cout << ERROR_INDEX << std::endl;
}

void	PhoneBook::search_contact(void)
{
	if (this->_size == 0)
	{
		std::cout << LIST_IS_EMPTY << std::endl;
		return ;
	}
	this->phonebook_header_print();
	this->phonebook_list_print();
	this->phonebook_index_print();
	return ;
}