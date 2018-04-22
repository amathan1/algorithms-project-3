
#include "readCsv.hpp"





class 
Huffman : public readCsv
{

public:

	Huffman(std::string fileName) { readFile(fileName, true); }

	int quick_sort(int, int);

	int partition(int, int);

	int encode();


private:

	std::vector <int> args;


};