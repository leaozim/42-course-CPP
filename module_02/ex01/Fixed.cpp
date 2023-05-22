#include "Fixed.hpp"

Fixed::Fixed(void) : _rawBits(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n) : _rawBits(n * 256) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float n) : _rawBits(n * 256 + (n >= 0 ? 0.5 : -0.5)) {
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const {
	return (this->_rawBits); 
}

void Fixed::setRawBits( int const raw ) {
	this->_rawBits = raw;
}

Fixed &Fixed::operator=( const Fixed &fixed ) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed)
		this->_rawBits = fixed.getRawBits();
	return (*this);
}


float	Fixed::toFloat( void ) const {
	return ((float)this->_rawBits / 256);
}

int		Fixed::toInt( void ) const {
	return (this->_rawBits / 256);
}

std::ostream & operator<<(std::ostream &o, Fixed const &fixed) {
	o << fixed.toFloat();
	return (o);
}

const int Fixed::_fracBits = 8;
