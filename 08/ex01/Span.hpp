#pragma once

# include <iostream>
# include <vector>

class Span {
	public:
		Span();
		Span(unsigned int n);
		Span(const Span &s);
		Span &operator=(const Span &s);
		~Span();

		void	addNumber(int num);
		int		shortestSpan() const;
		int		longestSpan() const;
		void	addNumberRange(const std::vector<int>::iterator &begin, const std::vector<int>::iterator &end);

		void	printSpan() const;

		class SpanFull : public std::exception {
			public:
				virtual const char* what() const throw(){
					return "Span already full";
				}
		};

		class NotEnough : public std::exception {
			public:
				virtual const char* what() const throw(){
					return "Not enough numbers";
				}
		};

		class NotPossible : public std::exception {
			public:
				virtual const char* what() const throw(){
					return "Not Possible (not enough space in span)";
				}
		};

	private:
		unsigned int 		_size;
		std::vector<int>	_vec;
};