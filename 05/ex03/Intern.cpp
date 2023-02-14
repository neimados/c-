#include "Intern.hpp"

Intern::Intern(){
	std::cout<<"Intern constructor called"<<std::endl;
}

Intern::Intern(const Intern &i){
	std::cout<<"Intern copy constructor called"<<std::endl;
	*this = i;
}

Intern &Intern::operator= (const Intern &i){
	std::cout<<"Intern assignment operator called"<<std::endl;
	return *this;
}

Intern::~Intern(){
	std::cout<<"Intern destructor called"<<std::endl;
}

AForm *Intern::makeForm(const std::string &form, const std::string &target){
	std::string forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm* (*fn[3])(const std::string &target);
	fn[0] = &ShrubberyCreationForm::newShrubbery;
	fn[1] = &RobotomyRequestForm::newRobotomy;
	fn[2] = &PresidentialPardonForm::newPresidential;

	for (int i = 0; i < 3; i++){
		if (form == forms[i]){
			return fn[i](target);
		}
	}
	throw Intern::NotExist();
}

const char* Intern::NotExist::what() const throw(){
	return "Error: Form does not exist!";
}