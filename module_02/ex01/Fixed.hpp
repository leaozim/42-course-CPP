#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed 
{
	public:
		Fixed();
		Fixed( const int n );
		Fixed( const float n );
		Fixed( Fixed const &rhs );
		~Fixed();

		Fixed	&operator=( Fixed const &fixed );
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;

	private:
		int					_rawBits;
		static const int	_fracBits;
};

std::ostream & operator<<( std::ostream &output, Fixed const &i );

#endif
