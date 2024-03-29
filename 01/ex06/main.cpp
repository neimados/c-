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
			case 1:
					harl2.complain("info");
			case 2:
					harl2.complain("warning");
			case 3:
					harl2.complain("error");
					break;
			default:
				std::cout << "Default answer";
		}
	} else {
		std::cout<<"Wrong argument"<<std::endl;
	}

	return 0;
}