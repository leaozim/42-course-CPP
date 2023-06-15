#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{

	public:

		RobotomyRequestForm();
		RobotomyRequestForm( std::string target );
		RobotomyRequestForm( RobotomyRequestForm const & src );
		virtual ~RobotomyRequestForm();

		RobotomyRequestForm &	operator=( RobotomyRequestForm const & rhs );

		void					execute( Bureaucrat const &executor ) const;
		void					print_description( std::string str, std::string color );

	private:

		std::string				_target;
		static bool				_seedHasBeenGenerated;

};

#endif /* ********************************************* ROBOTOMYREQUESTFORM_H */