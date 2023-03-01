#pragma once

# include <iostream>

template <typename T>
void	printElement(const T &element){
	std::cout<<element<<std::endl;
}

template <typename T>
void	iter(T *address, int length, void (*ptr)(const T &element)){
	for (int i = 0; i < length; i++){
		ptr(address[i]);
	}
}