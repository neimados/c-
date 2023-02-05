#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void){

	Bureaucrat	*a = new Bureaucrat("aaa", 10);
	Bureaucrat	*b = new Bureaucrat("bbb", 100);

	try{
		Form	*f1 = new Form("f1", 100, 100);

		std::cout<<*f1<<std::endl;
		f1->beSigned(*a);
		std::cout<<*f1<<std::endl;

		try{
			Form *f2 = new Form(*f1);
			std::cout<<*f2<<std::endl;
			delete f2;
		}
		catch(std::exception &e){
			std::cout<<e.what()<<std::endl;
		}

		delete f1;
	}
	catch (std::exception &e){
		std::cout<<e.what()<<std::endl;
	}

	std::cout<<std::endl;

	try
	{
		Form	*f2 = new Form("f2", 5, 100);
		f2->beSigned(*a);
		delete f2;
	}
	catch (std::exception &e){
		std::cout<<e.what()<<std::endl;
	}

	std::cout<<std::endl;

	try
	{
		Form	*f3 = new Form("f3", 15, 100);
		
		std::cout<<*f3<<std::endl;
		a->signForm(*f3);
		std::cout<<*f3<<std::endl;
		b->signForm(*f3);

		delete f3;
	}
	catch (std::exception &e){
		std::cout<<e.what()<<std::endl;
	}

	delete a;
	delete b;

	return 0;
}