#include "HumanB.hpp"

HumanB::HumanB(std::string name){
	this->_name = name;
}

HumanB::HumanB(std::string name, Weapon &weapon)
	: _name(name), _weapon(&weapon) {}

HumanB::~HumanB(){
	std::cout<<"HumanB killed"<<std::endl;
}

std::string	HumanB::getName(){
	return this->_name;
}

std::string	const HumanB::getWeapon() const{
	return this->_weapon->getType();
}

void	HumanB::setWeapon(Weapon & weapon){
	this->_weapon = &weapon;
}

void	HumanB::attack(){
	std::cout<<this->getName()<<" attacks with their "<<this->getWeapon()<<std::endl;
}