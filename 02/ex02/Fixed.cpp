#include "Fixed.hpp"

Fixed::Fixed(): _fixed(0){
	std::cout<<"Default constructor called"<<std::endl;
}

Fixed::Fixed(int const num){
	this->_fixed = num<<_bits;
	std::cout<<"Int constructor called"<<std::endl;
}

Fixed::Fixed(float const num){
	this->_fixed = roundf(num * (1<<Fixed::_bits));
	std::cout<<"Float constructor called"<<std::endl;
}

Fixed::Fixed (const Fixed& f){
	std::cout<<"Copy constructor called"<<std::endl;
	*this = f;
}

Fixed &Fixed::operator = (const Fixed& f){
	this->_fixed = f._fixed;
	std::cout<<"Copy assignment operator called"<<std::endl;
	return *this;
}

Fixed::~Fixed(){
	std::cout<<"Destructor called"<<std::endl;
}

bool Fixed::operator>(const Fixed& f) const{
	return this->_fixed > f._fixed;
}

bool Fixed::operator<(const Fixed& f) const{
	return this->_fixed < f._fixed;
}

bool Fixed::operator>=(const Fixed& f) const{
	if (_fixed >= f._fixed)
		return true;
	else 
		return false;
}

bool Fixed::operator<=(const Fixed& f) const{
	if (_fixed <= f._fixed)
		return true;
	else 
		return false;
}

bool Fixed::operator==(const Fixed& f) const{
	if (_fixed == f._fixed)
		return true;
	else 
		return false;
}

bool Fixed::operator!=(const Fixed& f) const{
	if (_fixed != f._fixed)
		return true;
	else 
		return false;
}

Fixed Fixed::operator+(const Fixed& f){
	this->_fixed += f._fixed;
	return *this;
}

Fixed Fixed::operator-(const Fixed& f){
	this->_fixed -= f._fixed;
	return *this;
}

Fixed Fixed::operator*(const Fixed& f){
	return Fixed(this->toFloat() * f.toFloat());
}

Fixed Fixed::operator/(const Fixed& f){
	return Fixed(this->toFloat() / f.toFloat());
}

Fixed Fixed::operator++(){
	this->_fixed++;
	return *this;
}

Fixed Fixed::operator++(int){
	Fixed	tmp;

	tmp = *this;
	this->_fixed++;
	return tmp;
}

Fixed Fixed::operator--(){
	this->_fixed--;
	return *this;
}

Fixed Fixed::operator--(int){
	Fixed	tmp;

	tmp = *this;
	this->_fixed--;
	return tmp;
}

Fixed &Fixed::min (Fixed &ref1, Fixed &ref2){
	if (ref1 > ref2)
		return ref2;
	return ref1;
}

Fixed const &Fixed::min (Fixed const &ref1, Fixed const &ref2){
	if (ref1 > ref2)
		return ref2;
	return ref1;
}

Fixed &Fixed::max (Fixed &ref1, Fixed &ref2){
	if (ref1 < ref2)
		return ref2;
	return ref1;
}

Fixed const &Fixed::max (Fixed const &ref1, Fixed const &ref2){
	if (ref1 < ref2)
		return ref2;
	return ref1;
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