/*This file is what the .cpp file looks for when it runs*/

#ifndef PadComLib_h
#define PadComLib_h

#include "Arduino.h"
void maincom(String custommsg, bool launchperm, int pyro, String mode);
void padStatus(String pstatus);
void initialize(bool start);


#endif