#pragma once

#include <iostream>

class PmergeMe{
	public:
		PmergeMe();
		PmergeMe(PmergeMe const &p);
		PmergeMe &operator=(PmergeMe const &p);
		~PmergeMe();

	private:

};