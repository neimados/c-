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
		~ShrubberyCreationForm();

		void	execute(const Bureaucrat &executor) const;
};