#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main(void){
	Intern	i;
	Intern	i2(i);
	AForm	*sForm;
	AForm	*rForm;
	AForm	*pForm;

	try{
		std::cout<<std::endl;
		sForm = i.makeForm("shrubbery creation", "Bibi");
		std::cout<<sForm->getTarget()<<std::endl;
		rForm = i.makeForm("robotomy request", "Bender");
		std::cout<<rForm->getTarget()<<std::endl;
		pForm = i2.makeForm("presidential pardon", "Kiki");
		std::cout<<pForm->getTarget()<<std::endl;
		std::cout<<std::endl;
	}
	catch(std::exception &e){
		std::cout<<e.what()<<std::endl;
	}
	
	delete sForm;
	delete rForm;
	delete pForm;
	
	std::cout<<std::endl;
	return 0;
}