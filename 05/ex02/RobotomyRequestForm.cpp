#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm():	AForm("Robotomy", 72, 45, "Default")
{
	std::cout<<"SCForm default constructor called"<<std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target): AForm("Robotomy", 72, 45, target)
{
	std::cout<<"SCForm constructor called"<<std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &s): AForm(s)
{
	std::cout<<"SCForm copy constructor called"<<std::endl;
}

RobotomyRequestForm	&RobotomyRequestForm::operator= (const RobotomyRequestForm &s){
	AForm::operator=(s);
	std::cout<<"SCForm assignment operator called"<<std::endl;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(){
	std::cout<<"SCForm destructor called"<<std::endl;
}

void	RobotomyRequestForm::execute(const Bureaucrat &b) const{
	try {
		this->check(b);
		std::cout<<"Drilling noise..."<<std::endl;
		if (rand() % 2 == 0){
			std::cout<<this->getTarget()<<" has been robotomized"<<std::endl;
		} else {
			std::cout<<"Robotomization of "<<this->getTarget()<<" failed"<<std::endl;
		}
	}
	catch(std::exception &e){
		std::cout<<e.what()<<std::endl;
	}
}