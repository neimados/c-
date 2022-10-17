#ifndef HUMANA_CPP
#define HUMANA_CPP

#include "Weapon.hpp"

class HumanA {
	public:
		HumanA(std::string name, Weapon & weapon);
		~HumanA();
		std::string	getName();
		std::string	const getWeapon() const;
		void	attack();

	private:
		std::string	_name;
		Weapon		&_weapon;
};


#endif