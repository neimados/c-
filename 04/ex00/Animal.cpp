#include "Animal.hpp"

Animal::Animal():   type("unknown")
{
    std::cout<<"Animal default constructor called."<<std::endl;
}

Animal::Animal(std::string name):   type(name)
{
    std::cout<<"Animal constructor called."<<std::endl;
}

Animal::Animal(const Animal &a){
    std::cout<<"Animal copy constructor called"<<std::endl;
    *this = a;
}

Animal &Animal::operator=(const Animal &a){
    std::cout<<"Animal copy assignment operator called"<<std::endl;
    this->type = a.type;
    return *this;
}

Animal::~Animal(){
    std::cout<<"Animal defaut destructor called"<<std::endl;
}

void    Animal::makeSound() const{
    std::cout<<"Random animal sound"<<std::endl;
}

std::string Animal::getType() const{
    return this->type;
}