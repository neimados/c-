#pragma once

#include "Animal.hpp"

class Cat: public Animal{
	public:
		Cat();
		Cat(std::string name);
		Cat(const Cat &d);
		Cat &operator=(const Cat &d);
		~Cat();

		void	makeSound() const;
};