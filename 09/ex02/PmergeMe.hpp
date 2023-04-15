#pragma once

#include <iostream>
#include <deque>
#include <vector>
#include <cstdlib>
#include <ctime>

class PmergeMe{
	public:
		PmergeMe();
		PmergeMe(int argc, char **argv);
		PmergeMe(PmergeMe const &p);
		PmergeMe &operator=(PmergeMe const &p);
		~PmergeMe();

		int convertInt(std::string argv);
		int	getSize();
		void printVec();
		void sortVec(int begin, int end);
		void mergeVec(int begin, int mid, int end);
		void insertVec(int begin, int mid);
		void setTimeVec();

		class InputError : public std::exception {
			public:
				virtual const char* what() const throw();
		};

	private:
		int					_size;
		std::vector<int>	_vec;
		std::deque<int>		_deq;
		clock_t				_vecBegin;
		clock_t				_vecEnd;
		clock_t				_deqBegin;
		clock_t				_deqEnd;
};