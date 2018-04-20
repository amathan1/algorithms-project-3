#include "dynamic.hpp"









int 
main(int argc, char* argv[])
{

	if (argc != 2) {std::cerr << "[Usage] ./dynamic.out <input_file_name>.csv"; exit(0);}

	Dynamic dyn(argv[1]);

	return 0;	
}
