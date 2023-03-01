#pragma once

# include "AForm.hpp"
# include <cstdlib>

class RobotomyRequestForm: public AForm
{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string &target);
		RobotomyRequestForm(const RobotomyRequestForm &s);
		RobotomyRequestForm &operator= (const RobotomyRequestForm &s);
		virtual ~RobotomyRequestForm();

		void	execute(const Bureaucrat &executor) const;
};