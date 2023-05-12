#include "Contact.hpp"

Contact::Contact(void ) {std::cout << "CONSTRUTOR DO CONTATO\n";}

// Contact::Contact(std::string name, std::string last_name, std::string nickname,
// 				std::string phone_number, std::string darkest_secret):
// 				_first_name(name), _last_name(last_name), _nickname(nickname),
// 				_phone_number(phone_number), _darkest_secret(darkest_secret) {}

Contact::~Contact(void) { std::cout << "fui cgamado\n"; return ; }

void	Contact::set_first_name( std::string first_name ) {
	_first_name = first_name;
}

void	Contact::set_last_name( std::string last_name ) {
	_last_name = last_name;
}

void	Contact::set_nickname( std::string nickname ) {
	_nickname = nickname;
}

void	Contact::set_phone_number( std::string phone_numbe ) {
	 _phone_number = phone_numbe;
}

void	Contact::set_darkest_secret( std::string darkest_secret ) {
	_darkest_secret = darkest_secret;
}

std::string Contact::get_first_name(void) const { return this->_first_name; }

std::string Contact::get_last_name(void) const { return this->_last_name; }

std::string Contact::get_nickname(void) const { return this->_nickname; }

std::string Contact::get_phone_number(void) const { return this->_phone_number; }

std::string Contact::get_darkest_secret(void)const { return this->_darkest_secret; }




// std::string Contact::create_input(std::string cmd, std::string msg_error, bool (*is_valid)(std::string))
// {	
// 	std::string input;

// 	input.clear();
// 	while (true)
// 	{
// 		std::cout << cmd;
// 		std::getline(std::cin, input);
// 		if (std::cin.eof() || std::cin.fail())
// 		{
// 			this->~Contact();
// 			exit(0);
// 		}
// 		if (is_valid(input))
// 			return (input);
// 		else std::cout << msg_error << std::endl;
// 	}
// 	this->~Contact();
// 	return (NULL);
// }

// Contact Contact::create_contatc(void)
// {
// 	std::string first_name, last_name, nickname, phone_number, darkest_secret;

// 	first_name = create_input(NAME, ERROR_NAME, Validator::is_valid_name);
// 	last_name = create_input(L_NAME, ERROR_NAME, Validator::is_valid_name);
// 	nickname = create_input(NICK, ERROR_INPUT, Validator::is_valid_input);
// 	phone_number = create_input(NUMBER, ERROR_NUMBER, Validator::is_valid_number);
// 	darkest_secret = create_input(SECRET, ERROR_INPUT,Validator::is_valid_input);

// 	return Contact(first_name, last_name, nickname, phone_number, darkest_secret);
// }
