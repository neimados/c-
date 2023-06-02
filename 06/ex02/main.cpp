#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>

Base * generate(void){
	Base *b;
	int tmp = rand() % 3;
	switch (tmp){
		case 0:
			b = new A;
			break;
		case 1:
			b = new B;
			break;
		case 2:
			b = new C;
			break;
		default:
			return NULL;
	}
	return b;
}

void	identify(Base* p){
	if (dynamic_cast<A *>(p)){
		std::cout<<"Base is A (ptr)"<<std::endl;
	} else if (dynamic_cast<B *>(p)){
		std::cout<<"Base is B (ptr)"<<std::endl;
	} else if (dynamic_cast<C *>(p)){
		std::cout<<"Base is C (ptr)"<<std::endl;
	} else {
		std::cout<<"P not exist"<<std::endl;
	}
}

void	identify(Base& p){
	try {
		A aa = dynamic_cast<A &>(p);
		std::cout<<"Base is A (ref)"<<std::endl;	
	} catch (std::exception &e){}
	try {
		B bb = dynamic_cast<B &>(p);
		std::cout<<"Base is B (ref)"<<std::endl;
	} catch (std::exception &e){}
	try {
		C cc = dynamic_cast<C &>(p);
		std::cout<<"Base is C (ref)"<<std::endl;
	} catch (std::exception &e){}
}

int	main (void){
	srand(time(0));
	Base *bb;
	bb = generate();

	identify(bb);

	Base &tmp = *bb;
	identify(tmp);

	delete bb;

	return 0;
}