#include "Harl.hpp"

Harl::Harl() {
	funcions[0].nivel = "DEBUG";
	funcions[0].funcao = &Harl::debug;
	funcions[1].nivel = "INFO";
	funcions[1].funcao = &Harl::info;
	funcions[2].nivel = "WARNING";
	funcions[2].funcao = &Harl::warning;
	funcions[3].nivel = "ERROR";
	funcions[3].funcao = &Harl::error;
}

Harl::~Harl() {}

void Harl::debug() {
	std::cout
		<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
		<< std::endl;
}

void Harl::info() {
	std::cout
		<< "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!"
		<< std::endl;
}

void Harl::warning() {
	std::cout
		<< "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month."
		<< std::endl;
}

void Harl::error() {
	std::cout
		<< "This is unacceptable! I want to speak to the manager now."
		<< std::endl;
}

void Harl::complain(std::string level) {
	for (std::size_t i = 0; i < 4; ++i) {
		if (level == funcions[i].nivel) {
			(this->*funcions[i].funcao)();
			return;
		}
	}
	std::cout << "This level does not exist" << std::endl;
}



