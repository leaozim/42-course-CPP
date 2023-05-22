#include "Fixed.hpp"

Fixed::Fixed(void) : _rawBits(0){
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n) : _rawBits(n){
	std::cout << "Parametric constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_rawBits); 
}

void Fixed::setRawBits( int const raw ){ 
	this->_rawBits = raw;
}

Fixed &Fixed::operator=( const Fixed &fixed ) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed)
		this->_rawBits = fixed.getRawBits();
	return (*this);
}

const int Fixed::_fracBits = 8;
