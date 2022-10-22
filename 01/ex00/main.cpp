#include "Zombie.hpp"

int	main(void){
	Zombie *z = newZombie("heap");
	z->announce();
	z->~Zombie();
	std::cout<<std::endl;
	randomChump("stack");
	delete z;

	return 0;
}