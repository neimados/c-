#include "Zombie.hpp"

Zombie::Zombie(){
	return;
}

Zombie::~Zombie(){
	std::cout<<_name<<" has been detroyed"<<std::endl;
}

void	Zombie::announce(){
	std::cout<<_name<<": BraiiiiiiinnnzzzZ..."<<std::endl;
}

void	Zombie::setName(std::string name){
	_name = name;
}