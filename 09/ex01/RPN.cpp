#include "RPN.hpp"

RPN::RPN(){}

RPN::RPN(std::string input){
	_input = input;
}

RPN::RPN(RPN const &r){
	*this= r;
}

RPN	&RPN::operator=(RPN const &r){
	_input = r._input;
	_res = r._res;
	_s = r._s;
	return *this;
}

RPN::~RPN(){}

void RPN::fillStack(){
	for(int i = _input.size() - 1; i >= 0; i--){
		if (!std::isspace(_input[i])){
			if (std::isdigit(_input[i]) || _input[i] == '+'
			|| _input[i] == '-' || _input[i] == '*' || _input[i] == '/')
				_s.push(_input[i]);
			else
				throw RPN::InputError();
		}
	}
	if (_s.size() < 3)
		throw RPN::InputError();
}

void	RPN::firstCalc(){
	int	a, b = 0;
	for (int i = 0; i < 3; i++){
		if (i <= 1 && (_s.top() == '+' || _s.top() == '-'
		|| _s.top() == '*' || _s.top() == '/'))
			throw RPN::InputError();
		if (i == 0)
			a = _s.top() - 48;
		if (i == 1)
			b = _s.top() - 48;
		else 
			_res = RPN::signOp(a, b, _s.top());
		_s.pop();
	}
}

void	RPN::calculate(){
	if (_s.size() == 0){
		std::cout<<_res<<std::endl;
		return;
	}
	if (_s.size() < 2)
		throw RPN::InputError();
	int size = _s.size();
	int tmp = 0;
	for (int i = 0; i < size; i++){
		if (i % 2 == 0){
			if (!std::isdigit(_s.top()) || i == size - 1)
				throw RPN::InputError();
			tmp = _s.top() - 48;
		}
		else {
			if (_s.top() != '+'&& _s.top() != '-'
			&& _s.top() != '*' && _s.top() != '/')
				throw RPN::InputError();
			_res = RPN::signOp(_res, tmp, _s.top());
		}
		_s.pop();
	}
	std::cout<<_res<<std::endl;
}

double	RPN::signOp(double a, double b, char c){
	if (c == '+')
		return (a + b);
	if (c == '-')
		return (a - b);
	if (c == '*')
		return (a * b);
	if (c == '/')
		return (a / b);
	return 0;
}

const char* RPN::InputError::what() const throw(){
	return "Error: Input bad format !";
}
