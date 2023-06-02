#include "ScalarConverter.hpp"

// ScalarConverter::ScalarConverter() :	_str(""),
// 										_d(0.0),
// 										_possible(true),
// 										_count(0),
// 										_dot(0)
// {
//     std::cout<<"ScalarConverter default constructor called"<<std::endl;
// 	std::cout<<"Missing parameter"<<std::endl;
// }

// ScalarConverter::ScalarConverter(std::string &str) :	_str(str),
// 														_possible(true),
// 														_count(0),
// 														_dot(0)
// {
// 	this->_d = std::strtod(str.c_str(), NULL);
// 	std::cout<<"ScalarConverter constructor called"<<std::endl;
// }

// ScalarConverter::ScalarConverter(const ScalarConverter &conv){
//     std::cout<<"ScalarConverter copy constructor called"<<std::endl;
//     *this = conv;
// }

// ScalarConverter &ScalarConverter::operator= (const ScalarConverter &conv){
//     std::cout<<"ScalarConverter assignment operator called"<<std::endl;
// 	this->_str = conv._str;
//     return *this;
// }

// ScalarConverter::~ScalarConverter(){
//     std::cout<<"ScalarConverter destructor called"<<std::endl;
// }

int	ScalarConverter::check(std::string &input){
	int count = 0;
	int dot = 0;

	for (unsigned int i = 0; i < input.length(); i++){
		if (input[i] < 48 || input[i] > 57){
			if (input[i] == '.' && (i != 0 || i != input.length() - 1)){
				dot += 1;
				continue;
			}
			else if (input[i] == 'f' && i == input.length() - 1)
				continue;
			else
				count += 1;
		}
	}
	if (input == "nan" || input == "+inf" || input == "-inf"
		|| input == "nanf" || input == "+inff" || input == "-inff"
		|| input == "inf" || input == "inff")
		return 1;
	if (count || dot > 1)
		return 0;

	return 1;
}


void	ScalarConverter::convert(std::string &input){
	int i = 1;
	i = ScalarConverter::check(input);

	ScalarConverter::toChar(input);
	ScalarConverter::toInt(input, i);
	ScalarConverter::toFloat(input, i);
	ScalarConverter::toDouble(input, i);
}

void	ScalarConverter::toChar(std::string &input) {
	std::cout<<"char: ";
	try{
		ScalarConverter::convertChar(input);
	}
	catch (std::exception &e){
		std::cout<<e.what()<<std::endl;
	}
}

void	ScalarConverter::convertChar(std::string &input) {
	if (input.length() == 1){
		if (input[0] < 48 || input[0] > 57){
			std::cout<<"'"<<input[0]<<"'"<<std::endl;
			return;
		}
	}

	double d = std::strtod(input.c_str(), NULL);
	if (d >= 0 && d <= 255){
		if (d >= 32 && d <= 126){
			char	c = static_cast<int>(d);
			std::cout<<"'"<<c<<"'"<<std::endl;
		} else {
		throw ScalarConverter::NonDisplayable();
		}
	} else {
		throw ScalarConverter::Impossible();
	}
}

void	ScalarConverter::toInt(std::string &input, int i) {
	std::cout<<"int: ";
	try{
		ScalarConverter::convertInt(input, i);
	}
	catch (std::exception &e){
		std::cout<<e.what()<<std::endl;
	}
}

void	ScalarConverter::convertInt(std::string &input, int i) {
	if (i == 0)
		throw ScalarConverter::Impossible();

	double d = std::strtod(input.c_str(), NULL);

	if (d == 0 && input[0] != '0'){
		throw ScalarConverter::Impossible();
	} else {
		if (d >= -2147483648 && d <= 2147483647){

			int	i = static_cast<int>(d);
			std::cout<<i<<std::endl;
		} else {
			throw ScalarConverter::Impossible();
		}
	}
}

void	ScalarConverter::toFloat(std::string &input, int i) {
	std::cout<<"float: ";
	try{
		ScalarConverter::convertFloat(input, i);
	}
	catch (std::exception &e){
		std::cout<<e.what()<<std::endl;
	}
}

void	ScalarConverter::convertFloat(std::string &input, int i) {
	if (i == 0)
		throw ScalarConverter::Impossible();
	
	double d = std::strtod(input.c_str(), NULL);

	float	f = static_cast<float>(d);
	int		tmp = static_cast<int>(d);
	double	decimal = f - tmp;
	if (!decimal)
		std::cout<<f<<".0f"<<std::endl;
	else {
		if (input == "+inf" || input == "+inff")
			std::cout<<'+';
		std::cout<<f<<'f'<<std::endl;
	}
}

void	ScalarConverter::toDouble(std::string &input, int i) {
	std::cout<<"double: ";
	try{
		ScalarConverter::convertDouble(input, i);
	}
	catch (std::exception &e){
		std::cout<<e.what()<<std::endl;
	}
}

void	ScalarConverter::convertDouble(std::string &input, int i) {
	if (i == 0)
		throw ScalarConverter::Impossible();
	
	double d = std::strtod(input.c_str(), NULL);

	int		tmp = static_cast<int>(d);
	double	decimal = d - tmp;
	if (!decimal)
		std::cout<<d<<".0"<<std::endl;
	else {
		if (input == "+inf" || input == "+inff")
			std::cout<<'+'<<d<<std::endl;
		else
			std::cout<<d<<std::endl;
	}
}

const char* ScalarConverter::NonDisplayable::what() const throw(){
	return "Non displayable";
}

const char* ScalarConverter::Impossible::what() const throw(){
	return "Impossible";
}