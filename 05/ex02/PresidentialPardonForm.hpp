#pragma once

#include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string &target);
		PresidentialPardonForm(const PresidentialPardonForm &s);
		PresidentialPardonForm &operator= (const PresidentialPardonForm &s);
		virtual ~PresidentialPardonForm();

		void	execute(const Bureaucrat &executor) const;
};