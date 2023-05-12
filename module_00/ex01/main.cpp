#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook	phone_book;
	std::string	input;

	phone_book.display_menu(WELCOME);
	while (42)
	{
		std:: getline(std::cin, input); 
		if (std::cin.eof() || std::cin.fail()) {
			std::cin.clear();
			input.clear();
			break ;
		}
		if (input.empty()) {
			std::cin.clear();
			input.clear();
		}
		if (input == ADD) {
			phone_book.add_contact();
		}
		else if (input == SEARCH) {
			phone_book.search_contact();
			continue;
		}
		else if (input == EXIT) {
			break ;
		}
		phone_book.display_menu(OPTIONS);
	}
	return (0);
}