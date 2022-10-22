#include <iostream>

int	main(void){
	std::string	str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string	&stringREF = str;

	std::cout<<"address: "<<&str<<std::endl;
	std::cout<<"address: "<<stringPTR<<std::endl;
	std::cout<<"address: "<<&stringREF<<std::endl;

	std::cout<<"value: "<<str<<std::endl;
	std::cout<<"value: "<<*stringPTR<<std::endl;
	std::cout<<"value: "<<stringREF<<std::endl;

	return 0;
}