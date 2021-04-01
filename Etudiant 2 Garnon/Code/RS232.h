#pragma once
#include <windows.h>

class RS232
{
private:
	
	HANDLE hcom;
	DCB dcb;

public:

	bool openPort(int COMx);
	bool detectPortique();
	void closePort();
};

