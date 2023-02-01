#pragma once

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat: public AAnimal{
	public:
		Cat();
		Cat(std::string name);
		Cat(const Cat &d);
		Cat &operator=(const Cat &d);
		~Cat();

		void	makeSound() const;
		Brain	*accessBrain() const;

	private:
		Brain	*_b;
};