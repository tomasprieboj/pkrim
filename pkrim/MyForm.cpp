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
		
	Secure *secure = Secure::getInstance();


	//if(IsDebuggerPresent()){
	//	exit(0);
	//}
	
	if(secure->MemoryBreakpointDebuggerCheck()){
		exit(0);
	}

	if( secure->CheckHardwareBreakpoints() > 0){
		exit(0);
	}


	if(secure->readFile("test.txt")){
		exit(0);
	}


	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);


	
	//msclr::interop::marshal_context context;
	//String^ str = gcnew String(secure->getFileContent().c_str());
	//MessageBox::Show(str);
	
	pkrim::MyForm form;
	Application::Run(%form);
}

