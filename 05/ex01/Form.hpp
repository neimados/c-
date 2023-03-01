#pragma once

#include "Bureaucrat.hpp"

class Bureaucrat;
class Form;


class Form {
	public:
		Form();
		Form(const std::string name, const int signReq, const int execReq);
		Form(const Form &f);
		Form &operator=(const Form &f);
		~Form();

		class GradeTooHighException : public std::exception{
			public: 
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception{
			public:
				virtual const char* what() const throw();
		};

		const std::string	getName() const;
		bool				getSigned() const;
		int					getSignReq() const;
		int					getExecReq() const;

		void	beSigned(const Bureaucrat &b);

	private:
		const std::string	_name;
		bool				_signed;
		const int			_signReq;
		const int			_execReq;
};

std::ostream& operator<<(std::ostream &out, const Form &f);