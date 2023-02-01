#pragma once

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog: public AAnimal{
	public:
		Dog();
		Dog(std::string name);
		Dog(const Dog &d);
		Dog &operator=(const Dog &d);
		~Dog();

		void	makeSound() const;
		Brain	*accessBrain() const;

	private:
		Brain	*_b;
};