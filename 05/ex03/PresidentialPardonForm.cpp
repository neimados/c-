#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm():	AForm("Presidential", 25, 5, "Default")
{
	std::cout<<"PPForm default constructor called"<<std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target): AForm("Presidential", 25, 5, target)
{
	std::cout<<"PPForm constructor called"<<std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &s): AForm(s)
{
	std::cout<<"PPForm copy constructor called"<<std::endl;
}

PresidentialPardonForm	&PresidentialPardonForm::operator= (const PresidentialPardonForm &s){
	AForm::operator=(s);
	std::cout<<"PPForm assignment operator called"<<std::endl;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(){
	std::cout<<"PPForm destructor called"<<std::endl;
}

void	PresidentialPardonForm::execute(const Bureaucrat &b) const{
	this->check(b);
	std::cout<<this->getTarget()<<" has been pardoned by Zaphod Beeblebrox."<<std::endl;
}

AForm	*PresidentialPardonForm::newPresidential(const std::string &target){
	return new PresidentialPardonForm(target);
}