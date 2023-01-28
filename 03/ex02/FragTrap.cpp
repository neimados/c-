#include "FragTrap.hpp"

FragTrap::FragTrap(){
	this->_hit = 100;
	this->_energy = 100;
	this->_attack = 30;
	std::cout<<"FragTrap Default constructor called"<<std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name){
	this->_hit = 100;
	this->_energy = 100;
	this->_attack = 30;
	std::cout<<"FragTrap constructor called"<<std::endl;
}

FragTrap::FragTrap(const FragTrap &f): ClapTrap(f){
	std::cout<<"FragTrap copy constructor called"<<std::endl;
	*this = f;
}

FragTrap &FragTrap::operator=(const FragTrap &f){
	this->_name = f._name;
    this->_hit = f._hit;
    this->_energy = f._energy;
    this->_attack = f._attack;
    std::cout<<"FragTrap Copy assignment operator called"<<std::endl;
	return *this;
}

FragTrap::~FragTrap(){
	std::cout<<"FragTrap default destructor called"<<std::endl;
}

void	FragTrap::highFivesGuys(){
	std::cout<<"FragTrap "<<this->_name<<" has requested a high fives!"<<std::endl;
}