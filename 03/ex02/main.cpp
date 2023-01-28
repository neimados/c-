#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void){
	ClapTrap c("Clav");
	FragTrap f("Frag");

	c.takeDamage(0);
	f.takeDamage(0);
	f.highFivesGuys();

	return 0;
}