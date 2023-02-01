#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main()
{
	const AAnimal	*a[4];

	for (int i = 0; i < 4; i++){
		if (i % 2 == 0){
			a[i] = new Dog();
		}
		else{
			a[i] = new Cat();
		}
	}
	std::cout<<std::endl;
	for (int i = 0; i < 4; i++){
		delete	a[i];
	}

	std::cout<<std::endl;
	const Cat	*c = new Cat();

	for (int i = 0; i < 100; i++){
		if (i % 2 == 0)
			c->accessBrain()->setIdea("sleep");
		else
			c->accessBrain()->setIdea("eat");
	}

	for (int j = 0; j < 100; j++){
		std::cout<<c->accessBrain()->getIdea(j)<<" ";
	}

	std::cout<<std::endl;
	std::cout<<std::endl;
	const Cat	*copy = new Cat(*c);

	std::cout<<std::endl;
	delete c;

	std::cout<<std::endl;
	for (int j = 0; j < 100; j++){
		std::cout<<copy->accessBrain()->getIdea(j)<<" ";
	}

	std::cout<<std::endl;
	std::cout<<std::endl;
	delete copy;

	// AAnimal	*aze= new AAnimal();

	return 0;
}