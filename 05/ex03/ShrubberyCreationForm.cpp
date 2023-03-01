#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm():	AForm("Shrubbery", 145, 137, "Default")
{
	std::cout<<"SCForm default constructor called"<<std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target): AForm("Shrubbery", 145, 137, target)
{
	std::cout<<"SCForm constructor called"<<std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &s): AForm(s)
{
	std::cout<<"SCForm copy constructor called"<<std::endl;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator= (const ShrubberyCreationForm &s){
	AForm::operator=(s);
	std::cout<<"SCForm assignment operator called"<<std::endl;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
	std::cout<<"SCForm destructor called"<<std::endl;
}

void	ShrubberyCreationForm::execute(const Bureaucrat &b) const{
	std::ofstream		output;
	std::string			filename = b.getName() + "_shrubbery";
	std::string 		tree =	
"    oxoxoo    ooxoo\n\
  ooxoxo oo  oxoxooo\n\
 oooo xxoxoo ooo ooox\n\
 oxo o oxoxo  xoxxoxo\n\
  oxo xooxoooo o ooo\n\
    ooooo|ooo| /o/o\n\
         |  |//\n\
         |   /\n\
         |  |\n\
         | D|\n\
         |  |\n\
         |  |\n\
  ______/___|____\n";
	this->check(b);
	output.open(filename.c_str());
	if (!output.is_open()){
		std::cout<<"File creation error!"<<std::endl;
		return;
	}
	output << tree;
	output.close();
}

AForm *ShrubberyCreationForm::newShrubbery(const std::string &target){
	return new ShrubberyCreationForm(target);
}