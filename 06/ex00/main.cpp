#include "ScalarConverter.hpp"

int main(int argc, char **argv){
	if (argc != 2){
		std::cout<<"Missing Argument!"<<std::endl;
		return 1;
	}
	std::string	str = argv[1];
    ScalarConverter *s = new ScalarConverter(str);
	s->convert();

    delete s;

	return 0;
}