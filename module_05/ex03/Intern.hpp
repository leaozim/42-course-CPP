#ifndef INTERN_HPP
# define INTERN_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#define NUM_FORMS 3

class Intern
{

	public:

		Intern();
		Intern( Intern const & src );
		~Intern();
		AForm					*makeForm( std::string name, std::string target );
		Intern &				operator=( Intern const &rhs );


	private:

		struct mappedFunction
		{
			std::string			name;
 			AForm				*(Intern::*form)( std::string target, std::string );
		};
		mappedFunction			_funcions[NUM_FORMS];

		AForm					*_makeShrubberyCreationForm( std::string target, std::string name );
		AForm					*_makeRobotomyRequestForm( std::string target, std::string name );
		AForm					*_makePresidentialPardonForm( std::string target, std::string name );
};


#endif /* ********************************************************** INTERN_H */