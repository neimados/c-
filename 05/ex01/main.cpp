#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void){

	Bureaucrat a("aaa", 10);
	Bureaucrat b("bbb", 100);

	try{
		Form f1("f1", 100, 100);

		std::cout<<f1<<std::endl;
		f1.beSigned(a);
		std::cout<<f1<<std::endl;

		try{
			Form f2(f1);
			std::cout<<f2<<std::endl;
		}
		catch(std::exception &e){
			std::cout<<e.what()<<std::endl;
		}
	}
	catch (std::exception &e){
		std::cout<<e.what()<<std::endl;
	}

	std::cout<<std::endl;

	try
	{
		Form f2("f2", 5, 100);
		f2.beSigned(a);
	}
	catch (std::exception &e){
		std::cout<<e.what()<<std::endl;
	}

	std::cout<<std::endl;

	try
	{
		Form f3("f3", 15, 100);
		
		std::cout<<f3<<std::endl;
		a.signForm(f3);
		std::cout<<f3<<std::endl;
		b.signForm(f3);
	}
	catch (std::exception &e){
		std::cout<<e.what()<<std::endl;
	}

	return 0;
}