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
		std::cout << CONTATCT_ADD << BR;
		return ;
	}
	this->_contacts[this->_size++] = contact;
	std::cout << CONTATCT_ADD << BR;
}

void	PhoneBook::search_contact(void)
{
	if (this->_size == 0)
	{
		std::cout << LIST_IS_EMPTY << BR;
		return ;
	}
	this->display_header();
	this->display_list();
	this->display_index();
	return ;
}

void	PhoneBook::display_menu(int option)
{
	if (option == WELCOME)
	{
		std::cout << PIPE << std::string(63, EQUALS) << PIPE << BR;
		std::cout << std::setw(43) << std::setfill(SPACE) << WELCOME_MSG << BR;
		std::cout << PIPE << std::string(63, EQUALS) << PIPE << BR;
	}
	else
		std::cout << std::string(65, HYPHEN) << BR;
	std::cout << std::setw(40) << std::setfill(SPACE) << OPTIONS_MSG << BR;
	std::cout << std::string(65, HYPHEN) << BR;
}

void	PhoneBook::display_header(void)
{
	std::cout << PIPE << std::string(63, EQUALS) << PIPE << BR;
	std::cout << std::setw(52) << std::setfill(SPACE) << TITLE << BR;
	std::cout << PIPE << std::string(63, EQUALS) << PIPE << BR;
	std::cout << RED
			  << std::setw(10) << ID			<< PIPE
			  << std::setw(10) << FT_NAME		<< PIPE
			  << std::setw(10) << LT_NAME		<< PIPE
			  << std::setw(10) << NICKNAME		<< PIPE
			  << std::setw(10) << PHO_NUMBER	<< PIPE
			  << std::setw(10) << DARK_SECRET
			  << RES 
			  << BR;
	std::cout << std::string(65, HYPHEN)  << BR;
	std::cout.clear();
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

void	PhoneBook::display_list(void)
{
	for (int i = 0; i < this->_size; i++) {
		std::cout << std::setw(10) << i << PIPE
				  << std::setw(10) << truncated_str(this->_contacts[i].get_first_name())	<< PIPE
				  << std::setw(10) << truncated_str(this->_contacts[i].get_last_name())		<< PIPE
				  << std::setw(10) << truncated_str(this->_contacts[i].get_nickname())		<< PIPE
				  << std::setw(10) << truncated_str(this->_contacts[i].get_phone_number())	<< PIPE
				  << std::setw(10) << truncated_str(this->_contacts[i].get_darkest_secret()) 
				  << BR
				  << std::string(65, HYPHEN)
				  << BR;
	}
	std::cout.clear();
}

void	PhoneBook::display_index(void)
{
	std::string	index_str;
	int			index;

	std::cout << INDEX_TO_SEE;
	std::cin >> index_str;
	index = index_str[0] - '0';
	if (index < this->_size && index >=0) {
		std::cout << std::string(65, HYPHEN)  << BR;
		std::cout << INDEX	<< index << BR
				  << NAME	<< this->_contacts[index].get_first_name()		<< BR
				  << L_NAME	<< this->_contacts[index].get_last_name() 		<< BR
				  << NICK	<< this->_contacts[index].get_nickname()		<< BR
				  << NUMBER	<< this->_contacts[index].get_phone_number()	<< BR
				  << SECRET	<< this->_contacts[index].get_darkest_secret()	<< BR;
	}
	else 
		std::cout << ERROR_INDEX << BR;
	index_str.clear();
	std::cin.clear();
	std::cout.clear();
}
