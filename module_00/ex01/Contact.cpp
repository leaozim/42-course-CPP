#include "Contact.hpp"

Contact::Contact( void ) {}

Contact::~Contact( void ) {}

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

std::string Contact::get_first_name( void ) const { return this->_first_name; }

std::string Contact::get_last_name( void ) const { return this->_last_name; }

std::string Contact::get_nickname( void ) const { return this->_nickname; }

std::string Contact::get_phone_number( void ) const { return this->_phone_number; }

std::string Contact::get_darkest_secret( void )const { return this->_darkest_secret; }
