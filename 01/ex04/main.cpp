#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>

int	main(int argc, char **argv){
	std::ifstream		input;
	std::ofstream		output;
	std::string 		filename;
	std::string			outfile;
	std::string			s1;
	std::string			s2;
	std::stringstream	ss;
	std::string			content;
	size_t 				pos = 0;
	
	if (argc != 4){
		std::cout<<"Arguments error"<<std::endl;
	} else {
		filename = argv[1];
		s1 = argv[2];
		s2 = argv[3];
		input.open(argv[1]);
		if (!input.is_open() || s1 == ""){
			std::cout<<"Arguments error"<<std::endl;
			return 1;
		}
		outfile = filename.append(".replace");
		output.open(outfile.c_str());
		if (!output.is_open()){
			std::cout<<"Arguments error"<<std::endl;
			input.close();
			return 1;
		}
		ss << input.rdbuf();
		content = ss.str();
		while((pos = content.find(s1, pos)) != std::string::npos)
		{
			content.erase(pos, s1.length());
			content.insert(pos, s2);
			pos += s2.length();
		}
		output << content;
		input.close();
		output.close();
	}
	return 0;
}