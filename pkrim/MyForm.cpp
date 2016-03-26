#include "MyForm.h"
#include "Secure.h"
#include <fstream>
#include <string>
#include <iostream>
#include <msclr\marshal_cppstd.h>
#include <sstream>
#include <windows.h>


using namespace System;
using namespace System ::Windows::Forms;
using namespace std;

[STAThread]
void main(array<String^>^ arg) {
		
	Secure *secure = Secure::getInstance();


	//if(IsDebuggerPresent()){
	//	exit(0);
	//}
	DWORD Counter = GetTickCount();

	if(secure->MemoryBreakpointDebuggerCheck()){
		exit(0);
	}

	if( secure->CheckHardwareBreakpoints() > 0){
		exit(0);
	}

	if(!secure->readFile(secure->getFilename())){
		exit(0);
	}

	if(!secure->checkFileKey()){
		exit(0);
	}

	Counter = GetTickCount() - Counter;

	if(Counter > 100 || Counter < 5){
		exit(0);
	}
//	ostringstream stream;
//	stream << Counter;
//	MessageBox::Show(gcnew String(stream.str().c_str()));
	
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);


	
	//msclr::interop::marshal_context context;
	//String^ str = gcnew String(secure->getFileContent().c_str());
	//MessageBox::Show(str);
	
	pkrim::MyForm form;
	Application::Run(%form);
}

