#include  "Fixed.hpp"

static void print_header(std::string str)
{
	std::cout << YELLOW << std::string(22, '=') << RES << std::endl;
	std::cout << RED << str << RES << std::endl;
	std::cout << YELLOW << std::string(22, '=') << RES << std::endl;
}

int main( void ) 
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed fixed1(3.5f);
	Fixed fixed2(2);
	Fixed fixed3(3);
	Fixed const fixed4(1);
	Fixed const fixed5(3);
	Fixed f(5);
	Fixed fcopy(5);

	print_header("Subject Test");
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	print_header("Comparison Operators");
	std::cout << std::boolalpha;
	std::cout << (fixed1 < fixed2) << std::endl;
	std::cout << (fixed1 > fixed2) << std::endl;
	std::cout << (fixed1 <= fixed2) << std::endl;
	std::cout << (fixed1 >= fixed2) << std::endl;
	std::cout << (fixed1 == fixed2) << std::endl;
	std::cout << (fixed1 != fixed2) << std::endl;
	std::cout << YELLOW << std::string(20, '-') << RES << std::endl;
	std::cout << (fixed3 < fixed3) << std::endl;
	std::cout << (fixed3 > fixed3) << std::endl;
	std::cout << (fixed3 <= fixed3) << std::endl;
	std::cout << (fixed3 >= fixed3) << std::endl;
	std::cout << (fixed3 == fixed3) << std::endl;
	std::cout << (fixed3 != fixed3) << std::endl;
	std::cout << std::noboolalpha;
	print_header("Arithmetic Operators");
	std::cout << fixed1 << " + " << fixed2 << " = " << fixed1 + fixed2 << std::endl;
	std::cout << fixed1 << " - " << fixed2 <<  " = " << fixed1 - fixed2 << std::endl;
	std::cout << fixed1 << " * " << fixed2 <<  " = " << fixed1 * fixed2 << std::endl;
	std::cout << fixed1 << " / " << fixed2 <<  " = " <<  fixed1 / fixed2 << std::endl;
	print_header("Increment");
	std::cout << f << std::endl;
	std::cout << fcopy << std::endl;
	std::cout << ++f << std::endl;
	std::cout << fcopy++ << std::endl;
	std::cout << f << std::endl;
	std::cout << fcopy << std::endl;
	print_header("Decrement");
	std::cout << f << std::endl;
	std::cout << fcopy << std::endl;
	std::cout << --f << std::endl;
	std::cout << fcopy-- << std::endl;
	std::cout << f << std::endl;
	std::cout << fcopy << std::endl;
	print_header("Max");
	std::cout << Fixed::max(fixed1, fixed2) << std::endl;
	std::cout << Fixed::max(fixed4, fixed5) << std::endl;
	print_header("Min");
	std::cout << Fixed::min(fixed1, fixed2) << std::endl;
	std::cout << Fixed::min(fixed5, fixed4) << std::endl;
	return 0;
}
