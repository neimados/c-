#include "Form.hpp"

Form::Form():	_name("Default"),
				_signed(false),
				_signReq(1),
				_execReq(1)
{
	std::cout<<"Form default constructor called"<<std::endl;
}

Form::Form(const std::string name, const int signReq, const int execReq) :	_name(name),
																			_signed(false),
																			_signReq(signReq),
																			_execReq(execReq)
{
	if (signReq > 150 || execReq > 150){
		throw Form::GradeTooLowException();
	} 
	else if (signReq < 1 || execReq < 1) {
		throw Form::GradeTooHighException();
	} 
	std::cout<<"Form constructor called"<<std::endl;
}

Form::Form(const Form &f):	_name(f.getName()),
							_signed(f._signed),
							_signReq(f.getSignReq()),
							_execReq(f.getExecReq())
{
	std::cout<<"Form copy constructor called"<<std::endl;
}

Form	&Form::operator=(const Form &f){
	*(const_cast<std::string*>(&_name)) = f.getName();
	this->_signed = f._signed;
	*(const_cast<int*>(&_signReq)) = f.getSignReq();
	*(const_cast<int*>(&_execReq)) = f.getExecReq();
	std::cout<<"Form copy assignment operator called"<<std::endl;
	return *this;
}

Form::~Form(){
	std::cout<<"From default destructor called"<<std::endl;
}

const std::string	Form::getName() const{
	return this->_name;
}

bool	Form::getSigned() const{
	return this->_signed;
}

int	Form::getSignReq() const{
	return this->_signReq;
}

int	Form::getExecReq() const{
	return this->_execReq;
}

const char* Form::GradeTooHighException::what() const throw(){
	return "Error: Grade Too High (Highest is 1)";
}

const char* Form::GradeTooLowException::what() const throw(){
	return "Error: Grade Too Low (Lowest is 150)";
}

void	Form::beSigned(const Bureaucrat &b){
	if (b.getGrade() > this->_signReq || b.getGrade() > this->_execReq){
		std::cout<<b.getName()<<" couldn't sign "<<this->getName()<<" because his grade is too low."<<std::endl;
		delete this;
		throw Form::GradeTooLowException();
	}
	this->_signed = true;
	std::cout<<b.getName()<<" signed "<<this->getName()<<std::endl;
}

std::ostream &operator<<(std::ostream &out, Form const &f)
{
	if (f.getSigned()){
		out<<"Form "<<f.getName()<<", Grade needed to be signed: "<<f.getSignReq()<<" and "<<f.getExecReq()<<" to be executed, is done.";
	}else{
		out<<"Form "<<f.getName()<<", Grade needed to be signed: "<<f.getSignReq()<<" and "<<f.getExecReq()<<" to be executed, is pending.";
	}
	return out;
}