#include "Span.hpp"

int main()
{
	Span sp = Span(5);
	Span sp3 = Span(5);
	
	std::cout<<"Adding 3 numbers to span 1"<<std::endl;
	try{
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
	}
	catch (std::exception &e){
		std::cout<<e.what()<<std::endl;
	}

	Span sp2 = Span(sp);
	std::cout<<"Test span Full exception"<<std::endl;
	try{
		sp2.addNumber(9);
		sp2.addNumber(11);
		sp2.addNumber(11);
	}
	catch (std::exception &e){
		std::cout<<e.what()<<std::endl;
	}

	std::cout<<"Test copy Span (original not full)"<<std::endl;
	try{
		sp.addNumber(6);
	}
	catch (std::exception &e){
		std::cout<<e.what()<<std::endl;
	}

	std::cout<<"Longest / Shortest Test"<<std::endl;
	try{
	std::cout << sp2.shortestSpan() << std::endl;
	std::cout << sp2.longestSpan() << std::endl;
	std::cout << sp3.shortestSpan() << std::endl;
	}
	catch (std::exception &e){
		std::cout<<e.what()<<std::endl;
	}

	std::cout<<"Adding range iterators test"<<std::endl;
	std::vector<int> range;
	for (int i = 0; i < 10; i++){
		range.push_back(i + 1);
	}
	try {
		sp3.addNumberRange(range.begin(), range.end());
	}
	catch (std::exception &e){
		std::cout<<e.what()<<std::endl;
	}
	std::vector<int>::iterator rangeIt = range.begin() + 5;
	try {
		sp3.addNumberRange(range.begin(), rangeIt);
		sp3.printSpan();
	}
	catch (std::exception &e){
		std::cout<<e.what()<<std::endl;
	}

	return 0;
}