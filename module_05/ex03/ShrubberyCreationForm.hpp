#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{

	public:

		ShrubberyCreationForm();
		ShrubberyCreationForm( std::string target );
		ShrubberyCreationForm( ShrubberyCreationForm const & src );
		~ShrubberyCreationForm();

		ShrubberyCreationForm	&operator=( ShrubberyCreationForm const & rhs );

		void					execute( Bureaucrat const &executor ) const;
	
	private:

		std::string				_target;
};

#endif /* ******************************************* SHRUBBERYCREATIONFORM_H */