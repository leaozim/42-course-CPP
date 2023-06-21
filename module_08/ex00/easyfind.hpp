#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <string>

template <typename T>
void easyFind(T& container, int value)
{
    typename T::iterator itr = container.begin();
    typename T::iterator end = container.end();

	while (itr != end)
	{

		if (*itr == value)
		{
			std::cout << value << std::endl;
			return ;
		}
		    ++itr;

	}
	std::cout << "not found" << std::endl;
}
#endif /* ******************************************************** EASYFIND_H */