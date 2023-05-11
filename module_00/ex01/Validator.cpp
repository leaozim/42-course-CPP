#include "Validator.hpp"

bool Validator::is_valid_name(std::string str) {
	if (str.empty())
		return (false);
	for (int i = 0; str[i]; i++)
		if (!isalpha(str[i]) && !isspace(str[i]))
			return (false);
	return (true);
}

bool Validator::is_valid_input(std::string str) {
	if (str.empty())
		return (false);
	for (int i = 0; str[i]; i++)
		if (!isalpha(str[i]) && !isdigit(str[i]) && !isspace(str[i]))
			return (false);
	return (true);
}

bool Validator::is_valid_number(std::string str) {
	if (str.empty())
		return (false);
	for (int i = 0; str[i]; i++)
		if (!isdigit(str[i]) && !isspace(str[i]))
			return (false);
	return (true);
}
