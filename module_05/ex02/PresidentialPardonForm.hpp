#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{

	public:

		PresidentialPardonForm();
		PresidentialPardonForm( std::string target );
		PresidentialPardonForm( PresidentialPardonForm const & src );
		~PresidentialPardonForm();

		PresidentialPardonForm	&operator=( PresidentialPardonForm const & rhs );

		void					execute( Bureaucrat const &executor ) const;
		void					print_description( std::string str, std::string color );

	private:

		std::string				_target;

};

#endif /* ****************************************** PRESIDENTIALPARDONFORM_H */