#include "PmergeMe.hpp"

int	main(int argc, char **argv){
	if (argc == 1){
		std::cout<<"Arguments error !"<<std::endl;
		return 1;
	}
	try {
		PmergeMe p(argc, argv);
		p.sortVec(0, p.getSize() - 1);
		p.setTimeVec();
		p.sortDeq(0, p.getSize() - 1);
		p.setTimeDeq();
		p.printSort();
	} catch (std::exception &e) {
		std::cout<<e.what()<<std::endl;
	}

	return 0;
}