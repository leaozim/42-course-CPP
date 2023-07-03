#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>
# include <stdexcept>
# include <vector>
# include <deque>
# include <list>

# define MAGENTA "\033[35m"
# define RED "\x1b[38;5;88m"
# define GREEN "\x1b[38;5;40m"
# define BLUE "\x1b[38;5;25m"
# define YELLOW "\x1b[38;5;220m"
# define ORANGE	"\033[0;38;5;166m"
# define LIGHT_PURPLE "\033[1;35m"
# define CYAN "\001\e[0;36m\002"
# define RES "\x1b[0m"

template <typename T>
typename T::iterator easyFind(T& elements, int value)
{
    typename T::iterator    itr = find(elements.begin(), elements.end(), value);

    if (itr == elements.end())
        throw  std::out_of_range("Value not found");
    return (itr);
}

#endif /* ******************************************************** EASYFIND_H */