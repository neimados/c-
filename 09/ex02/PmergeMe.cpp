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
	_origin = _vec;
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

void PmergeMe::printSort(){
	std::vector<int>::iterator it;
	it = _origin.begin();
	std::cout<<"Before: ";
	while (it != _origin.end()){
		std::cout<<*it<<" ";
		it++;
	}
	std::cout<<std::endl<<"Afer: ";
	it = _vec.begin();
	while (it != _vec.end()){
		std::cout<<*it<<" ";
		it++;
	}
	std::cout<<std::endl;
	double vtime = static_cast<double>(_vecEnd - _vecBegin) / CLOCKS_PER_SEC * 1000 * 1000;
	double dtime = static_cast<double>(_deqEnd - _deqBegin) / CLOCKS_PER_SEC * 1000 * 1000;
	std::cout << "Time to process a range of " << _size << " elements with std::[vector] : " << vtime << "us" << std::endl;
	std::cout << "Time to process a range of " << _size << " elements with std::[deque] : " << dtime << "us" << std::endl;
}

int	PmergeMe::getSize(){
	return _size;
}

void PmergeMe::sortVec(int left, int right){
	int n = right - left + 1;

	if (n < 5) {
		insertVec(left, right);
		return;
	}
	int mid = (left + right) / 2;
	sortVec(left, mid);
	sortVec(mid + 1, right);
	mergeVec(left, mid, right);
}

void PmergeMe::mergeVec(int left, int mid, int right){
	int i, j = 0;
	std::vector<int> tmp;

	i = left;
	j = mid + 1;
	while (i <= mid && j <= right) {
		if (_vec[i] < _vec[j]) {
			tmp.push_back(_vec[i]);
			i++;
		}
		else {
			tmp.push_back(_vec[j]);
			j++;
		}
	}
	while (i <= mid) {
		tmp.push_back(_vec[i]);
		i++;
	}
	while (j <= right) {
		tmp.push_back(_vec[j]);
		j++;
	}
	i = left;
	j = 0;
	while (i <= right) {
		_vec[i] = tmp[j];
		i++;
		j++;
	}
}

void PmergeMe::insertVec(int left, int right) {
	int tmp;
	int i;
	int j;

	for (i = left + 1; i <= right; i++) {
		tmp = _vec[i];
		for (j = i - 1; j >= left && _vec[j] > tmp; j--)
			_vec[j + 1] = _vec[j];
		_vec[j + 1] = tmp;
	}
}

void	PmergeMe::setTimeVec(){
	_vecEnd = clock();
}

void PmergeMe::sortDeq(int left, int right){
	int n = right - left + 1;

	if (n < 5) {
		insertDeq(left, right);
		return;
	}
	int mid = (left + right) / 2;
	sortDeq(left, mid);
	sortDeq(mid + 1, right);
	mergeDeq(left, mid, right);
}

void PmergeMe::mergeDeq(int left, int mid, int right){
	int i, j = 0;
	std::deque<int> tmp;

	i = left;
	j = mid + 1;
	while (i <= mid && j <= right) {
		if (_deq[i] < _deq[j]) {
			tmp.push_back(_deq[i]);
			i++;
		}
		else {
			tmp.push_back(_deq[j]);
			j++;
		}
	}
	while (i <= mid) {
		tmp.push_back(_deq[i]);
		i++;
	}
	while (j <= right) {
		tmp.push_back(_deq[j]);
		j++;
	}
	i = left;
	j = 0;
	while (i <= right) {
		_deq[i] = tmp[j];
		i++;
		j++;
	}
}

void PmergeMe::insertDeq(int left, int right) {
	int tmp;
	int i;
	int j;

	for (i = left + 1; i <= right; i++) {
		tmp = _deq[i];
		for (j = i - 1; j >= left && _deq[j] > tmp; j--)
			_deq[j + 1] = _deq[j];
		_deq[j + 1] = tmp;
	}
}

void	PmergeMe::setTimeDeq(){
	_deqEnd = clock();
}