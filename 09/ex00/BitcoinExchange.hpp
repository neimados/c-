#pragma once

# include <iostream>
# include <fstream>
# include <iomanip>
# include <sstream>
# include <map>
# include <string>
# include <cstdlib>

class BitcoinExchange{
	public:
		BitcoinExchange();
		BitcoinExchange(std::string db, std::string input);
		BitcoinExchange(const BitcoinExchange &b);
		BitcoinExchange &operator=(const BitcoinExchange &b);
		~BitcoinExchange();

		void		fillMap();
		void		printData();
		void		checkData(std::string &s1, std::string &s2);
		bool		checkDate(std::string &s1) const;
		int			checkNum(std::string &s2) const;
		std::string	getRate(std::string &s1, std::string &s2) const;
		std::string	pickDate(int &y, int &m, int &d) const;

	private:
		std::map<std::string, std::string>	_m;
		std::string					_db;
		std::string					_input;
};