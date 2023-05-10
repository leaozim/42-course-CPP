#ifndef VALIDATOR_HPP
#define VALIDATOR_HPP

#define RED "\x1b[38;5;88m"
#define BLUE "\x1b[38;5;25m"
#define RES "\x1b[0m"

#include <iostream>
#include <stdbool.h>

struct Validator
{
	public:
		bool	is_valid_name(std::string str);
		bool	is_valid_message(std::string str);
		bool	is_valid_number(std::string str);
};
#endif
