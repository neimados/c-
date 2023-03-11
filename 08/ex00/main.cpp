#include "easyfind.hpp"


int	main(void){
	std::vector<int> vec;
	std::vector<int>::iterator it1;
	std::vector<int>::iterator it2;
	std::vector<int>::iterator it3;

	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(12);
	vec.push_back(123);
	vec.push_back(34534);
	vec.push_back(-234);
	vec.push_back(42234);
	vec.push_back(-21234);
	vec.push_back(422);

	try{
		it1 = easyfind(vec, -234);
		std::cout<<*it1<<std::endl;
		it2 = easyfind(vec, 422);
		std::cout<<*it2<<std::endl;
		it3 = easyfind(vec, 13);
		std::cout<<*it3<<std::endl;

	}
	catch (std::exception &e){
		std::cout<<e.what()<<std::endl;
	}
}