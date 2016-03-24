#include "MyForm.h"
#include "Secure.h"
#include <fstream>
#include <string>
#include <iostream>
#include <msclr\marshal_cppstd.h>

using namespace System;
using namespace System ::Windows::Forms;
using namespace std;

[STAThread]
void main(array<String^>^ arg) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	
	Secure *secure = new Secure();
	secure->readFile("test.txt");

	/*
	msclr::interop::marshal_context context;
	String^ str = gcnew String(secure->getFileContent().c_str());
	MessageBox::Show(str);
	*/
	pkrim::MyForm form;
	Application::Run(%form);
}