#include "Base.hpp"

void printHeader( std::string str, char marker )
{
	std::cout << std::endl << 
			  std::string(70, marker) << std::endl
			  << BLUE << str << RES
			  << std::endl
			  << std::string(70, marker) << std::endl;
}

Base *generate( void )
{
	int random;

	random = std::rand() % 3;
	if (random == 1)
		return (new A);
	else if (random == 2)
		return (new B);	
	return (new C);
}

void identify(Base *p)
{
	A *a = dynamic_cast<A*>(p);
	B *b = dynamic_cast<B*>(p);
	C *c = dynamic_cast<C*>(p);
	std::cout << (a ? "A - Pointer" : 
				 (b ? "B - Pointer" : 
				 (c ? "C - Pointer" : 
				 "This class is not in my list of valid classes!\n"))) 
			  << std::endl;
}

void identify(Base &p)
{
	try
	{
		A a = dynamic_cast<A&>(p);
		std::cout <<  "A - Reference" << std::endl;
		return ;
	}	catch(...) {}
	try
	{
		B b = dynamic_cast<B&>(p);
		std::cout <<  "B - Reference" << std::endl;
		return ;
	}	catch(...) {}
	try
	{
		C c = dynamic_cast<C&>(p);
		std::cout <<  "C - Reference" << std::endl;
		return ;
	}	
	catch (...) 
	{
		std::cout << "This class is not in my list of valid classes!\n";
	}
}

int main( void )
{
	std::srand(time(NULL));
	printHeader("Generating a random class (A, B or C)", '=');
	for (int i= 0; i < 6; i++)
	{
		Base	*newBase = generate();
		std::cout << YELLOW << "Identify of pointer: " << RES;
		identify(newBase);
		std::cout << YELLOW << "Identify of reference: " << RES;
		identify(*newBase);
		delete newBase;
		std::cout << CYAN << std::string(70, '-') << RES << std::endl;
	}
	printHeader("ERROR", '=');
	{
		Base newBase;
		std::cout << YELLOW << "Identify of pointer: " << RES;
		identify(&newBase);
		std::cout << YELLOW << "Identify of reference: " << RES;
		identify(newBase);
	}

}