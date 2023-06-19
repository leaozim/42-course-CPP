#include "Base.hpp"

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
				 (c ? "C - Pointer" : ""))) 
			  << std::endl;
}

void identify(Base &p)
{
	try
	{
		A a = dynamic_cast<A&>(p);
		std::cout <<  "A - Reference" << std::endl;
	}	catch(const std::exception& e) {}
	try
	{
		B b = dynamic_cast<B&>(p);
		std::cout <<  "B - Reference" << std::endl;
	}	catch(const std::exception& e) {}
	try
	{
		C c = dynamic_cast<C&>(p);
		std::cout <<  "C - Reference" << std::endl;
	}	catch(const std::exception& e) {}
}

int main( void )
{
	std::srand(time(NULL));
	for (int i= 0; i < 6; i++)
	{
		std::cout << CYAN << std::string(20, '-') << RES << std::endl;
		Base	*newBase = generate();
		Base	&baseRef = *newBase;

		identify(newBase);
		identify(baseRef);
		delete newBase;
		std::cout << CYAN << std::string(20, '-') << RES << std::endl;
	}
}