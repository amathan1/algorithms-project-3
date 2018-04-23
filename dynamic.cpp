#include "dynamic.hpp"


int 
Dynamic::printBoard()
{
	for (int i = 0; i <= this->n_elem; i++) {
		for (int j = 0; j <= this->cc+1; j++) {
			std::cout << this->board[i][j] << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}



int 
Dynamic::initializeMatrix()
{
	board = (int**) malloc((this->n_elem+1) * sizeof(int*));
	for (int i = 0; i < n_elem+1; i++) {
		board[i] = (int*) calloc(sizeof(int), this->cc+1);
	}

	for (int i = 0; i < n_elem; i++) {
		this->board[i+1][this->items[1][i]] = this->items[0][i];
	}

	return 0;
}


inline int
Dynamic::max(int a, int b)
{
	if (a > b) {
		return a;
	} else {
		return b;
	}
}


int 
Dynamic::findOptimalSolution()
{
	/* Builds the matrix structure for finding the optimal solution */
	
	int cur;

	for (int i = 1; i <= this->n_elem; i++) {
		for (int j = 1; j <= this->cc+1; j++) {
			if (this->items[1][i-1] > j) {
				this->board[i][j] = this->board[i][j-1];
				if (this->board[i][j] < this->board[i-1][j]) this->board[i][j] = this->board[i-1][j];
			} else {
				this->board[i][j] = max(this->board[i-1][j], this->board[i-1][j-this->items[1][i-1]] + this->items[0][i-1]);
			  }
		}
	}
	printBoard();
}


int
Dynamic::printOut()
{
	/* Print out the results */

	return 0;
}


int 
main(int argc, char* argv[])
{

	if (argc != 2) {std::cerr << "[Usage] ./dynamic.out <input_file_name>.csv"; exit(0);}

	Dynamic dyn(argv[1]);

	dyn.initializeMatrix();

	dyn.findOptimalSolution();

	return 0;	
}
