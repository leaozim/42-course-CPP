#include  "easyfind.hpp"
#include <map>
#include <vector>
#include <list>

int main( void ) 
{
	std::list<int>  lst;

	std::vector<int> v = {10, 20, 30, 40, 50};

	lst.push_back(10);
    lst.push_back(44);
    lst.push_back(30);

	::easyFind(v, 44 );
	::easyFind(lst, 1 );

	
}
