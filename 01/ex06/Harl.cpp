#include "Harl.hpp"

Harl::Harl(){
	std::cout<<"Harl is born."<<std::endl;
}

Harl::~Harl(){
	std::cout<<"Harl has been killed!"<<std::endl;
}

void	Harl::debug(){
	std::cout<<"I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do !"<<std::endl;
}

void	Harl::info(){
	std::cout<<"I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !"<<std::endl;
}

void	Harl::warning(){
	std::cout<<"I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month."<<std::endl;
}

void	Harl::error(){
	std::cout<<"This is unacceptable ! I want to speak to the manager now."<<std::endl;
}

void	Harl::complain(std::string level){
	std::string	levels[4] = {"debug", "info", "warning", "error"};
	void	(Harl::*fn[4])();
	fn[0] = &Harl::debug;
	fn[1] = &Harl::info;
	fn[2] = &Harl::warning;
	fn[3] = &Harl::error;

	for (int i = 0; i < 4; i++){
		if (level == levels[i]){
			(this->*fn[i])();
			return;
		}
	}
	std::cout<<"Wrong level of complain!"<<std::endl;
}