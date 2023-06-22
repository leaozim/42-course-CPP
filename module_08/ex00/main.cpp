#include  "easyfind.hpp"

void printHeader(std::string str, char marker)
{
	std::cout << std::string(58, marker) << std::endl
			  << BLUE << str << RES
			  << std::endl
			  << std::string(58, marker) << std::endl;
}

int main( void ) 
{
	printHeader("TEST VECTOR",  '=');
	try	{
		std::vector<int>			vector(5, 1);
		std::vector<int>::iterator	valueFind;

		valueFind = ::easyFind(vector, 1);
		std::cout << *valueFind << std::endl;
		valueFind = ::easyFind(vector, 5);
		std::cout << *valueFind << std::endl;
	}
	catch (const std::out_of_range& e) {
		std::cout << "Erro: " << e.what() << std::endl;
	}
	printHeader("TEST VECTOR",  '=');
	try	{
		std::list<int>				lst;
		std::list<int>::iterator	valueFind;

		lst.push_back(10);
		lst.push_back(44);
		lst.push_back(30);
		valueFind = ::easyFind(lst, 44 );
		std::cout << *valueFind << std::endl;
		valueFind = ::easyFind(lst, 1 );
		std::cout << *valueFind << std::endl;
	}
	catch (const std::out_of_range& e) {
		std::cout << "Erro: " << e.what() << std::endl;
	}
	printHeader("TEST DEQUE",  '=');
	try	{
		std::deque<int>				deque;
		std::deque<int>::iterator	valueFind;

		for (int i = 0; i < 5; i++)
			deque.push_back(i + 1 * 2);
		valueFind = ::easyFind(deque, 4 );
		std::cout << *valueFind << std::endl;
		valueFind = ::easyFind(deque, 1 );
		std::cout << *valueFind << std::endl;
	}
	catch (const std::out_of_range& e) {
		std::cout << "Erro: " << e.what() << std::endl;
	}
}
