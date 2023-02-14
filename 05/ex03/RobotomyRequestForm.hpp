#pragma once

#include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string &target);
		RobotomyRequestForm(const RobotomyRequestForm &s);
		RobotomyRequestForm &operator= (const RobotomyRequestForm &s);
		~RobotomyRequestForm();

		void			execute(const Bureaucrat &executor) const;
		static AForm	*newRobotomy(const std::string &target);
};