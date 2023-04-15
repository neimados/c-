#include "Bureaucrat.hpp"

int	main(void){

	Bureaucrat a("aaa", 1);

	try{
		Bureaucrat b("bbb", 12);
		std::cout<<b.getName()<<b.getGrade()<<std::endl;
	}
	catch (std::exception & e){
		std::cout<<e.what()<<std::endl;
	}

	try{
		Bureaucrat c("ccc", 140);
		std::cout<<c.getName()<<c.getGrade()<<std::endl;
	}
	catch (std::exception & e){
		std::cout<<e.what()<<std::endl;
	}

	try{
		Bureaucrat d(a);
		std::cout << d << std::endl;
		d.decrement();
		std::cout << d << std::endl;
		d.increment();
		std::cout << d << std::endl;
		d.increment();
		std::cout << d << std::endl;
	}
	catch (std::exception & e){
		std::cout<<e.what()<<std::endl;
	}

	return 0;
}