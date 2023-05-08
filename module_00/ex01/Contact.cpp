#include "Contact.hpp"

Contact::Contact(void) {
	_first_name = "";
	_last_name = "";
	_nickname = "";
	_phone_number = "";
	_darkest_secret = "";
}

Contact::~Contact(void){
	return ;
}

void Contact::set_first_name(std::string _first_name) {
	this->_first_name = _first_name;
}

void Contact::set_last_name(std::string _last_name) {
	this->_last_name = _last_name;
}

void Contact::set_nickname(std::string _nickname) {
	this->_nickname = _nickname;
}

void Contact::set_phone_number(std::string _phone_number) {
	this->_phone_number = _phone_number;
}

void Contact::set_darkest_secret(std::string _darkest_secret) {
	this->_darkest_secret = _darkest_secret;
}

std::string Contact::get_first_name(void) {
	return this->_first_name;
}

std::string Contact::get_last_name(void) {
	return this->_last_name;
}

std::string Contact::get_nickname(void) {
	return this->_nickname;
}

std::string Contact::get_phone_number(void) {
	return this->_phone_number;
}

std::string Contact::get_darkest_secret(void) {
	return this->_darkest_secret;
}
