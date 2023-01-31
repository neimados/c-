#include "Dog.hpp"

Dog::Dog(){
	this->type = "Dog";
	std::cout<<"Dog default constructor called"<<std::endl;
}

Dog::Dog(std::string name): Animal(name){
	this->type = name;
	std::cout<<"Dog constructor called"<<std::endl;
}

Dog::Dog(const Dog &d): Animal(d)
{
	std::cout<<"Dog copy constructor called"<<std::endl;
	*this = d;
}

Dog &Dog::operator=(const Dog &d){
	std::cout<<"Dog copy assignment operator called"<<std::endl;
	this->type = d.type;
	return *this;
}

Dog::~Dog(){
	std::cout<<"Dog default destructor called"<<std::endl;
}

void	Dog::makeSound() const{
	std::cout<<this->type<<" Woof Woof"<<std::endl;
}