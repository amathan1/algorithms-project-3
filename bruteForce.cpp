
#include "bruteForce.hpp"
#include <cmath>

int
bruteForce::printData()
{

	std::cout << "Item#\tItem_Value\tItem_Weight" << std::endl; 

	for (int i = 0; i < this->n_elem; i++) {
		std::cout << "Item #" << i+1 << ":\t" << items[0][i] << "\t" << items[1][i] << std::endl;
	}

	return 0;
}


int
bruteForce::findOptimalCombination()
{

	int total_combinations = pow(2, this->n_elem);

	return 0;
}












int 
main(int argc, char* argv[])
{

	if (argc != 2) {std::cerr << "[Usage] ./bruteForce.out <input_file_name>.csv"; exit(0);}

	bruteForce bf(argv[1]);

	

	return 0;	
}
