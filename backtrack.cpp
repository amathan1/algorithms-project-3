#include "backtrack.hpp"


inline void
backtrack::clone(std::vector <int> &dst, std::vector <int> &src)
{
	/* Clones src into dst */

	dst.clear();
	for (auto x: src)
		dst.push_back(x);
}


int
backtrack::recursivelyBacktrack(int start, int current_cost, int current_wt, std::vector <int>& optimal_vec, std::vector <int> current, int& optimal_cost)
{
	/*
	* Consider it like a binary space partitioning tree (every knapsack element is now a dimension)
	* Not promising? Prune (Backtrack)
	* start - start point, optimal_vec - to store intermmediate results
	* current - current vector
	*/

	if (current_wt > this->cc)
		return 0;	

	if (current_cost > optimal_cost) {
		clone(optimal_vec, current);
		optimal_cost = current_cost;
	}
		
	if (start >= this->n_elem)
		return 0;

	// Add the if promising here, else it will automatically return.
	// What the heck does the KWF2() function do? Look up.
	// Just do if (!promising())	return 0;

	std::vector <int> klone;
	clone(klone, current);
	current.push_back(start);

	recursivelyBacktrack(start+1, current_cost+this->items[0][start], current_wt+this->items[1][start], optimal_vec, current, optimal_cost);
	recursivelyBacktrack(start+1, current_cost, current_wt, optimal_vec, klone, optimal_cost);

	return 0;
}


int
backtrack::findOptimalSolution()
{

	int optimal_cost = 0;
	std::vector <int> optimal_vec;
	std::vector <int> temp;

	recursivelyBacktrack(0, 0, 0, optimal_vec, temp, optimal_cost);
	printOut(optimal_vec);

	return 0;
}

int 
backtrack::printOut(std::vector <int> &sol)
{
	/* Print out the results*/

	int weight, profit;
	weight = profit = 0;

	for (auto i: sol) {
		weight += this->items[1][i];
		profit += this->items[0][i];
	}

	std::cout << "Total Profit : " << profit << "\tTotal Weight : " << weight << "\nSelected Items : ";
	for (auto i: sol)	std::cout << i+1 << " ";
	
	return 0;
}





int 
main(int argc, char* argv[])
{

	if (argc != 2) {std::cerr << "[Usage] ./backtrack.out <input_file_name>.csv"; exit(0);}

	backtrack bt(argv[1]);

	bt.findOptimalSolution();

	return 0;	
}
