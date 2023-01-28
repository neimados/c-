#include "ScavTrap.hpp"

ScavTrap::ScavTrap(){
	this->_hit = 100;
	this->_energy = 50;
	this->_attack = 20;
    std::cout<<"ScavTrap Default constructor called"<<std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name){
	this->_hit = 100;
	this->_energy = 50;
	this->_attack = 20;
    std::cout<<"ScavTrap Constructor called"<<std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &s): ClapTrap(s){
    std::cout<<"ScavTrap Copy constructor called"<<std::endl;
	*this = s;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &s){
	this->_name = s._name;
    this->_hit = s._hit;
    this->_energy = s._energy;
    this->_attack = s._attack;
    std::cout<<"ScavTrap Copy assignment operator called"<<std::endl;
	return *this;
}

ScavTrap::~ScavTrap(){
    std::cout<<"ScavTrap Default destructor called"<<std::endl;
}

void	ScavTrap::attack(const std::string& target){
    if (this->_hit <= 0){
		std::cout<<this->_name<<" is already dead."<<std::endl;
	} 
	else if (this->_energy <=0){
		std::cout<<this->_name<<" has not enought energy."<<std::endl;
	} else {
		this->_energy -= 1;
		std::cout<< this->_name << " defending against " << target << ", causing " << this->_attack << " points of damage!"<<std::endl;
	}
}

void	ScavTrap::guardGate(){
	std::cout<<this->_name<<" is now in Gate keeper mode."<<std::endl;
}