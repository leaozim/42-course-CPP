#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

#define MAGENTA "\033[35m"
#define RED "\x1b[38;5;88m"
#define GREEN "\x1b[38;5;40m"
#define BLUE "\x1b[38;5;25m"
#define YELLOW "\x1b[38;5;220m"
#define ORANGE	"\033[0;38;5;166m"
#define LIGHT_PURPLE "\033[1;35m"
#define CYAN "\001\e[0;36m\002"
#define RES "\x1b[0m"

class Bureaucrat;

class AForm
{

	public:

		AForm();
		AForm( std::string name, int gradeSign, int gradeExecute );
		AForm( AForm const &src );
		~AForm();

		AForm					&operator=( AForm const &rhs );

		void					checkExecute( Bureaucrat const &executor ) const;
		virtual void			execute( Bureaucrat const &executor ) const = 0;
		void					beSigned( Bureaucrat &bureaucrat );
		int						getGradeExecute (void ) const;
		int						getGradeSign (void ) const;
		bool					getIsSigned( void ) const;
		std::string				getName( void ) const;
		virtual void			print_description( std::string str, std::string color );

		class GradeTooHighException: public std::exception {
			virtual const char	*what( void ) const throw();
		};
		class GradeTooLowException: public std::exception {
			virtual const char	*what( void ) const throw();
		};
		class NotSignedException: public std::exception {
			virtual const char	*what( void ) const throw();
		};
		class AlreadySignedException: public std::exception {
			virtual const char	*what( void ) const throw();
		};

	private:
	
		const std::string		_name;
		bool					_isSigned;
		const int				_gradeSign;
		const int				_gradeExecute;

};

std::ostream			&operator<<( std::ostream &o, AForm const &i );

#endif /* ************************************************************ FORM_H */