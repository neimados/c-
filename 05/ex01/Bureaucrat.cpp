#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat():	_name("Default"),
							_grade(150)
{
	std::cout<<"Bureaucrat default constructor called"<<std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade):	_name(name)
{
	if (grade > 150){
		throw Bureaucrat::GradeTooLowException();
	} 
	else if (grade < 1) {
		throw Bureaucrat::GradeTooHighException();
	} 
	else {
		this->_grade = grade;
	}
	std::cout<<"Bureaucrat constructor called"<<std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &b){
	std::cout<<"Bureaucrat copy constructor called"<<std::endl;
	*this = b;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &b){
	*(const_cast<std::string*>(&_name)) = b.getName();
	this->_grade = b._grade;
	std::cout<<"Bureaucrat assignment operator called"<<std::endl;
	return *this;
}

Bureaucrat::~Bureaucrat(){
	std::cout<<"Bureaucrat destructor called"<<std::endl;
}

int	Bureaucrat::getGrade() const{
	return this->_grade;
}

std::string Bureaucrat::getName() const{
	return this->_name;
}

const char* Bureaucrat::GradeTooHighException::what() const throw(){
	return "Error: Grade Too High (Highest is 1)";
}

const char* Bureaucrat::GradeTooLowException::what() const throw(){
	return "Error: Grade Too Low (Lowest is 150)";
}

void	Bureaucrat::increment(){
	if (this->_grade - 1 < 1) {
		delete this;
		throw Bureaucrat::GradeTooHighException();
	} else {
		this->_grade -= 1;
		std::cout<<"Raised a grade !"<<std::endl;
	}
}

void	Bureaucrat::decrement(){
	if (this->_grade + 1 > 150) {
		delete this;
		throw Bureaucrat::GradeTooLowException();
	} else {
		this->_grade += 1;
		std::cout<<"Lowered a grade !"<<std::endl;
	}
}

void	Bureaucrat::signForm(Form &f){
	f.beSigned(*this);
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &b)
{
	out<<b.getName()<<", bureaucrat grade "<<b.getGrade()<<".";
	return out;
}