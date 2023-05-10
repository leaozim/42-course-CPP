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

Contact Contact::create_contatc(void)
{
	std::string first_name, last_name, nickname, phone_number, darkest_secret;

	while (first_name.empty())
	{
		std::cout << "First name: ";
   	 	std::getline(std::cin, first_name);
    	// first_name = if (validator.name(first_name));
   		 if (!first_name.empty() || std::cin.fail())
      		break ;
    }
	while (last_name.empty())
	{
		std::cout << "Last name: ";
   	 	std::getline(std::cin, last_name);
    	// last_name = valid_name(last_name);
   		 if (!last_name.empty() || std::cin.fail())  
      		break ;
    }
	while (nickname.empty())
	{
		std::cout << "Nickname: ";
   	 	std::getline(std::cin, nickname);
    	// nickname = valid_name(nickname);
   		 if (!nickname.empty() || std::cin.fail()) 
      		break ;
    }
	while (phone_number.empty())
	{
		std::cout << "Phone Number: ";
   	 	std::getline(std::cin, phone_number);
    	// phone_number = valid_name(phone_number);
   		 if (!phone_number.empty() || std::cin.fail()) 
      		break ;
    }
	while (darkest_secret.empty() )
	{
		std::cout << "Darkest Secret: ";
   	 	std::getline(std::cin, darkest_secret);
    	// darkest_secret = valid_name(darkest_secret);
   		 if (!darkest_secret.empty() || std::cin.fail()) 
      		break ;
    }
	if (std::cin.fail()) {
		exit(0);
	}
	return Contact(first_name, last_name, nickname, phone_number, darkest_secret);
}