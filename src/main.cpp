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
	mode_t nMode = 0733; // UNIX style permissions
	int nError = 0;
	#if defined(_WIN32)
		nError = _mkdir(sPath.c_str()); // can be used on Windows
	#else 
		nError = mkdir(sPath.c_str(), nMode); // can be used on non-Windows
		// C++ by default for now
		// Copy empty main file to the project directory
		ifstream  main_code_source("../sources/main.cpp", ios::binary);
		ofstream  main_code_destination(sPath + "/main.cpp", ios::binary);
		main_code_destination << main_code_source.rdbuf();
		// Copy license file to the project directory
		// GPL3 by default for now
		ifstream license_source("../licenses/gnu-gpl-v3.0.md", ios::binary);
		ofstream license_destination(sPath + "/LICENSE", ios::binary);
		license_destination << license_source.rdbuf();
	#endif
	if (nError != 0) {
		cout << "Could not make project directory, make sure the name is correct" << endl;
	}
	
	// Suppress warnings
	(void)argc;
	(void)argv;
	return 0;
}
