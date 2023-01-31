#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

// int main(void){
// 	Animal	*a;
// 	Dog		d("Dog");
// 	Cat		c("Cat");
// 	Cat		test(c);

// 	std::cout<<std::endl;
// 	d.makeSound();
// 	c.makeSound();
// 	test.makeSound();
// 	std::cout<<std::endl;

// 	a->makeSound();

// 	return 0;
// }

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal *w = new WrongAnimal();
	const WrongAnimal *w1 = new WrongCat();

	std::cout<<std::endl;
	std::cout << meta->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << w->getType() << " " << std::endl;
	std::cout << w1->getType() << " " << std::endl;
	std::cout<<std::endl;

	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	w->makeSound();
	w1->makeSound();
	std::cout<<std::endl;

	delete meta;
	delete j;
	delete i;
	delete w;
	delete w1;

	return 0;
}