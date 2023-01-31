#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal():   type("unknown wrong")
{
    std::cout<<"WrongAnimal default constructor called."<<std::endl;
}

WrongAnimal::WrongAnimal(std::string name):   type(name)
{
    std::cout<<"WrongAnimal constructor called."<<std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &a){
    std::cout<<"WrongAnimal copy constructor called"<<std::endl;
    *this = a;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &a){
    std::cout<<"WrongAnimal copy assignment operator called"<<std::endl;
    this->type = a.type;
    return *this;
}

WrongAnimal::~WrongAnimal(){
    std::cout<<"WrongAnimal defaut destructor called"<<std::endl;
}

void    WrongAnimal::makeSound() const{
    std::cout<<"Random WrongAnimal sound"<<std::endl;
}

std::string WrongAnimal::getType() const{
    return this->type;
}