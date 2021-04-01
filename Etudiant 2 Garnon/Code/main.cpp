#include "RS232.h"
#include <stdio.h>

int main(int argc, const char * argv[]){
	PortiqueRFID = new RS232();
	int COMx;
	
	//ICI LE CODE IHM LAISSANT L'UTILISATEUR ENTRER UN NUMERO DE PORT (COMx)
	
	if(PortiqueRFID->ouvrirPort(COMx) == true){
		if(PortiqueRFID->detectPortique() == true){
			/*
			if(BOUTON FERMER PORT EST PRESSE){
				PortiqueRFID->closePort();
			}
			*/
		}
	}
	
	return 0;
}
