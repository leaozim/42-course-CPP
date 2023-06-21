#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <stdint.h>
# include <string>
# include "Data.hpp"

#define MAGENTA "\033[35m"
#define RED "\x1b[38;5;88m"
#define GREEN "\x1b[38;5;40m"
#define BLUE "\x1b[38;5;25m"
#define YELLOW "\x1b[38;5;220m"
#define ORANGE	"\033[0;38;5;166m"
#define LIGHT_PURPLE "\033[1;35m"
#define CYAN "\001\e[0;36m\002"
#define RES "\x1b[0m"

class Serializer
{

	public:
		static uintptr_t		serialize( Data* ptr );
		static Data				*deserialize( uintptr_t raw );

	private:

		Serializer();
		Serializer( Serializer const & src );
		~Serializer();
		Serializer				&operator=( Serializer const & rhs );

};


#endif /* ****************************************************** SERIALIZER_H */