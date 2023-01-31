#pragma once

#include "Animal.hpp"

class Dog: public Animal{
	public:
		Dog();
		Dog(std::string name);
		Dog(const Dog &d);
		Dog &operator=(const Dog &d);
		~Dog();

		void	makeSound() const;
};