#include "Brain.hpp"

Brain::Brain(){
	this->index = 0;
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
	this->index = b.index;
	std::cout<<"Brain copy assignment operator called"<<std::endl;
	return *this;
}

Brain::~Brain(){
	std::cout<<"Brain default destructor called"<<std::endl;
}

void	Brain::setIdea(const std::string &idea){
	this->ideas[this->index%100] = idea;
	this->index++;
}

std::string	Brain::getIdea(int i) const {
	return this->ideas[i%100];
}