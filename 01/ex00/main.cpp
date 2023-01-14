#include "Zombie.hpp"

int	main(void){
	Zombie *z = newZombie("heap");
	z->announce();
	delete z;

	std::cout<<std::endl;
	randomChump("stack");

	return 0;
}