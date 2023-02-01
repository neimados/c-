#include "AAnimal.hpp"

AAnimal::AAnimal():   type("unknown")
{
    std::cout<<"Animal default constructor called."<<std::endl;
}

AAnimal::AAnimal(std::string name):   type(name)
{
    std::cout<<"Animal constructor called."<<std::endl;
}

AAnimal::AAnimal(const AAnimal &a){
    std::cout<<"Animal copy constructor called"<<std::endl;
    *this = a;
}

AAnimal &AAnimal::operator=(const AAnimal &a){
    std::cout<<"Animal copy assignment operator called"<<std::endl;
    this->type = a.type;
    return *this;
}

AAnimal::~AAnimal(){
    std::cout<<"Animal defaut destructor called"<<std::endl;
}

void    AAnimal::makeSound() const{
    std::cout<<"Random animal sound"<<std::endl;
}

std::string AAnimal::getType() const{
    return this->type;
}