#include "Dog.hpp"

Dog::Dog(): Animal(), _b(new Brain())
{
	std::cout<<"Dog default constructor called"<<std::endl;
	this->type = "Dog";
}

Dog::Dog(std::string name): Animal(name), _b(new Brain())
{
	std::cout<<"Dog constructor called"<<std::endl;
	this->type = name;
}

Dog::Dog(const Dog &d): Animal(d), _b(new Brain(*d._b))
{
	std::cout<<"Dog copy constructor called"<<std::endl;
	*this = d;
}

Dog &Dog::operator=(const Dog &d){
	std::cout<<"Dog copy assignment operator called"<<std::endl;
	this->type = d.type;
	*this->_b = *d._b;
	return *this;
}

Dog::~Dog(){
	delete	this->_b;
	std::cout<<"Dog default destructor called"<<std::endl;
}

void	Dog::makeSound() const{
	std::cout<<this->type<<" Woof Woof"<<std::endl;
}

Brain	*Dog::accessBrain() const{
	return	this->_b;
}