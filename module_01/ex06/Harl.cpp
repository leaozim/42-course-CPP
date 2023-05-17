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
	std::cout << "[ DEBUG ] \n"
		<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger.\n" 
		<< "I really do!"
		<< std::endl
		<< std::endl;

}

void Harl::info() {
	std::cout << "[ INFO ] \n"
		<< "I cannot believe adding extra bacon costs more money. \n"
		<< "You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!"
		<< std::endl
		<< std::endl;
}

void Harl::warning() {
	std::cout << "[ WARNING ] \n"
		<< "I think I deserve to have some extra bacon for free. \n"
		<< "I've been coming for years whereas you started working her1e since last month."
		<< std::endl
		<< std::endl;
}

void Harl::error() {
	std::cout << "[ ERROR ] \n"
		<< "This is unacceptable! I want to speak to the manager now."
		<< std::endl
		<< std::endl;
}

void Harl::complain(std::string level) {
	int numLevel= 0;

	for (int i = 0; i < 4 && level != funcions[i].nivel; ++i)
		numLevel++;
	switch (numLevel)
	{
		case 0:
			(this->*funcions[0].funcao)();
			/* Falls through. */
		case 1:
			(this->*funcions[1].funcao)();
			/* Falls through. */
		case 2:
			(this->*funcions[2].funcao)();
			/* Falls through. */
		case 3:
			(this->*funcions[3].funcao)();
			break ;
		default:
			std::cout << "I am not sure how tired I am today..." << std::endl;
	}
}



