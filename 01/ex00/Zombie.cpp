#include "Zombie.hpp"

Zombie::Zombie(std::string name){
	Zombie::_name = name;
}

Zombie::~Zombie(){
	std::cout<<_name<<" has been detroyed"<<std::endl;
}

void	Zombie::announce(){
	std::cout<<_name<<": BraiiiiiiinnnzzzZ..."<<std::endl;
}
