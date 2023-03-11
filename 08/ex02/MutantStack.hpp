#pragma once

# include <iostream>
# include <list>
# include <stack>
# include <deque>

template <typename T>
class MutantStack : public std::stack<T>
{
	public: 
		MutantStack(){
			std::cout<<"MutantStack constructor called"<<std::endl;
		};
		MutantStack(const MutantStack &m){
			std::cout<<"MutantStack copy constructor called"<<std::endl;
			*this = m;
		}
		MutantStack	&operator=(const MutantStack &m){
			std::cout<<"MutantStack assignement operator called"<<std::endl;
			return *this;
		}
		~MutantStack(){
			std::cout<<"MutantStack destructor called"<<std::endl;
		}

		typedef typename MutantStack<T>::stack::container_type::iterator iterator;
		iterator begin(){
			return this->c.begin();
		}
		iterator end(){
			return this->c.end();
		}
};

