#include "Secure.h"


Secure::Secure(void){
	this->fileContent = "";
}

Secure::~Secure(){
}

void Secure::readFile(string fileName){
	string tmpLine;
	ifstream file;
	
	file.open(fileName);
	if(file.is_open()){
		while (!file.eof()){
			getline(file, tmpLine);
			fileContent += tmpLine;
		}

		file.close();
	}else{
		System::Windows::Forms::MessageBox::Show("File not found");
	}

}

string Secure::getFileContent(){
	return this->fileContent;
}


