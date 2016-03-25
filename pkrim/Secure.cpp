#include "Secure.h"

Secure* Secure::sInstance= NULL;
Secure::Secure(){
	this->fileContent = "";
	this->buttonName = "sifButton";
	this->cistaMzdaName = "sifCistaMzda";
	this->hrubaMzdaName = "sifHrumaMzda";
	this->windName = "sifMenoOkna";
}

Secure* Secure::getInstance(){
	if(sInstance == NULL){
		sInstance = new Secure();
	}
	return sInstance;
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

string Secure::getButtonName(){
	return this->buttonName;
}

string Secure::getCistaMzdaName(){
	return this->cistaMzdaName;
}

string Secure::getHrubaMzdaName(){
	return this->hrubaMzdaName;
}

string Secure::getWindName(){
	return this->windName;
}

