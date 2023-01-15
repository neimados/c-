#include "Fixed.hpp"

Fixed::Fixed(){
	_fixed = 0;
	std::cout<<"Default constructor called"<<std::endl;
}

Fixed::Fixed (const Fixed& f){
	this->_fixed = f._fixed;
	std::cout<<"Copy constructor called"<<std::endl;
	f.getRawBits();
}

Fixed &Fixed::operator = (const Fixed& f){
	this->_fixed = f._fixed;
	std::cout<<"Copy assignment operator called"<<std::endl;
	f.getRawBits();
	return *this;
}

Fixed::~Fixed(){
	std::cout<<"Destructor called"<<std::endl;
}

int		Fixed::getRawBits(void) const{
	std::cout<<"getRawBits member function called"<<std::endl;
	return this->_fixed;
}

void	Fixed::setRawBits(int const raw){
	this->_fixed = raw;
}