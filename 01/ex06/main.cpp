#include "Harl.hpp"

int	main(int argc, char **argv){
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int			level = -1;
	
	if (argc != 2){
		std::cout<<"Missing argument"<<std::endl;
		return 1;
	}
	for (int i = 0; i < 4; i++){
		if (levels[i] == argv[1]){
			level = i;
		}
	}
	std::cout<<std::endl;
	if (level != -1){
		Harl		harl2;
		std::cout<<std::endl;
		switch (level){
			case 0:
				harl2.complain("debug");
				std::cout<<std::endl;
			case 1:
				harl2.complain("info");
				std::cout<<std::endl;
			case 2:
				harl2.complain("warning");
				std::cout<<std::endl;
			case 3:
				harl2.complain("error");
				std::cout<<std::endl;
		}
	} else {
		std::cout<<"Wrong argument"<<std::endl;
	}

	return 0;
}