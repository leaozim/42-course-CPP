#ifndef VALIDATOR_HPP
#define VALIDATOR_HPP

#include <iostream>
#include <stdbool.h>
#include "Defines.hpp"
struct Validator
{
	public:
		static bool	is_valid_name(std::string str);
		static bool	is_valid_input(std::string str);
		static bool	is_valid_number(std::string str);
		static bool is_valid_index(int index);
};
#endif
