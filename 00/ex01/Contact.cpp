#include "Contact.hpp"

Contact::Contact(){
	return;
}

Contact::~Contact(){
	return;
}

int	checkDigit(std::string str){
	if (str.length() > 10)
		return 1;
	for(unsigned int i = 0; i < str.length(); i++){
		if (!std::isdigit(str[i]))
			return 1;
	}
	return 0;
}

void	Contact::setContact(){
	std::string	firstname;
	std::string	lastname;
	std::string	nickname;
	std::string	phone;
	std::string	secret;

	while (firstname == ""){
		std::cout<<"Enter First Name : "<<std::endl;
		if (!std::getline(std::cin, firstname))
			return;
	}
	while (lastname == ""){
		std::cout<<"Enter Last Name : "<<std::endl;
		if (!std::getline(std::cin, lastname))
			return;
	}
	while (nickname == ""){
		std::cout<<"Enter Nick Name : "<<std::endl;
		if (!std::getline(std::cin, nickname))
			return;
	}
	while (phone == "" || checkDigit(phone)){
		std::cout<<"Enter Phone (number only) : "<<std::endl;
		if (!std::getline(std::cin, phone))
			return;
	}
	while (secret == ""){
		std::cout<<"Enter Secret : "<<std::endl;
		if (!std::getline(std::cin, secret))
			return;
	}
	_firstName = firstname;
	_lastName = lastname;
	_nickName = nickname;
	_phone = phone;
	_secret = secret;
}

std::string	Contact::getFirstName(){
	return	_firstName;
}

std::string	Contact::getLastName(){
	return	_lastName;
}

std::string	Contact::getNickName(){
	return	_nickName;
}

std::string	Contact::getPhone(){
	return _phone;
}

std::string Contact::getSecret(){
	return _secret;
}