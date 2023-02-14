#pragma once

#include "Bureaucrat.hpp"

class Bureaucrat;
class AForm;


class AForm {
	public:
		AForm();
		AForm(const std::string &name, const int signReq, const int execReq, const std::string &target);
		AForm(const AForm &f);
		AForm &operator=(const AForm &f);
		~AForm();

		class GradeTooHighException : public std::exception{
			public: 
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception{
			public:
				virtual const char* what() const throw();
		};
		class NotSigned : public std::exception{
			public:
				virtual const char* what() const throw();
		};

		const std::string	getName() const;
		bool				getSigned() const;
		const int			getSignReq() const;
		const int			getExecReq() const;
		const std::string	getTarget() const;

		void			beSigned(const Bureaucrat &b);
		virtual void	execute(const Bureaucrat &executor) const = 0;
		void			check(const Bureaucrat &b) const;

	private:
		const std::string	_name;
		bool				_signed;
		const int			_signReq;
		const int			_execReq;
		std::string			_target;
};

std::ostream& operator<<(std::ostream &out, const AForm &f);