#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Secure{
public:
	Secure static *getInstance(); 
	void readFile(string fileName);
	string getFileContent();
	string getHrubaMzdaName();
	string getCistaMzdaName();
	string getWindName();
	string getButtonName();
	
	
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

