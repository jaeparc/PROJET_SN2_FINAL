#include "RS232.h"



bool RS232::openPort(int COMx){

	this->hcom = CreateFileA("COM"+COMx, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_FLAG_NO_BUFFERING, NULL);

	if (hcom == INVALID_HANDLE_VALUE) {
		return false;
	}

	GetCommState(this->hcom, &this->dcb);

	this->dcb.BaudRate = CBR_9600;
	this->dcb.ByteSize = 8;
	this->dcb.Parity = NOPARITY;
	this->dcb.StopBits = ONESTOPBIT;

	SetCommState(this->hcom, &this->dcb);


	COMMTIMEOUTS comm;
	comm.ReadIntervalTimeout = MAXDWORD;
	comm.ReadTotalTimeoutMultiplier = 0;
	comm.ReadTotalTimeoutConstant = 0;
	comm.WriteTotalTimeoutMultiplier = 0;
	comm.WriteTotalTimeoutConstant = 0;

	SetCommTimeouts(this->hcom, &comm);

	return true;

}
bool RS232::detectPortique() {

	unsigned long sendLenght;
	char* trame = "TRAME DETECTION A DEFINIR";
	if (!WriteFile(this->hcom, trame, strlen(trame), &sendLenght, NULL)) {
		return false;
	}
	return true;
}
void RS232::closePort() {
	CloseHandle(this->hcom);
}
