
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

	inline int formula(int, int);

	int printOptimalSolution();

	int quicksort(int, int, std::vector<int>&);

	int partition(int, int, std::vector<int>&);



private:
	int** board;
	std::vector <int> map;
	int max_wt, min_wt;
	std::map wt_map;

}



int 
Dynamic::partition(int low, int high)
{
	/* Helper for quicksort */
	int pivot, i, j, temp, temp2, temp3;
	i = low - 1;
	pivot = rand() % high;

	while (pivot < low)
		pivot = rand() % high;


	// For the elements
	temp = this->items[1][pivot];
	this->items[1][pivot] = this->items[1][high - 1];
	this->items[1][high-1] = temp;

	// For indices
	temp2 = this->map[pivot];
	this->map[pivot] = this->map[high-1];
	this->map[high-1] = temp2;

	// For costs
	temp3 = this->items[0][pivot];
	this->items[0][pivot] = this->items[0][high-1];
	this->items[0][high-1] = temp3;


	pivot = high -1;

	for (j = low; j < high - 1; ++j)
	{
		if (this->items[1][j] < this->items[1][pivot]){
			i++;
			temp = this->items[1][i];
			this->items[1][i] = this->items[1][j];
			this->items[1][j] = temp;

			temp2 = this->map[i];
			this->map[i] = this->map[j];
			this->map[j] = temp2;
		}
	}

	i++;
	
	// Move pivot back to its place
	temp = arr[i];
	arr[i] = arr[pivot];
	arr[pivot] = temp;
	
	//For indices
	temp2 = this->map[i];
	this->map[i] = this->map[pivot];
	this->map[pivot] = temp2;

	return i;
}



int 
Dynamic::quick_sort(int low, int high)
{
	/* Quicksort: Pass by reference vector of integers and by value 0 and vector.size() */

	int pivot;
	if (high - low < 2)	return 0;
	pivot = partition(low, high);

	quick_sort(low, pivot);
	quick_sort(pivot, high);

	return 0;
}
