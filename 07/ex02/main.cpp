#include "Array.hpp"

template <typename T>
std::ostream &operator<<(std::ostream &out, Array<T> const &a)
{
	out<<a.size();
	return out;
}

int main(void){
	Array<int> *test = new Array<int>;
	std::cout<<*test<<std::endl;

	Array<int> *arr1 = new Array<int>(30);
	Array<int> *arr2 = new Array<int>(*arr1);

	std::cout<<"ORIGINAL"<<std::endl;
	std::cout<<*arr1<<std::endl;
	std::cout<<*arr2<<std::endl;
	arr2->test();
	std::cout<<"ALTERED ARR2"<<std::endl;
	std::cout<<*arr1<<std::endl;
	std::cout<<*arr2<<std::endl;
	std::cout<<"COPY TEST"<<std::endl;
	*arr2 = *arr1;
	std::cout<<*arr1<<std::endl;
	std::cout<<*arr2<<std::endl;
	std::cout<<"DELETE ARR1 TEST"<<std::endl;
	delete arr1;
	std::cout<<*arr2<<std::endl;

	std::cout<<"INDEX TEST"<<std::endl;
	Array<int> num(30);
	for (int i = 0; i < 30; i++){
		num[i] = i * 10;
	}
	try{
		std::cout<<num[0]<<std::endl;
		std::cout<<num[1]<<std::endl;
		std::cout<<num[2]<<std::endl;
		std::cout<<num[-2]<<std::endl;
	}
	catch (std::exception &e){
		std::cout<<e.what()<<std::endl;
	}
	try{
		std::cout<<num[29]<<std::endl;
	}
	catch (std::exception &e){
		std::cout<<e.what()<<std::endl;
	}
	try{
		std::cout<<num[30]<<std::endl;
	}
	catch (std::exception &e){
		std::cout<<e.what()<<std::endl;
	}

	delete arr2;
	delete test;

	return 0;
}