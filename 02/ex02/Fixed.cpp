#include "Fixed.hpp"

Fixed::Fixed(){
	_fixed = 0;
	std::cout<<"Default constructor called"<<std::endl;
}

Fixed::Fixed(int const num){
	this->_fixed = num << _bits;
	std::cout<<"Int constructor called"<<std::endl;
}

Fixed::Fixed(float const num){
	this->_fixed = roundf(num * (1<<Fixed::_bits));
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

bool Fixed::operator>(const Fixed& f){
	if (_fixed > f._fixed)
		return true;
	else 
		return false;
}

bool Fixed::operator<(const Fixed& f){
	if (_fixed < f._fixed)
		return true;
	else 
		return false;
}

bool Fixed::operator>=(const Fixed& f){
	if (_fixed >= f._fixed)
		return true;
	else 
		return false;
}

bool Fixed::operator<=(const Fixed& f){
	if (_fixed <= f._fixed)
		return true;
	else 
		return false;
}

bool Fixed::operator==(const Fixed& f){
	if (_fixed == f._fixed)
		return true;
	else 
		return false;
}

bool Fixed::operator!=(const Fixed& f){
	if (_fixed != f._fixed)
		return true;
	else 
		return false;
}

Fixed Fixed::operator+(const Fixed& f){
	Fixed tmp;

	tmp._fixed += f._fixed;
	return tmp;
}

Fixed Fixed::operator-(const Fixed& f){
	Fixed tmp;

	tmp._fixed -= f._fixed;
	return tmp;
}

Fixed Fixed::operator*(const Fixed& f){
	Fixed tmp (this->toFloat() * f.toFloat());

	return tmp;
}

Fixed Fixed::operator/(const Fixed& f){
	Fixed tmp (this->toFloat() / f.toFloat());

	return tmp;
}

Fixed Fixed::operator++(){
	this->_fixed++;

	return *this;
}

Fixed Fixed::operator++(int){
	Fixed tmp;

	tmp = *this;
	++*this;
	return tmp;
}

Fixed Fixed::operator--(){
	this->_fixed--;

	return *this;
}

Fixed Fixed::operator--(int){
	Fixed tmp;

	tmp = *this;
	--*this;
	return tmp;
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

Fixed& Fixed::min(Fixed& f1, Fixed& f2){
	if (f1._fixed < f2._fixed){
		return f1;
	}
	return f2;
}

const Fixed& Fixed::min(const Fixed& f1, const Fixed& f2){
	if (f1._fixed < f2._fixed){
		return f1;
	}
	return f2;
}

Fixed& Fixed::max(Fixed& f1, Fixed& f2){
	if (f1._fixed < f2._fixed){
		return f2;
	}
	return f1;
}

const Fixed& Fixed::max(const Fixed& f1, const Fixed& f2){
	if (f1._fixed < f2._fixed){
		return f2;
	}
	return f1;
}

std::ostream &operator<<(std::ostream &out, Fixed const &f)
{
	out<<f.toFloat();
	return out;
}