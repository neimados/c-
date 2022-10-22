#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon & weapon): 
	_name(name),_weapon(weapon) {}

HumanA::~HumanA(){
	std::cout<<"HumanA killed"<<std::endl;
}

std::string	HumanA::getName(){
	return this->_name;
}

const std::string HumanA::getWeapon() const{
	return this->_weapon.getType();
}

void	HumanA::attack(){
	std::cout<<this->getName()<<" attacks with their "<<this->getWeapon()<<std::endl;
}