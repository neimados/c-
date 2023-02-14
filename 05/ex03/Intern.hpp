#pragma once

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
	public:
		Intern();
		Intern(const Intern &i);
		Intern &operator= (const Intern &i);
		~Intern();

		AForm *makeForm(const std::string &form, const std::string &target);

		class NotExist : public std::exception{
			public:
				virtual const char* what() const throw();
		};
};