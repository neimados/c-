#include "Array.hpp"

template <typename T>
std::ostream &operator<<(std::ostream &out, T const &a)
{
	out<<a.size();
	return out;
}

int main(void){
	Array<int> arr1;
	Array<int> arr2(5);
	Array<int> arr3(arr2);

	Array<int> *test = new Array<int>(5);
	std::cout<<*test<<std::endl;

	// std::cout<<"ARR2:"<<arr2<<std::endl;
	// std::cout<<"ARR3:"<<&arr3<<std::endl;

	delete test;

	return 0;
}