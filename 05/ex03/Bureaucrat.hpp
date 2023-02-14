#pragma once

#include <iostream>
#include <ctime>
#include "AForm.hpp"

class Bureaucrat;
class AForm;

class Bureaucrat {
	public:
		Bureaucrat();
		Bureaucrat(const std::string name, const int grade);
		Bureaucrat(const Bureaucrat &b);
		Bureaucrat	&operator=(const Bureaucrat &b);
		~Bureaucrat();

		int			getGrade() const;
		std::string	getName() const;

		class GradeTooHighException : public std::exception{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception{
			public:
				virtual const char* what() const throw();
		};

		void	increment();
		void	decrement();
		void	signForm(AForm &f);

	private:
		std::string	const	_name;
		int					_grade;
};

std::ostream& operator<<(std::ostream &out, const Bureaucrat &b);