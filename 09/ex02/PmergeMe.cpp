#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe(int argc, char **argv){
	_vecBegin = clock();
	for (int i = 1; i < argc; i++){
		_vec.push_back(convertInt(argv[i]));
	}
	_deqBegin = clock();
	for (int j = 1; j < argc; j++){
		_deq.push_back(convertInt(argv[j]));
	}
	_size = _vec.size();
}

PmergeMe::PmergeMe(PmergeMe const &p){
	*this = p;
}

PmergeMe &PmergeMe::operator=(PmergeMe const &p){
	_vec = p._vec;
	_deq = p._deq;
	_size = p._size;
	return *this;
}

PmergeMe::~PmergeMe(){}

const char* PmergeMe::InputError::what() const throw(){
	return "Error: Input bad format !";
}

int	PmergeMe::convertInt(std::string argv){
	long res = 0;
	for (unsigned int i = 0; i < argv.size(); i++){
		if (!std::isdigit(argv[i]))
			throw PmergeMe::InputError();
	}
	res = std::atol(argv.c_str());
	if (res < 0 || res > 2147483647)
		throw PmergeMe::InputError();
	return res;
}

void PmergeMe::printVec(){
	std::vector<int>::iterator it = _vec.begin();
	while (it != _vec.end()){
		std::cout<<*it<<std::endl;
		it++;
	}
	double time = static_cast<double>(_vecEnd - _vecBegin) / CLOCKS_PER_SEC * 1000;
	std::cout << "Time to process a range of " << _size << " elements with std::[vector]: " << time << "us" << std::endl;
}

int	PmergeMe::getSize(){
	return _size;
}

void PmergeMe::sortVec(int begin, int end){
	if (end - begin > 5) {
		int mid = (begin + end) / 2;
		sortVec(begin, mid);
		sortVec(mid + 1, end);
		mergeVec(begin, mid, end);
	} else {
		insertVec(begin, end);
	}
}

void PmergeMe::mergeVec(int begin, int mid, int end){
	int n1 = mid - begin + 1;
	int n2 = end - mid;
	int lindex, rindex = 0;
	std::vector<int> left;
	std::vector<int> right;

	for(int i = 0; i <= mid; i++){
		left.push_back(_vec[i]);
	}
	for (int j = mid + 1; j <= end; j++){
		right.push_back(_vec[j]);
	}
	for (int k = begin; k < end - begin + 1; k++){
		if (rindex == n2){
			_vec[k] = left[lindex];
			lindex++;
		} else if (lindex == n1) {
			_vec[k] = right[rindex];
			rindex++;
		} else if (right[rindex] > left[lindex]) {
			_vec[k] = left[lindex];
			lindex++;
		} else {
			_vec[k] = right[rindex];
			rindex++;
		}
	}
}

void PmergeMe::insertVec(int begin, int mid) {
	for (int i = begin; i < mid; i++){
		int tmp = _vec[i + 1];
		int j = i + 1;
		while (j > begin && _vec[j -1] > tmp) {
			_vec[j] = _vec[j - 1];
			j--;
		}
		_vec[j] = tmp;
	}
	std::vector<int> vecTmp;
	for (int j = begin; j <= mid; j++) {
		vecTmp.push_back(_vec[j]);
	}
}

void	PmergeMe::setTimeVec(){
	_vecEnd = clock();
}