#include "WrongCat.hpp"

WrongCat::WrongCat(){
	this->type = "WrongCat";
	std::cout<<"WrongCat default constructor called"<<std::endl;
}

WrongCat::WrongCat(std::string name): WrongAnimal(name)
{
	std::cout<<"WrongCat constructor called"<<std::endl;
}

WrongCat::WrongCat(const WrongCat &c): WrongAnimal(c)
{
	std::cout<<"WrongCat copy constructor called"<<std::endl;
	*this = c;
}

WrongCat &WrongCat::operator=(const WrongCat &c){
	std::cout<<"WrongCat copy assignment operator called"<<std::endl;
	this->type = c.type;
	return *this;
}

WrongCat::~WrongCat(){
	std::cout<<"WrongCat default destructor called"<<std::endl;
}

void	WrongCat::makeSound() const{
	std::cout<<this->type<<" make the wrong sound"<<std::endl;
}