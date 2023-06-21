#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>
# include <string>
# include <cstdlib> 

#define MAGENTA "\033[35m"
#define RED "\x1b[38;5;88m"
#define GREEN "\x1b[38;5;40m"
#define BLUE "\x1b[38;5;25m"
#define YELLOW "\x1b[38;5;220m"
#define ORANGE	"\033[0;38;5;166m"
#define LIGHT_PURPLE "\033[1;35m"
#define CYAN "\001\e[0;36m\002"
#define RES "\x1b[0m"

class Base
{
	public:
		virtual ~Base();
};

class A : public Base { public: A(){
	std::cout<< ORANGE<<"Class A = "<<RES<<"Default constructor\n";}; };
class B : public Base { public: B(){
	std::cout<<ORANGE<<"Class B = "<<RES <<"Default constructor\n";}; };
class C : public Base { public: C(){
	std::cout<<ORANGE<<"Class C = "<<RES <<"Default constructor\n";}; };

#endif /* ************************************************************ BASE_H */