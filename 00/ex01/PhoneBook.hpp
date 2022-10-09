#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

# include <iostream>
# include "Contact.hpp"

class PhoneBook {
	public:
		PhoneBook();
		~PhoneBook();
		void	setPhoneBook(int i);
		void	getPhoneBook();

	private:
		Contact _c[8];
};

#endif