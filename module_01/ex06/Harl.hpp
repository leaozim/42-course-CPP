#ifndef HARL_HPP
#define HARL_HPP

#include <string>
#include <iostream>
#include <iomanip>

#define RED "\x1b[38;5;88m"
#define GREEN "\x1b[38;5;40m"
#define BLUE "\x1b[38;5;25m"
#define YELLOW "\x1b[38;5;220m"
#define RES "\x1b[0m"
#define USAGE "Usage: ./harlFilter FILTER"


class Harl 
{
	public:
		Harl();
		Harl( std::string name );
		~Harl();
		void complain( std::string level );

	private:
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );

		struct mappedFunction
		{
			std::string		nivel;
 			void			(Harl::*funcao)();
		};
		mappedFunction		funcions[4];
		
};

#endif