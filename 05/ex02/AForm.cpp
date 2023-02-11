#include "AForm.hpp"

AForm::AForm():	_name("Default"),
				_signed(false),
				_signReq(1),
				_execReq(1),
				_target("Default")
{
	std::cout<<"Form default constructor called"<<std::endl;
}

AForm::AForm(const std::string &name, const int signReq, const int execReq, const std::string &target) :	_name(name),
																											_signed(false),
																											_signReq(signReq),
																											_execReq(execReq),
																											_target(target)
{
	if (signReq > 150 || execReq > 150){
		throw AForm::GradeTooLowException();
	} 
	else if (signReq < 1 || execReq < 1) {
		throw AForm::GradeTooHighException();
	} 
	std::cout<<"Form constructor called"<<std::endl;
}

AForm::AForm(const AForm &f):	_name(f.getName()),
								_signed(f._signed),
								_signReq(f.getSignReq()),
								_execReq(f.getExecReq()),
								_target(f._target)
{
	std::cout<<"Form copy constructor called"<<std::endl;
}

AForm	&AForm::operator=(const AForm &f){
	*(const_cast<std::string*>(&_name)) = f.getName();
	this->_signed = f._signed;
	*(const_cast<int*>(&_signReq)) = f.getSignReq();
	*(const_cast<int*>(&_execReq)) = f.getExecReq();
	this->_target = f._target;
	std::cout<<"Form copy assignment operator called"<<std::endl;
	return *this;
}

AForm::~AForm(){
	std::cout<<"From default destructor called"<<std::endl;
}

const std::string	AForm::getName() const{
	return this->_name;
}

bool	AForm::getSigned() const{
	return this->_signed;
}

const int	AForm::getSignReq() const{
	return this->_signReq;
}

const int	AForm::getExecReq() const{
	return this->_execReq;
}

const std::string	AForm::getTarget() const{
	return this->_target;
}

const char* AForm::GradeTooHighException::what() const throw(){
	return "Error: Grade Too High (Highest is 1)";
}

const char* AForm::GradeTooLowException::what() const throw(){
	return "Error: Grade Too Low (Lowest is 150)";
}

const char* AForm::NotSigned::what() const throw(){
	return "Error: form not signed!";
}

void	AForm::beSigned(const Bureaucrat &b){
	if (b.getGrade() > this->_signReq || b.getGrade() > this->_execReq){
		std::cout<<b.getName()<<" couldn't sign "<<this->getName()<<" because his grade is too low."<<std::endl;
		delete this;
		throw AForm::GradeTooLowException();
	}
	this->_signed = true;
	std::cout<<b.getName()<<" signed "<<this->getName()<<std::endl;
}

void	AForm::check(const Bureaucrat &b) const{
	if (!this->_signed){
		throw AForm::NotSigned();
	} else if (b.getGrade() > this->_execReq){
		throw AForm::GradeTooLowException();
	}
}

std::ostream &operator<<(std::ostream &out, AForm const &f)
{
	if (f.getSigned()){
		out<<"Form "<<f.getName()<<", Grade needed to be signed: "<<f.getSignReq()<<" and "<<f.getExecReq()<<" to be executed, is done.";
	}else{
		out<<"Form "<<f.getName()<<", Grade needed to be signed: "<<f.getSignReq()<<" and "<<f.getExecReq()<<" to be executed, is pending.";
	}
	return out;
}