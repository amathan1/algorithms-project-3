/* All knapsack methods get data from same format*/
#include <cstdlib>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

class 
readCsv{

public:

	int readFile(std::string fileName);
	int buildEnv();

protected:
	
	std::vector <std::string> wholeCsv;	
	std::vector <std::vector <int> > items;	// Items are stored as {{set_of_item_values}, {set_of_item_weights}}
	int cc, n_elem;

};


int 
readCsv::readFile(std::string fileName)
{
	/*
	* Read from file
	*/

	std::string line;
	std::ifstream matrixFile;
	matrixFile.open(fileName.c_str());
	if (!matrixFile) {std::cerr << "[Error]: Unable to read file"; exit(1);}
	
	while (!matrixFile.eof())
	{
		getline(matrixFile, line);
		this->wholeCsv.push_back(line);
	}

	// When you put huffman here, just have a condition here and return by calling that function

	return buildEnv();
}


int 
readCsv::buildEnv()
{
	/*
	* Builds the whole knapsack environment
	*/

	items.resize(2);
	this->n_elem = atoi(this->wholeCsv[0].c_str());
	bool comma = false;
	this->cc = atoi(this->wholeCsv[1].c_str());
	std::string current = "";
	std::string cur = "";
	int w_idx;

	for (int i = 0; i < 2; i++) {
		w_idx = i+2;
		for (int k = 0; k < wholeCsv[w_idx].size(); k++)
		{	
			cur = this->wholeCsv[w_idx][k];
			if (cur == " ") {
				continue;
			} else if (cur == ",") {
				this->items[i].push_back(atoi(current.c_str()));
				current = "";
				} else {
					current += cur;
				  }
		}
		this->items[i].push_back(atoi(current.c_str()));
		current = "";
	}

	wholeCsv.clear();

	return 0;
}
