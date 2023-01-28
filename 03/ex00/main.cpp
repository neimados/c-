#include "ClapTrap.hpp"

int	main(void){
	ClapTrap c("Harl");
	ClapTrap t;

	c.attack("Bibi");
	t.attack("Bobo");

	c.beRepaired(10);
	c.beRepaired(10);
	c.beRepaired(10);
	c.beRepaired(10);
	c.beRepaired(10);
	c.takeDamage(10);
	c.takeDamage(10);
	c.takeDamage(10);
	c.beRepaired(10);
	c.beRepaired(10);
	c.beRepaired(10);
	c.beRepaired(10);
	c.beRepaired(10);
	c.beRepaired(10);

	t.takeDamage(5);
	t.takeDamage(5);
	t.takeDamage(5);
	t.takeDamage(5);

	return 0;
}