#include "Zombie.hpp"

int	main (void){
	Zombie *z = zombieHorde(8, "Foo");
	for (int i = 0; i < 8; i++){
		std::cout<<i<<':';
		z[i].announce();
	}
	killZombies(z, 8);
	delete [] z;

	return 0;
}