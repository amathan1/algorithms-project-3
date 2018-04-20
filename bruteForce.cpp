
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
bruteForce::findCombinations(int &r, int st, std::vector <int> &combination, std::vector < std::vector <int> >& cur_comb, int &done, int &n_c_r) 
{

	int idx;
	std::vector < std::vector <int> > new_clones;
	new_clones.resize(this->n_elem+1 - st);
	for (int i = st; i < this->n_elem+1; i++) { 
		new_clones[i-st] = combination; 
	}

	for (int i = 0; i < new_clones.size(); i++)
	{
		if (done >= n_c_r)	continue;
		if (new_clones[i].size() == r) {
			cur_comb[done] = new_clones[i];
			done++;
			return 0;
		}
		if (i+st >= this->n_elem)	continue;
		if (new_clones[i][new_clones[i].size()-1] >= i+st)	continue;
		new_clones[i].push_back(i+st);
		findCombinations(r, st+1, new_clones[i], cur_comb, done, n_c_r);
	}

	return 0;
}



int 
bruteForce::binomialCoeffecient(int r, std::vector < std::vector <int> >& cur_comb)
{	
	std::cout << "We are computing " << n_elem << " C " << r << std::endl;

	if (this->n_elem == r) {
		cur_comb.resize(1);
		for (int i = 0; i < this->n_elem; i++) {
			cur_comb[0].push_back(i);
		}
		return 0;
	}

	int n_c_r, num = 1, den = 1, done = 0;

	for (int i = 0; i < r; i++) {
		num *= (this->n_elem-i);
		den *= (i+1);
	}

	n_c_r = num / den;
	cur_comb.resize(n_c_r);
	std::vector <int> temp;

	std::cout << "And the n_c_r is " << n_c_r << std::endl;

	for (int i = 0; i < this->n_elem; i++) {
		temp.clear();
		temp.push_back(i);
		std::cout << "Inside we pushed " << i << std::endl;
		findCombinations(r, i+1, temp, cur_comb, done, n_c_r);
	}

	return 0;
}


int 
bruteForce::findCosts(std::vector < std::vector <int> > &bc, std::vector <int> &costs)
{
	/*
	* Given a combination, find corresponding costs.
	*/


}


int
bruteForce::findOptimalCombination()
{
	/*
	* Finds the optimal solution to 0/1 knapsack problem using brute force approach. 
	* Extremely inefficient. Do not try this at home. Haha
	*/

	int total_combinations = pow(2, this->n_elem);

	std::vector < std::vector < std::vector <int> > > combinations;
	combinations.resize(this->n_elem);

	// First we calculate the binomial coefficient for knapsack with all capacities
	for (int i = 0; i < this->n_elem; i++) {
		binomialCoeffecient(i+1, combinations[i]);
	}

	std::cout << "Hope it's done" << std::endl;

	for (int i = 0; i < combinations.size(); i++) {
		std::cout << "Current Size #" << i << " is " << combinations[i].size() << std::endl;
		for (int j = 0; j < combinations[i].size(); j++) {
			for (int k = 0; k < combinations[i][j].size(); k++) {
				std::cout << combinations[i][j][k] << " ";
			}
			std::cout << std::endl;
		}
	}

	return 0;
}






int 
main(int argc, char* argv[])
{

	if (argc != 2) {std::cerr << "[Usage] ./bruteForce.out <input_file_name>.csv"; exit(0);}

	bruteForce bf(argv[1]);

	bf.findOptimalCombination();

	return 0;	
}
