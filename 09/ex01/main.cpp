#include "RPN.hpp"

int main(int argc, char **argv){
	if (argc != 2){
		std::cout<<"Arguments Error !"<<std::endl;
		return 1;
	}
	RPN	r(argv[1]);
	try{
		r.fillStack();
		r.firstCalc();
		r.calculate();
	} catch (std::exception &e){
		std::cout<<e.what()<<std::endl;
	}
	return 0;
}