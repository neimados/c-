#include "Harl.hpp"

int	main(void){
	Harl	harl2;
	
	std::cout<<std::endl;
	harl2.complain("debug");
	std::cout<<std::endl;
	harl2.complain("info");
	std::cout<<std::endl;
	harl2.complain("warning");
	std::cout<<std::endl;
	harl2.complain("error");
	std::cout<<std::endl;
	harl2.complain("gfgfdg");
	std::cout<<std::endl;
	harl2.complain("");
	std::cout<<std::endl;

	return 0;
}