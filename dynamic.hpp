
#include "readCsv.hpp"
#include <random>
#include <map>


class
Dynamic : public readCsv
{

public:
	Dynamic(std::string fileName) {readFile(fileName);}	// From now, we assume we have the whole data

	int initializeMatrix();

	int findOptimalSolution();

	int printOptimalSolution();

	inline int max(int, int);

	int printBoard();

	int printResults();	

private:
	int** board;
	std::vector <int> map;
	int max_wt, min_wt;
	std::map<int, int> wt_map;

};

