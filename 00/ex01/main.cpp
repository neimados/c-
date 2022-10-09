#include "PhoneBook.hpp"
#include <iomanip>

int	main(void){
	int	i = 0;
	std::string	input;
	PhoneBook p;
	
	while (input != "EXIT"){
		std::cout<<"Choose an action : ADD, SEARCH, EXIT"<<std::endl;
		std::getline(std::cin, input);
		if (input == "ADD"){
			p.setPhoneBook(i);
			i++;
		}
		else if (input == "SEARCH"){
			p.getPhoneBook();
		}
	}
	return 0;
}