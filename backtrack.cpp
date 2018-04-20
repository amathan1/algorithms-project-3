#include "backtrack.hpp"









int 
main(int argc, char* argv[])
{

	if (argc != 2) {std::cerr << "[Usage] ./backtrack.out <input_file_name>.csv"; exit(0);}

	backtrack bt(argv[1]);

	return 0;	
}
