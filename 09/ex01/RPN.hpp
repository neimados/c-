#pragma once

#include <iostream>
#include <stack>
#include <cstdlib>
#include <iomanip>

class RPN{
	public:
		RPN();
		RPN(std::string input);
		RPN(const RPN &r);
		RPN &operator=(const RPN &r);
		~RPN();

		void	fillStack();
		void	firstCalc();
		void	calculate();
		double	signOp(double a, double b, char c);

		class InputError : public std::exception {
			public:
				virtual const char* what() const throw();
		};

	private:
		std::string			_input;
		double				_res;
		std::stack<char>	_s;
};