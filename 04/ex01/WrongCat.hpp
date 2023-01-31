#pragma once

#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal{
	public:
		WrongCat();
		WrongCat(std::string name);
		WrongCat(const WrongCat &d);
		WrongCat &operator=(const WrongCat &d);
		~WrongCat();

		void	makeSound() const;
};