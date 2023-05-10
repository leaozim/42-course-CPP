#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook	phone_book;
	std::string	input;

	std::cout << "Allowed operations: ADD (1), SEARCH (2), or EXIT (3)" << std::endl;
	while (42)
	{
		std:: getline(std::cin, input); 
		if (input == "1" || input == "ADD" || input == "add")
			phone_book.add_contact(Contact::create_contatc());
		else if (input == "2" || input == "SEARCH" || input == "search")
			phone_book.search_contact();
		else if (input == "3" || input == "EXIT" || input ==  "exit")
			break ;
	}
	phone_book.~PhoneBook();
	return (0);
}