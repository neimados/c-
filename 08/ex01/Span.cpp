#include "Span.hpp"

# include <vector>
# include <algorithm>

Span::Span() : _size(0)
{
	std::cout<<"Span default constructor called"<<std::endl;
}

Span::Span(unsigned int n) : _size(n)
{
	std::cout<<"Span constructor called"<<std::endl;
}

Span::Span(const Span &s){
	std::cout<<"Span copy constructor called"<<std::endl;
	*this = s;
}

Span	&Span::operator=(const Span &s){
	std::cout<<"Span copy assignment operator called"<<std::endl;
	_size = s._size;
	_vec = s._vec;
	return *this;
}

Span::~Span(){
	std::cout<<"Span destructor called"<<std::endl;
}

void	Span::addNumber(int num){
	if (_vec.size() == _size)
		throw Span::SpanFull();
	else
		_vec.push_back(num);
}

int	Span::shortestSpan() const{
	int shortest = 2147483647;
	if (_vec.size() <= 1){
		throw Span::NotEnough();
		return 0;
	}
	std::vector<int> tmp = _vec;
	std::sort(tmp.begin(), tmp.end());
	std::vector<int>::iterator it = tmp.begin();
	while (it != tmp.end() - 1){
		shortest = std::min(shortest, *(it + 1) - *it);
		it++;
	}
	return shortest;
}

int	Span::longestSpan() const{
	if (_vec.size() <= 1){
		throw Span::NotEnough();
		return 0;
	}
	std::vector<int> tmp = _vec;
	std::sort(tmp.begin(), tmp.end());
	return tmp.back() - tmp.front();
}

void	Span::addNumberRange(const std::vector<int>::iterator &begin, const std::vector<int>::iterator &end){
	if (_size < std::distance(begin, end))
		throw Span::NotPossible();
	else {
		std::vector<int>::iterator it = begin;
		while (it != end){
			_vec.push_back(*it);
			it++;
		}
	}
	
}

void	Span::printSpan() const{
	std::vector<int> tmp = _vec;
	std::vector<int>::iterator it;
	for (it = tmp.begin(); it != tmp.end(); it++){
		std::cout<<*it<<" ";
	}
	std::cout<<std::endl;
}