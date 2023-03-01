#include "data.hpp"

uintptr_t serialize(Data* ptr){
	return reinterpret_cast<uintptr_t>(ptr);
}

Data*	deserialize(uintptr_t raw){
	return reinterpret_cast<Data *>(raw);
}

int	main (void) {
	Data *test = new Data();
	Data *ptr;
	uintptr_t u;
	
	test->i = 12;
	std::cout<<"value i original = "<<test->i<<std::endl;

	u = serialize(test);
	std::cout<<"adress = "<<u<<std::endl;

	ptr = deserialize(u);
	std::cout<<"value i ptr = "<<ptr->i<<std::endl;

	test->i = 24;
	std::cout<<"value i original = "<<test->i<<std::endl;

	u = serialize(test);
	std::cout<<"adress = "<<u<<std::endl;

	ptr = deserialize(u);
	std::cout<<"value i ptr = "<<ptr->i<<std::endl;

	delete test;

	return 0;
}