#include "ClapTrap.hpp"

ClapTrap::ClapTrap(){
    this->_name = "Default Name";
    std::cout<<"Default constructor called"<<std::endl;
}

ClapTrap::ClapTrap(std::string name){
    this->_name = name;
    std::cout<<"Constructor called"<<std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &c){
    std::cout<<"Copy constructor called"<<std::endl;
    *this = c;
}

ClapTrap ClapTrap::operator=(const ClapTrap &c){
    this->_name = c._name;
    this->_hit = c._hit;
    this->_energy = c._energy;
    this->_attack = c._attack;
    std::cout<<"Copy assignment operator called"<<std::endl;
	return *this;
}

ClapTrap ClapTrap::operator-(const ClapTrap& c){
    
}

ClapTrap::~ClapTrap(){
    std::cout<<"Default destructor called"<<std::endl;
}

ClapTrap::attack(const std::string& target){
    this->_energy -= 1;
    std::cout<<"ClapTrap "<< this->_name << " attacks " << target << " , causing " << this->_attack << " points of damage!"<<std::endl;
}