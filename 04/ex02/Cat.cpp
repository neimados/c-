#include "Cat.hpp"


Cat::Cat(): _b(new Brain())
{
	this->type = "Cat";
	std::cout<<"Cat default constructor called"<<std::endl;
}

Cat::Cat(std::string name): AAnimal(name), _b(new Brain())
{
	std::cout<<"Cat constructor called"<<std::endl;
	this->type = name;
}

Cat::Cat(const Cat &c): AAnimal(c), _b(new Brain())
{
	std::cout<<"Cat copy constructor called"<<std::endl;
	*this = c;
}

Cat &Cat::operator=(const Cat &c){
	std::cout<<"Cat copy assignment operator called"<<std::endl;
	this->type = c.type;
	*this->_b = *c._b;
	return *this;
}

Cat::~Cat(){
	delete	this->_b;
	std::cout<<"Cat default destructor called"<<std::endl;
}

void	Cat::makeSound() const{
	std::cout<<this->type<<" Miaou Miaou"<<std::endl;
}

Brain	*Cat::accessBrain() const{
	return	this->_b;
}