#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <string.h>

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
	string encrypt(string msg, string key);
	string decrypt(string msg,string key);
	int getXORKey();
	string getFilename();
	
private:

	int indexOf(string arr, char c);
	int indexOf(char* arr, char c);
	static Secure* sInstance; 
	string fileContent;
	string windName;
	string hrubaMzdaName;
	string cistaMzdaName;
	string buttonName;
	int XORKey;
	string fileName;
	Secure(void);
	~Secure();
};

