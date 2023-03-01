#include "iter.hpp"

int	main (void){
	int arr1[5] = {1, 2, 3, 4, 5};
	std::string arr2[5] = {"un", "deux", "troix", "quatre", "cinq"};
	float arr3[5] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};

	::iter(arr1, 5, printElement);
	::iter(arr2, 5, printElement);
	::iter(arr3, 5, printElement);

	return 0;
}