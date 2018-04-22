
#include "readCsv.hpp"




class 
backtrack : public readCsv
{

public:
	
	backtrack(std::string fileName) {readFile(fileName);}	// From now, we assume we have the whole data

	int findOptimalSolution();

	int recursivelyBacktrack(int, int, int, std::vector <int>&, std::vector <int>, int&);

	inline void clone(std::vector <int>&, std::vector <int>&);

	int printOut(std::vector <int>&);

};
