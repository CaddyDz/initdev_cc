#include <iostream>
#include <fstream>
#include <string>
#include <sys/types.h>
#include <sys/stat.h>

using namespace std;

int main(int argc, char *argv[]) {

	// Define strings
	string current_exec_name = argv[0]; // Name of the current exec program
	string first_arg;
	if(argv[1] != NULL) {
		string first_arg = argv[1];
	}
	string home_dir = "~/";
	if(argv[1] == NULL) {
		cout << "Expected arguments, please check the help : " + current_exec_name + " –help" << '\n';
		return 1;
	} else if (first_arg == "-help") {
		cout << "Name: " + current_exec_name << endl;
		cout << "Description: Create a new preconfigured project initialized with templates to get started faster." << "\n";
		cout << "Syntax: " + current_exec_name + " name_of_project" << "\n";
		cout << "args: " << "\n";
		cout << "name_of_project: (Any valid alpha_dash string literal is accepted)" << " the name of the directory and project to be created." << "\n";
		cout << "-help: " << "Shows this help menu and instructions and then exit." << "\n";
		cout << "--Py: " << "Creates a project with preconfigurations tailored for Python projects." << "\n";
		cout << "--C++: " << "Creates a project with preconfigurations tailored for C++ projects." << "\n";
		cout << "--C: " << "Creates a project with preconfigurations tailored for C projects." << "\n";
		cout << "--Latex: " << "Creates a project with preconfigurations tailored for Latex documents projects." << "\n";
		cout << "--BEAMER: " << "Creates a project with preconfigurations tailored for Beamer projects." << "\n";
		cout << "Author: " << "Benguergoura Soumeya (bsoumeya)" << endl;
		return 0;
	}
	
	string sPath = argv[1];
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
		// Create empty MakeFile
		ofstream makefile(sPath + "/MakeFile", ios::binary);
	#endif
	if (nError != 0) {
		cout << "Could not make project directory, make sure the name is correct" << endl;
	}
	
	// Suppress warnings
	(void)argc;
	(void)argv;
	return 0;
}
