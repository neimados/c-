#pragma once

# include <iostream>

template <typename T>
class Array{
	public: 
		Array<T>() :	_size(0)
		{
			_arr = new T[_size];
			std::cout<<"Array default constructor called"<<std::endl;
		}

		Array<T>(unsigned int n):	_size(n)
		{
			_arr = new T[n];
			std::cout<<"Array constructor called"<<std::endl;
		}

		Array<T>(const Array<T> &a){
			std::cout<<"Array copy constructor called"<<std::endl;
			_arr = new T[a._size];
			*this = a;
		}

		Array<T> &operator=(const Array<T> &a){
			_size = a._size;
			for (unsigned int i = 0; i < _size; i++){
				_arr[i] = a._arr[i];
			}
			std::cout<<"Array assignement operator called"<<std::endl;
			return *this;
		}

		T &operator[](int i) {
		if (i < 0 || (unsigned int)i >= this->_size)
			throw Array::InvalidIndex();
		return _arr[i];
		}
		
		~Array<T>(){
			if (_arr)
				delete [] _arr;
			std::cout<<"Array destructor called"<<std::endl;
		}

		class InvalidIndex : public std::exception{
			public:
				virtual const char* what() const throw(){
					return "Invalid Index";
				}
		};

		unsigned int size() const{
			return _size;
		}

		void	test(){
			_size = 42;
		}

	private:
		T				*_arr;
		unsigned int	_size;
};
