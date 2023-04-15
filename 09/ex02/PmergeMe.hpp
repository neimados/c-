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
		void printSort();
		void sortVec(int left, int right);
		void mergeVec(int left, int mid, int right);
		void insertVec(int left, int right);
		void setTimeVec();
		void sortDeq(int left, int right);
		void mergeDeq(int left, int mid, int right);
		void insertDeq(int left, int right);
		void setTimeDeq();

		class InputError : public std::exception {
			public:
				virtual const char* what() const throw();
		};

	private:
		int					_size;
		std::vector<int>	_vec;
		std::vector<int>	_origin;
		std::deque<int>		_deq;
		clock_t				_vecBegin;
		clock_t				_vecEnd;
		clock_t				_deqBegin;
		clock_t				_deqEnd;
};