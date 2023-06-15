#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{

	public:

		ShrubberyCreationForm();
		ShrubberyCreationForm( std::string target );
		ShrubberyCreationForm( ShrubberyCreationForm const & src );
		virtual ~ShrubberyCreationForm();

		ShrubberyCreationForm	&operator=( ShrubberyCreationForm const & rhs );

		void					execute( Bureaucrat const &executor ) const;
		void					print_description( std::string str, std::string color );
	
	private:

		std::string				_target;
};


#endif /* ******************************************* SHRUBBERYCREATIONFORM_H */