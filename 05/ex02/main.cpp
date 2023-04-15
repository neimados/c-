#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>

int	main(void){

	srand(time(0));
	Bureaucrat a("aaa", 1);
	Bureaucrat b("bbb", 140);
	ShrubberyCreationForm s("Jardin");
	ShrubberyCreationForm s2(s);
	RobotomyRequestForm r("ChatGPT");
	PresidentialPardonForm p("Sorry");

	// AForm	s();
	// AForm	s2(*s);

	std::cout<<std::endl;
	std::cout<<s<<std::endl;
	std::cout<<s2<<std::endl;

	std::cout<<std::endl;
	std::cout<<s2.getTarget()<<std::endl;
	try{
		s.beSigned(a);
		a.executeForm(s);
	}
	catch(std::exception &e){
		std::cout<<e.what()<<std::endl;
	}

	std::cout<<std::endl;
	try{
		r.beSigned(a);
		r.execute(a);
	}
	catch(std::exception &e){
		std::cout<<e.what()<<std::endl;
	}

	std::cout<<std::endl;
	try {
		p.beSigned(a);
		p.execute(b);
	}
	catch(std::exception &e){
		std::cout<<e.what()<<std::endl;
	}

	std::cout<<std::endl;
	return 0;
}