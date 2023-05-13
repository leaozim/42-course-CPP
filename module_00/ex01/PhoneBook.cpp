#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) :  _size(0), _oldest(0) {}

PhoneBook::~PhoneBook(void) { return ; }

bool	PhoneBook::create_input(std::string cmd, std::string &input, bool (*is_valid)(std::string))
{	
	std::string user_input;

	while (true)
	{
		std::cout << cmd;
		std::getline(std::cin, user_input);
		if (std::cin.eof() || std::cin.fail())
			return (false);
		if (is_valid(user_input))
		{
			input = user_input;
			return (true);
		}
	}
	return (false);
}

void PhoneBook::fill_contacts(std::string input[], int id)
{
		this->_contacts[id].set_first_name(input[0]);
		this->_contacts[id].set_last_name(input[1]);
		this->_contacts[id].set_nickname(input[2]);
		this->_contacts[id].set_phone_number(input[3]);
		this->_contacts[id].set_darkest_secret(input[4]);
}

void	PhoneBook::add_contact(void)
{	
	std::string input[5];

	if (create_input(NAME, input[0], Validator::is_valid_name) &&
		create_input(L_NAME, input[1], Validator::is_valid_name) &&
		create_input(NICK, input[2], Validator::is_valid_input) &&
		create_input(NUMBER, input[3], Validator::is_valid_number) &&
		create_input(SECRET, input[4], Validator::is_valid_input))
		{
			if (this->_size == MAX_CONTACTS) {
				if (this->_oldest == MAX_CONTACTS)
					this->_oldest = 0;
				fill_contacts(input, _oldest);
				this->_oldest++;
				std::cout << CONTATCT_ADD << BR;
				return ;
		}
		fill_contacts(input, _size);
		if (_size < 8)
			this->_size++;
		std::cout << CONTATCT_ADD << BR;
	}
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

void	PhoneBook::display_header(void)
{
	std::cout << PIPE << std::string(42, EQUALS) << PIPE << BR;
	std::cout << std::setw(41) << std::setfill(SPACE) << TITLE << BR;
	std::cout << PIPE << std::string(42, EQUALS) << PIPE << BR;
	std::cout << YELLOW
			  << std::setw(10) << ID			<< PIPE
			  << std::setw(10) << FT_NAME		<< PIPE
			  << std::setw(10) << LT_NAME		<< PIPE
			  << std::setw(10) << NICKNAME		
			  << RES 
			  << BR;
	std::cout << std::string(43, HYPHEN)  << BR;
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
				  << std::setw(10) << truncated_str(this->_contacts[i].get_nickname())
				  << BR
				  << std::string(43, HYPHEN)
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
	if (std::cin.eof() || std::cin.fail()) {
		std::cin.clear();
		return ;
	}
	index = index_str[0] - '0';
	if (index < this->_size && index >=0) {
		std::cout << std::string(45, HYPHEN)  << BR;
		std::cout << INDEX	<< index << BR
				  << NAME	<< this->_contacts[index].get_first_name()		<< BR
				  << L_NAME	<< this->_contacts[index].get_last_name() 		<< BR
				  << NICK	<< this->_contacts[index].get_nickname()		<< BR
				  << NUMBER << this->_contacts[index].get_phone_number()	<< BR
				  << SECRET << this->_contacts[index].get_darkest_secret()	<< BR;
	}
	else 
		std::cout << ERROR_INDEX << BR;
	index_str.clear();
	std::cin.clear();
	std::cout.clear();
}

void	PhoneBook::display_menu(int option)
{
	if (option == WELCOME)
	{
		std::cout << PIPE << std::string(41, EQUALS) << PIPE << BR;
		std::cout << std::setw(47) << std::setfill(SPACE) << WELCOME_MSG << BR;
		std::cout << PIPE << std::string(41, EQUALS) << PIPE << BR;
	}
	else
		std::cout << std::string(43, HYPHEN) << BR;
	std::cout << YELLOW << std::setw(31) << std::setfill(SPACE) << OPTIONS_MSG << RES << BR;
	std::cout << std::string(43, HYPHEN) << BR;
}