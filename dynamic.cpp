#include "dynamic.hpp"


int 
Dynamic::initializeMatrix()
{

	board = (int**)malloc(this->n_elem * sizeof(int*));
	for (int i = 0; i < n_elem; i++) {
		board[i] = calloc(sizeof(int), this->n_elem);
	}

	max_wt = 0, min_wt = 9999999;

	for (int i = 0; i < n_elem; i++) {
		this->map.push_back(i);
		if (this->items[1][i]>max_wt)	max_wt = this->items[1][i];
		if (this->items[1][i]<min_wt)	min_wt = this->items[1][i];
	}

	// quick_sort(0, this->n_elem);

	for (int i = 0; i < n_elem; i++) {
		// this->wt_map[this->items[1][i]] = i+1;
		this->board[i+1][this->items[1][i]] = this->board[0][i];
	}

	return 0;
}


inline int
Dynamic::formula()
{

	return 0;
}


int 
Dynamic::findOptimalSolution()
{

	int cur;

	for (int i = 1; i <= this->max_wt; i++) {

		for (int j = 1; j <= this->max_wt; j++) {

			if (this->board[i][j] > )

		}

	}
}





int 
main(int argc, char* argv[])
{

	if (argc != 2) {std::cerr << "[Usage] ./dynamic.out <input_file_name>.csv"; exit(0);}

	Dynamic dyn(argv[1]);

	return 0;	
}
