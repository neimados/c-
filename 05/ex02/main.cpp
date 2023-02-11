#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int	main(void){

	srand(time(0));
	Bureaucrat	*a = new Bureaucrat("aaa", 10);	
	Bureaucrat	*b = new Bureaucrat("bbb", 140);
	ShrubberyCreationForm	*s  = new ShrubberyCreationForm("Jardin");
	ShrubberyCreationForm	*s2 = new ShrubberyCreationForm(*s);
	RobotomyRequestForm		*r = new RobotomyRequestForm("ChatGPT");

	// AForm	*s = new AForm();
	// AForm	*s2 = new AForm(*s);

	std::cout<<std::endl;
	std::cout<<*s<<std::endl;
	delete s;
	std::cout<<*s2<<std::endl;

	std::cout<<std::endl;
	std::cout<<s2->getTarget()<<std::endl;
	s2->beSigned(*a);
	s2->execute(*b);

	std::cout<<std::endl;
	r->beSigned(*a);
	r->execute(*a);

	std::cout<<std::endl;
	delete s2;
	delete r;
	delete a;
	delete b;

	return 0;
}