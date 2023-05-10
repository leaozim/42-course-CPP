#include "Contact.hpp"

Contact::Contact(void) {}

Contact::Contact(std::string name, std::string last_name, std::string nickname,
				std::string phone_number, std::string darkest_secret):
				_first_name(name), _last_name(last_name), _nickname(nickname),
				_phone_number(phone_number), _darkest_secret(darkest_secret) {}

Contact::~Contact(void) { return ; }

std::string Contact::get_first_name(void) const { return this->_first_name; }

std::string Contact::get_last_name(void) const { return this->_last_name; }

std::string Contact::get_nickname(void) const { return this->_nickname; }

std::string Contact::get_phone_number(void) const { return this->_phone_number; }

std::string Contact::get_darkest_secret(void)const { return this->_darkest_secret; }


std::string  Contact::create_input(std::string cmd, std::string msg_error,	bool (*is_valid)(std::string))
{	
	std::string input;

	while (true)
	{
		if (std::cin.eof() || std::cin.fail())
			exit (0);
		std::cout << cmd;
		std::getline(std::cin, input);
		if (is_valid(input))
			return (input);
		else std::cout << msg_error << std::endl;
	}
	return (NULL);
}

Contact Contact::create_contatc(void)
{
	std::string first_name, last_name, nickname, phone_number, darkest_secret;

	first_name = create_input(NAME, ERROR_NAME, Validator::is_valid_name);
	last_name = create_input(L_NAME, ERROR_NAME, Validator::is_valid_name);
	nickname = create_input(NICK, ERROR_INPUT, Validator::is_valid_input);
	phone_number = create_input(NUMBER, ERROR_NUMBER, Validator::is_valid_number);
	darkest_secret = create_input(SECRET, ERROR_INPUT,Validator::is_valid_input);

	return Contact(first_name, last_name, nickname, phone_number, darkest_secret);
}