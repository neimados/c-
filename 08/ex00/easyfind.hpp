#pragma once

# include <iostream>
# include <algorithm>

class NotFound : public std::exception{
	public:
		virtual const char* what() const throw(){
			return "Not Found";
		}
};

template <typename T>
typename T ::iterator	easyfind(T &arr, int i){
	typename T::iterator	it;

	it = std::find(arr.begin(), arr.end() - 1, i);
	if (it == arr.end() - 1){
		if (i != *(arr.end() - 1))
			throw NotFound();
	}
	return it;
}