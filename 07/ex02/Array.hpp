#pragma once

# include <iostream>

template <typename T>
class Array{
	public: 
		Array() :	_size(0)
		{
			_arr = new T[0];
			std::cout<<"Array default constructor called"<<std::endl;
		}

		Array(unsigned int n):	_size(n)
		{
			_arr = new T[n];
			std::cout<<"Array constructor called"<<std::endl;
		}

		Array(const Array &a){
			std::cout<<"Array copy constructor called"<<std::endl;
			_arr = new T[a._size];
			*this = a;
		}

		Array &operator=(const Array &a){
			_size = a._size;
			for (unsigned int i = 0; i < _size; i++){
				_arr[i] = a._arr[i];
			}
			std::cout<<"Array assignement operator called"<<std::endl;
			return *this;
		}
		
		~Array(){
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
