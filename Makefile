all:
	make backtrack bruteForce dynamic huffman

bruteForce:
	g++ -o bruteForce.out bruteForce.cpp

dynamic:
	g++ -o dynamic.out dynamic.cpp

backtrack:
	g++ -o backtrack.out backtrack.cpp

huffman:
	g++ -o huffman.out huffman.cpp

clean:
	rm -f *out

debug_bf:
	gdb ./bruteForce.out

debug_dy:
	gdb ./dynamic.out

debug_bt:
	gdb ./backtrack.out

debug_hf:
	gdb ./huffman.out
