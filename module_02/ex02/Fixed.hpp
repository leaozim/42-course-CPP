#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#define RED "\x1b[38;5;88m"
#define GREEN "\x1b[38;5;40m"
#define BLUE "\x1b[38;5;25m"
#define YELLOW "\x1b[38;5;220m"
#define RES "\x1b[0m"

class Fixed 
{
	public:
		Fixed();
		Fixed( const int n );
		Fixed( const float n );
		Fixed( Fixed const & copy );
		~Fixed();

		Fixed & operator=( Fixed const & fixed );
		Fixed operator+(Fixed const & fixed) const;
		Fixed operator-(Fixed const & fixed) const;
		Fixed operator*(Fixed const & fixed) const;
		Fixed operator/(Fixed const & fixed) const;

		bool operator>(Fixed const & fixed) const;
		bool operator<(Fixed const & fixed) const;
		bool operator>=(Fixed const & fixed) const;
		bool operator<=(Fixed const & fixed) const;
		bool operator==(Fixed const & fixed) const;
		bool operator!=(Fixed const & fixed) const;

		Fixed & operator++( void );
		Fixed operator++( int );
		Fixed & operator--( void );
		Fixed operator--( int );

		static Fixed & max( Fixed &fixed1, Fixed &fixed2);
		static const Fixed & max( Fixed const &fixed1, Fixed const &fixed2);
		static Fixed & min( Fixed &fixed1, Fixed &fixed2);
		static const Fixed & min( Fixed const &fixed1, Fixed const &fixed2);

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;


	private:
		int					_rawBits;
		static const int	_fracBits;
};

std::ostream & operator<<(std::ostream &o, Fixed const &fixed);

#endif
