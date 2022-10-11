#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name){
	Zombie *z = new Zombie[N];
	for (int i = 0; i < N; i++){
		z[i].setName(name);
	}
	return z;
}

void	killZombies(Zombie* z, int N){
	for(int i = 0; i < N; i++){
		z[i].~Zombie();
	}
}