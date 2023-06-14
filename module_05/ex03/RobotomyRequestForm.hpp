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

	private:

		std::string				_target;
		static bool				_seedHasBeenGenerated;

};

#endif /* ********************************************* ROBOTOMYREQUESTFORM_H */