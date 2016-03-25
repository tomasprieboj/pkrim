#include "Secure.h"
#include <stdio.h>
#include <Windows.h>

Secure* Secure::sInstance= NULL;
Secure::Secure(){
	this->fileContent = "";
	this->buttonName = "sifButton";
	this->cistaMzdaName = "sifCistaMzda";
	this->hrubaMzdaName = "sifHrumaMzda";
	this->windName = "sifMenoOkna";
	this->XORKey = 9;
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
		return true;
	}else{
		return false;
		System::Windows::Forms::MessageBox::Show("File not found");
	}

}

bool Secure::MemoryBreakpointDebuggerCheck()
{
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
int Secure::CheckHardwareBreakpoints()
{
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

string Secure::encrypt(string msg, string key){
    // Make sure the key is at least as long as the message
    string tmp(key);
    while (key.size() < msg.size())
        key += tmp;
    
    // And now for the encryption part
    for (string::size_type i = 0; i < msg.size(); ++i)
        msg[i] ^= key[i];
    return msg;
}
string Secure::decrypt(string msg,string key){
    return this->encrypt(msg, key); // lol
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

