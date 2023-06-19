#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>
# include <string>

class Data
{

	public:

		Data();
		Data( Data const & src );
		~Data();

		Data				&operator=( Data const & rhs );

		std::string			getName( void ) const;

	private:
		std::string			_name;

};

std::ostream &			operator<<( std::ostream & o, Data const & i );

#endif /* ************************************************************ DATA_H */