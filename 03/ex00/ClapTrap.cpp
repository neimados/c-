#include "ClapTrap.hpp"

ClapTrap::ClapTrap():	_name("Default"), 
						_hit(10),
						_energy(10),
						_attack(5)
{
	std::cout<<"Default constructor called"<<std::endl;
}

ClapTrap::ClapTrap(std::string name):	_name(name), 
										_hit(10),
										_energy(10),
										_attack(5)
{
	std::cout<<"Constructor called"<<std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &c){
    std::cout<<"Copy constructor called"<<std::endl;
    *this = c;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &c){
    this->_name = c._name;
    this->_hit = c._hit;
    this->_energy = c._energy;
    this->_attack = c._attack;
    std::cout<<"Copy assignment operator called"<<std::endl;
	return *this;
}

ClapTrap::~ClapTrap(){
    std::cout<<"Default destructor called"<<std::endl;
}

void	ClapTrap::attack(const std::string& target){
    if (this->_hit <= 0){
		std::cout<<"ClapTrap "<<this->_name<<" is already dead."<<std::endl;
	} 
	else if (this->_energy <=0){
		std::cout<<"ClapTrap "<<this->_name<<" has not enought energy."<<std::endl;
	} else {
		this->_energy -= 1;
		std::cout<<"ClapTrap "<< this->_name << " attacks " << target << ", causing " << this->_attack << " points of damage!"<<std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount){
	if (this->_hit <= 0){
		std::cout<<"ClapTrap "<<this->_name<<" is already dead."<<std::endl;
	} else {
		if ((int)(this->_hit - amount) < 0){
			this->_hit = 0;
		} else {
			this->_hit -= amount;
		}
		if (this->_hit <= 0){
			std::cout<<"ClapTrap "<<this->_name<<" received "<<amount<<" points of damage and died!"<<std::endl;
		} else {
			std::cout<<"ClapTrap "<<this->_name<<" received "<<amount<<" points of damage, left "<<this->_hit<<" points."<<std::endl;
		}
	}
}

void	ClapTrap::beRepaired(unsigned int amount){
    if (this->_hit <= 0){
		std::cout<<"ClapTrap "<<this->_name<<" is already dead."<<std::endl;
	} 
	else if (this->_energy <=0){
		std::cout<<"ClapTrap "<<this->_name<<" has not enought energy."<<std::endl;
	} else {
		this->_energy -= 1;
		this->_hit += amount;
		std::cout<<"ClapTrap "<< this->_name << " restore "<<amount<< " points, left "<<this->_hit<<" points."<<std::endl;
	}
}