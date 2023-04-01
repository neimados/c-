#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){
	std::cout<<"Missing Argument"<<std::endl;
}

BitcoinExchange::BitcoinExchange(std::string db, std::string input){
	_db = db;
	_input = input;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &b){
	// std::cout<<"Copy constructor called"<<std::endl;
	*this = b;
}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &b){
	// std::cout<<"Copy assignment operator called"<<std::endl;
	_m = b._m;
	_db = b._db;
	_input = _input;
	return *this;
}

BitcoinExchange::~BitcoinExchange(){
	// std::cout<<"Destructor called"<<std::endl;
}

void	BitcoinExchange::fillMap(){
	std::ifstream		db;
	std::string			line = "";

	db.open(_db.c_str());
	if (!db.is_open()){
		std::cout<<"Database error"<<std::endl;
		return;
	}
	while (std::getline(db, line)){
		_m.insert(std::pair<std::string, std::string>((line.substr(0, 10)), (line.substr(11, line.size() - 11))));
	}
	db.close();
}

void	BitcoinExchange::printData(void){
	std::ifstream		db;
	std::ifstream		input;
	std::string	line = "";
	std::string s1;
	std::string s2;
	bool		go;

	db.open(_db.c_str());
	if (!db.is_open()){
		std::cout<<"Database error"<<std::endl;
		return;
	}
	db.close();
	input.open(_input.c_str());
	if (!input.is_open()){
		std::cout<<"Arguments error"<<std::endl;
		return;
	}
	while (std::getline(input, line))
	{
			if (line.substr(0, 4) != "date"){
			go = true;
			s1 = "";
			s2 = "";
			for (unsigned int i = 0; i < line.size(); i++){
				if (line[i] == '|')
					go = false;
				else {
					if (go){
						if (line[i] != ' ')
							s1.push_back(line[i]);
					}
					else{
						if (line[i] != ' ')
							s2.push_back(line[i]);
					}
				}
			}
			checkData(s1, s2);
			std::cout<<s2<<std::endl;
		}
	}
	input.close();
}

void	BitcoinExchange::checkData(std::string &s1, std::string &s2){
	std::string rate;
	if (s1 == ""){
		s2 = "Error: missing date.";
	} else if (checkDate(s1)){
		s2 = "Error: bad input => " + s1;
	} else if (checkNum(s2) == 1){
		s2 = "Error: not a positive number.";
	} else if (checkNum(s2) == 2){
		s2 = "Error: too large a number.";
	}
	else {
		rate = getRate(s1, s2);
		s2 = s1 + " => " + s2 + " = " + rate;
	}
}

bool	BitcoinExchange::checkDate(std::string &s1) const{
	int year = std::atoi((s1.substr(0 , 4)).c_str());
	int month = std::atoi((s1.substr(5 , 2)).c_str());
	int day = std::atoi((s1.substr(8 , 2)).c_str());
	if (year < 2009 || year > 2022)
		return 1;
	if (month < 1 || month > 12)
		return 1;
	if (day < 1 || day > 31)
		return 1;
	return 0;
}

int BitcoinExchange::checkNum(std::string &s2) const{
	long num = std::atol(s2.c_str());
	if (num < 0)
		return 1;
	if (num > 1000)
		return 2;
	return 0;
}

std::string BitcoinExchange::getRate(std::string &s1, std::string &s2) const{
	int year = std::atoi((s1.substr(0 , 4)).c_str());
	int month = std::atoi((s1.substr(5 , 2)).c_str());
	int day = std::atoi((s1.substr(8 , 2)).c_str());
	std::map<std::string, std::string>::const_iterator it = _m.end();
	std::ostringstream rr;
	float	rate;
	
	it = _m.find(s1);
	while (it == _m.end()){
		it = _m.find(pickDate(year, month, day));
	}
	rate = (std::atof(s2.c_str())) * (std::atof((it->second).c_str()));
	rr << rate;
	return rr.str();
}

std::string BitcoinExchange::pickDate(int &y, int &m, int &d) const{
	std::ostringstream yy;
	std::ostringstream mm;
	std::ostringstream dd;
	std::string month;
	std::string day;
	
	if (d - 1 == 0){
		d = 31;
		if (m - 1 == 0){
			y--;
			m = 12;
		} else {
			m--;
		}
	} else {
		d--;
	}
	yy << y;
	mm << m;
	dd << d;
	std::string date = yy.str() + '-';
	if (m < 10)
		date.append('0' + mm.str());
	else
		date.append(mm.str());
	date.push_back('-');
	if (d < 10)
		date.append('0' + dd.str());
	else
		date.append(dd.str());
	return date;
}