#pragma once

#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string &target);
		ShrubberyCreationForm(const ShrubberyCreationForm &s);
		ShrubberyCreationForm &operator= (const ShrubberyCreationForm &s);
		virtual ~ShrubberyCreationForm();

		void			execute(const Bureaucrat &executor) const;
		static AForm	*newShrubbery(const std::string &target);
};