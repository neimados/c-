#include "Weapon.hpp"

Weapon::Weapon(std::string type){
	this->_type = type;
}

Weapon::~Weapon(){
	std::cout<<"Weapon destroyed"<<std::endl;
}

std::string const & Weapon::getType() const{
	return this->_type;
}

void Weapon::setType(std::string type){
	if (type != ""){
		this->_type = type;
	}
}