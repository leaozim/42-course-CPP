#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <string>

# define MAGENTA "\033[35m"
# define RED "\x1b[38;5;88m"
# define GREEN "\x1b[38;5;40m"
# define BLUE "\x1b[38;5;25m"
# define YELLOW "\x1b[38;5;220m"
# define ORANGE	"\033[0;38;5;166m"
# define LIGHT_PURPLE "\033[1;35m"
# define CYAN "\001\e[0;36m\002"
# define RES "\x1b[0m"
#define RANGE "Valid values = 0 - 4 | "
#define SIZE_MAX 5
#define SIZE_OUT_OF_LIMITS 6
#define NEGATIVE_VALUE - 1

void					print_description(std::string str) {
	std::cout << ORANGE << "ARRAY" << RES 
			  << " = " 
			  << str
			  << std::endl;
}

template <typename T>
class Array
{
	private:
		T					*_elements;
		unsigned int		_n;
public:

	Array() : _elements(NULL), _n(0) {
		print_description("Default constructor called");
	}

	Array(unsigned int n) : _n(n) {
		_elements = new T[n];
		print_description("N constructor called");
	}

	Array(const Array& src) : _n(src._n) {
		_elements = new T[_n];
		for (unsigned int i = 0; i < _n; i++)
			_elements[i] = src._elements[i];
		print_description("Copy constructor called");
	}

	~Array() {
		delete[] _elements;
		print_description("Default destructor called");
	}

	Array&	operator=(const Array& src) {
		if (this != &src) {
			_n = src.size();
			delete[] _elements;
			_elements = new T[_n]();
			for (unsigned int i = 0; i < _n; i++)
				_elements[i] = src._elements[i];
			print_description("Copy assignment operator called");
		}
		return (*this);
	}

	T		&operator[](size_t index)  {
		if (index >= _n) { throw RangeException(); }
		return _elements[index];
	}

	size_t	size() const {
		return _n;
	}

	class	RangeException : public std::exception	{
		public:
			virtual const char	*what(void) const throw() {
				return ("Index out of range! ");\
			}
	};

};

#endif /* ******************************************************** ARRAY_H */