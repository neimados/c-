#include "Cat.hpp"

Cat::Cat(){
	this->type = "Cat";
	std::cout<<"Cat default constructor called"<<std::endl;
}

Cat::Cat(std::string name): Animal(name)
{
	std::cout<<"Cat constructor called"<<std::endl;
}

Cat::Cat(const Cat &c): Animal(c)
{
	std::cout<<"Cat copy constructor called"<<std::endl;
	*this = c;
}

Cat &Cat::operator=(const Cat &c){
	std::cout<<"Cat copy assignment operator called"<<std::endl;
	this->type = c.type;
	return *this;
}

Cat::~Cat(){
	std::cout<<"Cat default destructor called"<<std::endl;
}

void	Cat::makeSound() const{
	std::cout<<this->type<<" Miaou Miaou"<<std::endl;
}