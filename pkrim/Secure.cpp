#include "Secure.h"
#include <stdio.h>
#include <Windows.h>
#include <msclr\marshal_cppstd.h>
#include <string>

using namespace System;

Secure* Secure::sInstance= NULL;
Secure::Secure(){
	this->fileContent = "";
	this->buttonName = "ynuzwle rpwloebpsdfb";
	this->cistaMzdaName = "wloe psdf ";
	this->hrubaMzdaName = "cvbk psdf ";
	this->windName = "ynuzwhepwloehrpsdfnpoebfhiezy";
	this->XORKey = 9;
	this->hash = "92be268a694bcb767dd9a4c297a28e58d7dc13e7e59fe644f918b960c9dedfb7";
	this->fileName="blpe`k'mh}";

}

Secure* Secure::getInstance(){
	if(sInstance == NULL){
		sInstance = new Secure();
	}
	return sInstance;
}

bool Secure::readFile(string fileName){
	string tmpLine;
	ifstream file;

	
	
	file.open(fileName);
	if(file.is_open()){
		while (!file.eof()){
			getline(file, tmpLine);
			fileContent += tmpLine;
		}

		file.close();
		if(this->fileContent.length() != 27)
			return false;
		return true;
	}else{
		return false;
		System::Windows::Forms::MessageBox::Show("File not found");
	}

}

bool Secure::MemoryBreakpointDebuggerCheck(){
     unsigned char *pMem = NULL;
     SYSTEM_INFO sysinfo = {0}; 
     DWORD OldProtect = 0;
     void *pAllocation = NULL; // Get the page size for the system 
 
    GetSystemInfo(&sysinfo); // Allocate memory 
 
    pAllocation = VirtualAlloc(NULL, sysinfo.dwPageSize, 
                        MEM_COMMIT | MEM_RESERVE, 
                         PAGE_EXECUTE_READWRITE); 
        
    if (pAllocation == NULL)
        return false; 
    
    // Write a ret to the buffer (opcode 0xc3)
    pMem = (unsigned char*)pAllocation;
    *pMem = 0xc3; 
    
    // Make the page a guard page         
    if (VirtualProtect(pAllocation, sysinfo.dwPageSize, 
                    PAGE_EXECUTE_READWRITE | PAGE_GUARD, 
                    &OldProtect) == 0)
    {
        return false;
    } 
    
    __try
    {
        __asm
        {
            mov eax, pAllocation
            // This is the address we'll return to if we're under a debugger
            push MemBpBeingDebugged
            jmp eax // Exception or execution, which shall it be :D?
        }
    }
    __except(EXCEPTION_EXECUTE_HANDLER)
    {
        // The exception occured and no debugger was detected
        VirtualFree(pAllocation, NULL, MEM_RELEASE);
        return false;
    }     
    
    __asm{MemBpBeingDebugged:}
    VirtualFree(pAllocation, NULL, MEM_RELEASE);
    return true;
}

// CheckHardwareBreakpoints returns the number of hardware 
// breakpoints detected and on failure it returns -1.
int Secure::CheckHardwareBreakpoints(){
    unsigned int NumBps = 0;

    // This structure is key to the function and is the 
    // medium for detection and removal
    CONTEXT ctx;
    ZeroMemory(&ctx, sizeof(CONTEXT)); 
    
    // The CONTEXT structure is an in/out parameter therefore we have
    // to set the flags so Get/SetThreadContext knows what to set or get.
    ctx.ContextFlags = CONTEXT_DEBUG_REGISTERS; 
    
    // Get a handle to our thread
    HANDLE hThread = GetCurrentThread();

    // Get the registers
    if(GetThreadContext(hThread, &ctx) == 0)
        return -1;

    // Now we can check for hardware breakpoints, its not 
    // necessary to check Dr6 and Dr7, however feel free to
    if(ctx.Dr0 != 0)
        ++NumBps; 
    if(ctx.Dr1 != 0)
           ++NumBps; 
    if(ctx.Dr2 != 0)
           ++NumBps; 
    if(ctx.Dr3 != 0)
        ++NumBps;
        
    return NumBps;
}

int Secure::getXORKey(){
	return this->XORKey;	
}

string Secure::getFilename(){
	string corrected = this->fileName;

	for(string::size_type i = 0; i < corrected.size(); ++i){
		corrected[i] = corrected[i]^this->getXORKey();
	}

	return corrected;
}

int Secure::indexOf(string arr, char c){
	for(int i = 0; i < arr.length(); i++){
		if(arr[i] == c)
			return i;
	}

	return -1;

}

int Secure::indexOf(char* arr, char c){
	for(int i = 0; i < strlen(arr); i++){
		if(arr[i] == c)
			return i;
	}

	return -1;

}

bool Secure::checkFileKey(){
	string fileContentHash = sha256(this->fileContent);

	if(fileContentHash == this->hash)
		return true;
	else
		false;
}

string Secure::encrypt(string msg, string key){
	char tsa[27] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',' '};
	if(key.length() != 27)
		return NULL;
	string encRet = "";
	for(int i = 0; i < msg.length(); i++){
		int tmpI = this->indexOf(tsa, msg[i]);
		encRet += key[tmpI];
	}

	return encRet;
}

string Secure::decrypt(string msg,string key){

	char tsa[27] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',' '};
	if(key.length() != 27)
		return NULL;
	string encRet = "";
	for(int i = 0; i < msg.length(); i++){
		int tmpI = this->indexOf(key, msg[i]);
		encRet += tsa[tmpI];
	}

	encRet[0] = toupper(encRet[0]);
	return encRet;
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

