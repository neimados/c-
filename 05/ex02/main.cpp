#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>

int	main(void){

	srand(time(0));
	Bureaucrat	*a = new Bureaucrat("aaa", 1);	
	Bureaucrat	*b = new Bureaucrat("bbb", 140);
	ShrubberyCreationForm	*s  = new ShrubberyCreationForm("Jardin");
	ShrubberyCreationForm	*s2 = new ShrubberyCreationForm(*s);
	RobotomyRequestForm		*r = new RobotomyRequestForm("ChatGPT");
	PresidentialPardonForm	*p = new PresidentialPardonForm("Sorry");

	// AForm	*s = new AForm();
	// AForm	*s2 = new AForm(*s);

	std::cout<<std::endl;
	std::cout<<*s<<std::endl;
	delete s;
	std::cout<<*s2<<std::endl;

	std::cout<<std::endl;
	std::cout<<s2->getTarget()<<std::endl;
	try{
		s2->beSigned(*a);
		s2->execute(*b);
	}
	catch(std::exception &e){
		std::cout<<e.what()<<std::endl;
	}

	std::cout<<std::endl;
	try{
		r->beSigned(*a);
		r->execute(*a);
	}
	catch(std::exception &e){
		std::cout<<e.what()<<std::endl;
	}

	std::cout<<std::endl;
	try {
		p->beSigned(*a);
		p->execute(*b);
	}
	catch(std::exception &e){
		std::cout<<e.what()<<std::endl;
	}

	std::cout<<std::endl;
	delete s2;
	delete r;
	delete a;
	delete b;
	delete p;

	return 0;
}