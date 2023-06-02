#include "Serializer.hpp"

int	main (void) {
	Data *test = new Data();
	Data *ptr;
	uintptr_t u;
	
	test->i = 12;
	std::cout<<"value i original = "<<test->i<<std::endl;

	u = Serializer::serialize(test);
	std::cout<<"adress = "<<u<<std::endl;

	ptr = Serializer::deserialize(u);
	std::cout<<"value i ptr = "<<ptr->i<<std::endl;

	test->i = 24;
	std::cout<<"value i original = "<<test->i<<std::endl;

	u = Serializer::serialize(test);
	std::cout<<"adress = "<<u<<std::endl;

	ptr = Serializer::deserialize(u);
	std::cout<<"value i ptr = "<<ptr->i<<std::endl;

	delete test;

	return 0;
}