
#include "huffman.hpp"



int
Huffman::encode()
{
	
	// Fill the indices vector to make reconstruction easier	
	for (int i = 0; i < this->chars.size(); i++) {
		this->args.push_back(i);
	}

	quick_sort(0, this->freqs.size());

	// buildHuffmanTree();

	return 0;
}


int 
buildHuffmanTree()
{
	/* Build the Huffman tree recursively */

	

	

	return 0;
}


int 
Huffman::partition(int low, int high)
{
	/* Helper for quicksort */
	int pivot, i, j, temp2;
	int temp;
	i = low - 1;
	pivot = rand() % high;

	while (pivot < low)
		pivot = rand() % high;


	// For the elements
	temp = this->freqs[pivot];
	this->freqs[pivot] = this->freqs[high - 1];
	this->freqs[high-1] = temp;

	// For indices
	temp2 = this->args[pivot];
	this->args[pivot] = this->args[high-1];
	this->args[high-1] = temp2;
	

	pivot = high -1;

	for (j = low; j < high - 1; ++j)
	{
		if (this->freqs[j] < this->freqs[pivot]){
			i++;
			temp = this->freqs[i];
			this->freqs[i] = this->freqs[j];
			this->freqs[j] = temp;

			temp2 = this->args[i];
			this->args[i] = this->args[j];
			this->args[j] = temp2;
		}
	}

	i++;
	
	// Move pivot back to its place
	temp = this->freqs[i];
	this->freqs[i] = this->freqs[pivot];
	this->freqs[pivot] = temp;
	
	//For indices
	temp2 = this->args[i];
	this->args[i] = this->args[pivot];
	this->args[pivot] = temp2;

	return i;
}



int 
Huffman::quick_sort(int low, int high)
{
	/* Quicksort: Pass by reference vector of integers and by value 0 and vector.size() */

	int pivot;
	if (high - low < 2)	return 0;
	pivot = partition(low, high);

	quick_sort(low, pivot);
	quick_sort(pivot, high);

	return 0;
}




int
main(int argc, char* argv[])
{

	if (argc != 2) {std::cerr << "[Usage] ./huffman.out <input_file_name>.csv"; exit(0);}

	Huffman hm(argv[1]);

	hm.encode();

	return 0;
}