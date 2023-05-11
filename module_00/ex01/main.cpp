#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook	phone_book;
	std::string	input;


	while (42)
	{
		
		std::cout << "Allowed operations: ADD, SEARCH, or EXIT" << std::endl;
		std:: getline(std::cin, input); 
		if (input == "ADD") {
			phone_book.add_contact(Contact::create_contatc());
			continue ;
		}
		else if (input == "SEARCH") {
			phone_book.search_contact();
			continue ;
		}
		else if (input == "EXIT") {
			break ;
		}
		else {
			std::cout << "COMANDO INVALIDO" << std::endl;
		}
		if (std::cin.eof() || std::cin.fail()) {
			break ;
		}
		if (input.empty()) {
			input.clear();
			std::cin.clear();
		}
	}
	phone_book.~PhoneBook();
	return (0);
}