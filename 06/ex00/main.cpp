#include "ScalarConverter.hpp"

int main(int argc, char **argv){
	if (argc != 2){
		std::cout<<"Missing Argument!"<<std::endl;
		return 1;
	}
	std::string	input = argv[1];
    // ScalarConverter s;

	ScalarConverter::convert(input);

	return 0;
}