#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Secure{
public:
	Secure static *getInstance(); 
	bool readFile(string fileName);
	string getFileContent();
	string getHrubaMzdaName();
	string getCistaMzdaName();
	string getWindName();
	string getButtonName();
	bool MemoryBreakpointDebuggerCheck();
	int CheckHardwareBreakpoints();
	
private:

	static Secure* sInstance; 
	string fileContent;
	string windName;
	string hrubaMzdaName;
	string cistaMzdaName;
	string buttonName;
	Secure(void);
	~Secure();
};

