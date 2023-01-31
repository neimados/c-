#include "Brain.hpp"

Brain::Brain(){
	std::cout<<"Brain default constructor called"<<std::endl;
}

Brain::Brain(const Brain &b){
	std::cout<<"Brain copy constructor called"<<std::endl;
	*this = b;
}

Brain &Brain::operator=(const Brain &b){
	for(int i=0; i < 100; i++){
		this->ideas[i] = b.ideas[i];
	}
	std::cout<<"Brain copy assignment operator called"<<std::endl;
	return *this;
}

Brain::~Brain(){
	std::cout<<"Brain default destructor called"<<std::endl;
}