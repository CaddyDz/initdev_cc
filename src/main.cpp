#include <iostream>
#include <fstream>
#include <string>
#include <sys/types.h>
#include <sys/stat.h>

using namespace std;

int main(int argc, char *argv[]) {

	// Define strings
	std::string current_exec_name = argv[0]; // Name of the current exec program
	std::string home_dir = "~/";

	if(argv[1] == NULL) {
		cout << "You must enter a directory name" << '\n';
		cout << "Enter " + current_exec_name + " --help for instructions" << endl;
		return 1;
	}
	
	std::string sPath = argv[1];
	cout << sPath << endl;
	mode_t nMode = 0733; // UNIX style permissions
	int nError = 0;
	#if defined(_WIN32)
		nError = _mkdir(sPath.c_str()); // can be used on Windows
	#else 
		nError = mkdir(sPath.c_str(), nMode); // can be used on non-Windows
	#endif
	if (nError != 0) {
		cout << "Could not make project directory, make sure the name is correct" << endl;
	}
	// Suppress warnings
	(void)argc;
	(void)argv;
	return 0;
}
