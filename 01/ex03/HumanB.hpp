#ifndef HUMANB_CPP
#define HUMANB_CPP

#include "Weapon.hpp"

class HumanB {
	public:
		HumanB(std::string name);
		HumanB(std::string name, Weapon & weapon);
		~HumanB();
		std::string	getName();
		std::string	const getWeapon() const;
		void	setWeapon(Weapon & weapon);
		void	attack();

	private:
		std::string	_name;
		Weapon		*_weapon;
};

#endif