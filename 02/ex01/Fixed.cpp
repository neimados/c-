#include "Fixed.hpp"

Fixed::Fixed(){
	_fixed = 0;
	std::cout<<"Default constructor called"<<std::endl;
}

Fixed::Fixed(int const num){
	_fixed = num << _bits;
	std::cout<<"Int constructor called"<<std::endl;
}

Fixed::Fixed(float const num){
	_fixed = roundf(num * (1<<Fixed::_bits));
	std::cout<<"Float constructor called"<<std::endl;
}

Fixed::Fixed (const Fixed& f){
	_fixed = f._fixed;
	std::cout<<"Copy constructor called"<<std::endl;
}

Fixed &Fixed::operator = (const Fixed& f){
	this->_fixed = f._fixed;
	std::cout<<"Copy assignment operator called"<<std::endl;
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

float	Fixed::toFloat(void) const{
	return (float)(this->_fixed / (float)(1<<_bits)); 
}

int		Fixed::toInt(void) const{
	return this->_fixed>>_bits;
}

std::ostream &operator<<(std::ostream &out, Fixed const &f)
{
	out<<f.toFloat();
	return out;
}