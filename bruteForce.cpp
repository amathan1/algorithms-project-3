
#include "bruteForce.hpp"
#include <cmath>

inline int 
bruteForce::findCombinations(int &r, int st, std::vector <int> &combination, std::vector < std::vector <int> >& cur_comb, int &done, int &n_c_r) 
{
	/*
	* Recursive tree method to build combinations
	*/

	int idx;
	std::vector < std::vector <int> > new_clones;
	new_clones.resize(this->n_elem+1 - st);
	for (int i = st; i < this->n_elem+1; i++) { 
		new_clones[i-st] = combination; 
	}

	for (int i = 0; i < new_clones.size(); i++)
	{
		if (done >= n_c_r)	continue;		// When we are done adding all combinations
		if (new_clones[i].size() == r) {
			cur_comb[done] = new_clones[i];
			done++;
			return 0;
		}
		if (i+st >= this->n_elem)	continue;	// Whatever to be pushed inside should not be greater than max elements
		if (new_clones[i][new_clones[i].size()-1] >= i+st)	continue;	// If {0,3} is in clones, and nothing <= 3 should be added
		new_clones[i].push_back(i+st);
		findCombinations(r, st+1, new_clones[i], cur_comb, done, n_c_r);
	}

	return 0;
}



int 
bruteForce::binomialCoeffecient(int r, std::vector < std::vector <int> >& cur_comb)
{	
	/*
	* Computes all possible combinations given by n_elem C r
	*/

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

	// n_c_r is the binomial coefficient. We pre-allocate memory to hold these many combinations
	n_c_r = num / den;
	cur_comb.resize(n_c_r);
	std::vector <int> temp;

	for (int i = 0; i < this->n_elem; i++) {
		temp.clear();
		temp.push_back(i);
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
	/* Finds the optimal solution to 0/1 knapsack problem using brute force method */

	int total_combinations = pow(2, this->n_elem);

	int min = 99999999;
	for (int i = 0; i < n_elem; i++) {
		if (this->items[1][i] < min) min = this->items[1][i]; 
	}

	if (this->cc < min) {
		std::cerr << "There is no optimal solution. The knapsack capacity is lower than the smallest item";
		exit(0);
	}
	
	std::vector < std::vector < std::vector <int> > > combinations;
	std::vector < std::vector <int> > costs;
	combinations.resize(this->n_elem);

	// We calculate the combinations for knapsack with all capacities
	for (int i = 0; i < this->n_elem; i++) {
		binomialCoeffecient(i+1, combinations[i]);
		findCosts(combinations[i], costs[i]);
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
