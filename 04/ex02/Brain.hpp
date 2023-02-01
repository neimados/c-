#pragma once

#include <iostream>

class Brain {
	public:
		Brain();
		Brain(const Brain &b);
		Brain &operator=(const Brain &b);
		~Brain();

		void		setIdea(const std::string &idea);
		std::string	getIdea(int i) const;

	protected:
		std::string ideas[100];
	
	private:
		int	index;
};