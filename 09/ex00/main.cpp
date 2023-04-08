#include "BitcoinExchange.hpp"

int	main (int argc, char ** argv){
	std::ifstream		db;
	std::ifstream		input;

	if (argc != 2){
		std::cout<<"Arguments error"<<std::endl;
	} else {
		db.open("data.csv");
		if (!db.is_open()){
			std::cout<<"Database error"<<std::endl;
			return 1;
		}
		input.open(argv[1]);
		if (!input.is_open()){
			std::cout<<"Arguments error"<<std::endl;
			db.close();
			return 1;
		}
		db.close();
		input.close();
		BitcoinExchange b("data.csv", argv[1]);
		try{
			b.fillMap();
			b.printData();
		} catch (std::exception &e){
			std::cout<<e.what()<<std::endl;
		}
	}

	return 0;
}