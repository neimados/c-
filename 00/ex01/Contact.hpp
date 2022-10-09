#ifndef CONTACT_HPP
#define CONTACT_HPP

# include <iostream>

class Contact {

	public:
		Contact();
		~Contact();
		void	setContact();
		std::string	getFirstName();
		std::string	getLastName();
		std::string	getNickName();
		std::string	getPhone();
		std::string getSecret();

	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickName;
		std::string	_phone;
		std::string	_secret;
};

#endif