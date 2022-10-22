#include "PhoneBook.hpp"
#include <iomanip>

PhoneBook::PhoneBook(){
	return;
}

PhoneBook::~PhoneBook(){
	return;
}

void	PhoneBook::setPhoneBook(int i){
	Contact c;

	c.setContact();
	_c[i % 8] = c;
}

std::string	ft_truncate(std::string str){
	std::string	tmp;
	
	if (str.length() <= 10)
		return str;
	else {
		for (int i = 0; i < 9; i++){
			tmp.push_back(str[i]);
		}
		tmp.push_back('.');
	}
	return tmp;
}

int	checkIndex(std::string str){
	if (str.length() > 1)
		return 1;
	if (!std::isdigit(str[0]))
		return 1;
	if (std::stoi(str) < 0 || std::stoi(str) > 7)
		return 1;
	return 0;
}

void	PhoneBook::getPhoneBook(){
	std::string	input;

	if (_c[0].getFirstName() == "")
		std::cout<<"No entry yet"<<std::endl;
	else {
		std::cout<<std::right<<std::setw(10)<<"index"<<" | "
		<<std::setw(15)<<"first name"<<" | "
		<<std::setw(15)<<"last name"<<" | "
		<<std::setw(15)<<"nick name"<<" | "<<std::endl;
		for (int i = 0; i < 8; i++){
			if (_c[i].getFirstName() != ""){
				std::cout<<std::right<<std::setw(10)<<i<<" | "
				<<std::setw(15)<<ft_truncate(_c[i].getFirstName())<<" | "
				<<std::setw(15)<<ft_truncate(_c[i].getLastName())<<" | "
				<<std::setw(15)<<ft_truncate(_c[i].getNickName())<<" | "<<std::endl;
			}
		}
		while (input == "" || checkIndex(input)){
			std::cout<<"Enter index (0 to 7) : "<<std::endl;
			if (!std::getline(std::cin, input))
				return;
		}
		if (_c[std::stoi(input)].getFirstName() == ""){
			std::cout<<"Contact not added yet"<<std::endl;
		} else {
			std::cout<<"First name : "<<_c[std::stoi(input)].getFirstName()<<std::endl;
			std::cout<<"Last name : "<<_c[std::stoi(input)].getLastName()<<std::endl;
			std::cout<<"Nick name : "<<_c[std::stoi(input)].getNickName()<<std::endl;
			std::cout<<"Phone : "<<_c[std::stoi(input)].getPhone()<<std::endl;
			std::cout<<"Darkest secret : "<<_c[std::stoi(input)].getSecret()<<std::endl;
		}
	}
}