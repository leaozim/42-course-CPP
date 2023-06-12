#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
#include "AForm.hpp"

#define MAGENTA "\033[35m"
#define RED "\x1b[38;5;88m"
#define GREEN "\x1b[38;5;40m"
#define BLUE "\x1b[38;5;25m"
#define YELLOW "\x1b[38;5;220m"
#define ORANGE	"\033[0;38;5;166m"
#define LIGHT_PURPLE "\033[1;35m"
#define CYAN "\001\e[0;36m\002"
#define RES "\x1b[0m"
#define MAX_GRADE 1
#define MIN_GRADE 150

class AForm;

class Bureaucrat
{

	public:

		Bureaucrat();
		Bureaucrat( Bureaucrat const &src );
		Bureaucrat( std::string name, int grade );
		~Bureaucrat();
		Bureaucrat				&operator=( Bureaucrat const &rhs );

		void					executeForm( AForm const & form );
		void					increment( void );
		void					decrement( void );
		int						getGrade( void ) const;
		std::string				getName( void ) const;
		void					signForm( AForm &form );
		void					print_description( std::string str, std::string color );

		class GradeTooHighException: public std::exception {
			virtual const char	*what( void ) const throw();
		};
		class GradeTooLowException: public std::exception {
			virtual const char	*what( void ) const throw();
		};

	private:
		const std::string		_name;
		int						_grade;
};

std::ostream					&operator<<( std::ostream &o, Bureaucrat const &i );

#endif /* ****************************************************** BUREAUCRAT_H */