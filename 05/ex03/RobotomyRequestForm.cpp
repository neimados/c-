#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm():	AForm("Robotomy", 72, 45, "Default")
{
	std::cout<<"RForm default constructor called"<<std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target): AForm("Robotomy", 72, 45, target)
{
	std::cout<<"RForm constructor called"<<std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &s): AForm(s)
{
	std::cout<<"RForm copy constructor called"<<std::endl;
}

RobotomyRequestForm	&RobotomyRequestForm::operator= (const RobotomyRequestForm &s){
	AForm::operator=(s);
	std::cout<<"RForm assignment operator called"<<std::endl;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(){
	std::cout<<"RForm destructor called"<<std::endl;
}

void	RobotomyRequestForm::execute(const Bureaucrat &b) const{
	this->check(b);
	std::cout<<"Drilling noise..."<<std::endl;
	if (rand() % 2 == 0){
		std::cout<<this->getTarget()<<" has been robotomized"<<std::endl;
	} else {
		std::cout<<"Robotomization of "<<this->getTarget()<<" failed"<<std::endl;
	}
}

AForm *RobotomyRequestForm::newRobotomy(const std::string &target){
	return new RobotomyRequestForm(target);
}