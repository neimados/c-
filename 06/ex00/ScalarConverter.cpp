#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() :	_str(""),
										_d(0.0),
										_possible(true),
										_count(0),
										_dot(0)
{
    std::cout<<"ScalarConverter default constructor called"<<std::endl;
	std::cout<<"Missing parameter"<<std::endl;
}

ScalarConverter::ScalarConverter(std::string &str) :	_str(str),
														_possible(true),
														_count(0),
														_dot(0)
{
	this->_d = std::strtod(str.c_str(), NULL);
	std::cout<<"ScalarConverter constructor called"<<std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &conv){
    std::cout<<"ScalarConverter copy constructor called"<<std::endl;
    *this = conv;
}

ScalarConverter &ScalarConverter::operator= (const ScalarConverter &conv){
    std::cout<<"ScalarConverter assignment operator called"<<std::endl;
	this->_str = conv._str;
    return *this;
}

ScalarConverter::~ScalarConverter(){
    std::cout<<"ScalarConverter destructor called"<<std::endl;
}

void	ScalarConverter::check(){
	for (unsigned int i = 0; i < _str.length(); i++){
		if (_str[i] < 48 || _str[i] > 57){
			if (_str[i] == '.' && (i != 0 || i != _str.length() - 1)){
				_dot += 1;
				continue;
			}
			else if (_str[i] == 'f' && i == _str.length() - 1)
				continue;
			else
				_count += 1;
		}
	}
	if (_count || _dot > 1)
		_possible = false;
	if (_str == "nan" || _str == "+inf" || _str == "-inf"
		|| _str == "nanf" || _str == "+inff" || _str == "-inff"
		|| _str == "inf" || _str == "inff")
		_possible = true;
}


void	ScalarConverter::convert(){
	ScalarConverter::check();
	ScalarConverter::toChar();
	ScalarConverter::toInt();
	ScalarConverter::toFloat();
	ScalarConverter::toDouble();
}

void	ScalarConverter::toChar() const{
	std::cout<<"char: ";
	try{
		ScalarConverter::convertChar();
	}
	catch (std::exception &e){
		std::cout<<e.what()<<std::endl;
	}
}

void	ScalarConverter::convertChar() const{
	if (this->_str.length() == 1){
		if (this->_str[0] < 48 || this->_str[0] > 57){
			std::cout<<"'"<<this->_str[0]<<"'"<<std::endl;
			return;
		}
	}
	if (this->_d >= 0 && this->_d <= 255){
		if (this->_d >= 32 && this->_d <= 126){
			char	c = static_cast<int>(this->_d);
			std::cout<<"'"<<c<<"'"<<std::endl;
		} else {
		throw ScalarConverter::NonDisplayable();
		}
	} else {
		throw ScalarConverter::Impossible();
	}
}

void	ScalarConverter::toInt() const{
	std::cout<<"int: ";
	try{
		ScalarConverter::convertInt();
	}
	catch (std::exception &e){
		std::cout<<e.what()<<std::endl;
	}
}

void	ScalarConverter::convertInt() const{
	if (!_possible)
		throw ScalarConverter::Impossible();
	if (this->_d == 0 && this->_str[0] != '0'){
		throw ScalarConverter::Impossible();
	} else {
		if (this->_d >= -2147483648 && this->_d <= 2147483647){

			int	i = static_cast<int>(this->_d);
			std::cout<<i<<std::endl;
		} else {
			throw ScalarConverter::Impossible();
		}
	}
}

void	ScalarConverter::toFloat() const{
	std::cout<<"float: ";
	try{
		ScalarConverter::convertFloat();
	}
	catch (std::exception &e){
		std::cout<<e.what()<<std::endl;
	}
}

void	ScalarConverter::convertFloat() const{
	if (!_possible)
		throw ScalarConverter::Impossible();
	float	f = static_cast<float>(this->_d);
	int		tmp = static_cast<int>(this->_d);
	double	decimal = f - tmp;
	if (!decimal)
		std::cout<<f<<".0f"<<std::endl;
	else {
		if (_str == "+inf" || _str == "+inff")
			std::cout<<'+';
		std::cout<<f<<'f'<<std::endl;
	}
}

void	ScalarConverter::toDouble() const{
	std::cout<<"double: ";
	try{
		ScalarConverter::convertDouble();
	}
	catch (std::exception &e){
		std::cout<<e.what()<<std::endl;
	}
}

void	ScalarConverter::convertDouble() const{
	if (!_possible)
		throw ScalarConverter::Impossible();
	int		tmp = static_cast<int>(this->_d);
	double	decimal = _d - tmp;
	if (!decimal)
		std::cout<<_d<<".0"<<std::endl;
	else {
		if (_str == "+inf" || _str == "+inff")
			std::cout<<'+'<<_d<<std::endl;
		else
			std::cout<<_d<<std::endl;
	}
}

const char* ScalarConverter::NonDisplayable::what() const throw(){
	return "Non displayable";
}

const char* ScalarConverter::Impossible::what() const throw(){
	return "Impossible";
}