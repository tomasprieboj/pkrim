#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Secure{
public:
	Secure(void);
	~Secure();
	void readFile(string fileName);
	string getFileContent();
private:
	string fileContent;
};

