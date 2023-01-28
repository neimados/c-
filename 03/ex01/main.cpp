#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void){
	ClapTrap c("Clav");
	ScavTrap s("Guard");
	ScavTrap s2(s);
	ScavTrap s3("Ben");

	c.beRepaired(10);
	s.beRepaired(10);
	s2.beRepaired(50);

	s3=s2;
	s3.guardGate();
	s3.takeDamage(50);
	s3.takeDamage(50);
	s3.takeDamage(50);
	s3.takeDamage(50);

	s.guardGate();
	c.attack("Paul");
	s.attack("Paul");

	return 0;
}