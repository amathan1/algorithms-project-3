

#include "readCsv.hpp"


class 
bruteForce : public readCsv
{

public:

	bruteForce(std::string fileName) {readFile(fileName);}	// From now, we assume we have the whole data

	int findOptimalCombination();

	int printData();	// For debugging purposes

};