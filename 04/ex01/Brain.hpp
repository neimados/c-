#pragma once

#include <iostream>

class Brain {
	public:
		Brain();
		Brain(const Brain &b);
		Brain &operator=(const Brain &b);
		~Brain();

	protected:
		std::string ideas[100];
};