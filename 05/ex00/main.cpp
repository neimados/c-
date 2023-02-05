#include "Bureaucrat.hpp"

int	main(void){

	Bureaucrat	*a = new Bureaucrat("aaa", 1);

	try{
		Bureaucrat	*b = new Bureaucrat("bbb", -12);

		std::cout<<b->getName()<<b->getGrade()<<std::endl;
		delete b;
	}
	catch (std::exception & e){
		std::cout<<e.what()<<std::endl;
	}

	try{
		Bureaucrat	*c = new Bureaucrat("ccc", 160);

		std::cout<<c->getName()<<c->getGrade()<<std::endl;
		delete c;
	}
	catch (std::exception & e){
		std::cout<<e.what()<<std::endl;
	}

	try{
		Bureaucrat	*d = new Bureaucrat(*a);

		std::cout << *d << std::endl;
		d->decrement();
		std::cout << *d << std::endl;
		d->increment();
		std::cout << *d << std::endl;
		d->increment();
		std::cout << *d << std::endl;

		delete d;
	}
	catch (std::exception & e){
		std::cout<<e.what()<<std::endl;
	}

	delete a;

	return 0;
}