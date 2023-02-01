#include "Dog.hpp"

Dog::Dog(): _b(new Brain())
{
	this->type = "Dog";
	std::cout<<"Dog default constructor called"<<std::endl;
}

Dog::Dog(std::string name): AAnimal(name), _b(new Brain()){
	this->type = name;
	std::cout<<"Dog constructor called"<<std::endl;
}

Dog::Dog(const Dog &d): AAnimal(d)
{
	std::cout<<"Dog copy constructor called"<<std::endl;
	*this = d;
}

Dog &Dog::operator=(const Dog &d){
	std::cout<<"Dog copy assignment operator called"<<std::endl;
	this->type = d.type;
	for (int i = 0; i < 100; i++){
		this->_b[i] = d._b[i];
	}
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