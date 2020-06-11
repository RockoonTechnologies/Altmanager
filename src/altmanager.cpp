/*PAD COM LIB*/
#include "Arduino.h"
#include "PadComLib.h"

String incomingByte;





void maincom(String custommsg, bool launchperm, int pyro, String mode) {
	incomingByte = Serial.readString();  // reads new data
	if (incomingByte.equals(custommsg) == true) {
		
		Serial.print("Custom Message Recieved");
		//customaction();
		
	    
    } 
	if (incomingByte.equals("launch") == true) {
		if (launchperm == true) {
			if (mode.equals("LOW") == true) {
			   digitalWrite(pyro, LOW);
			   delay(1000);
			   digitalWrite(pyro, HIGH);
			}
			if (mode.equals("HIGH") == true) {
			   digitalWrite(pyro, HIGH);
			   delay(1000);
			   digitalWrite(pyro, LOW);
	        }
	       
		}
	}
	if (incomingByte.equals("pyrotest") == true) {
		if (launchperm == true) {
			if (mode.equals("LOW") == true) {
				digitalWrite(pyro, LOW);
				delay(1000);
				digitalWrite(pyro, HIGH);
			}
			if (mode.equals("HIGH") == true) {
				digitalWrite(pyro, HIGH);
				delay(1000);
				digitalWrite(pyro, LOW);
			}

		}
	}
}



void padStatus(String pstatus) {
	if (pstatus.equals("Idle") == true) {
		Serial.print(pstatus); 
		delay(1000); 
	}
	if (pstatus.equals("Countdown") == true) {
		Serial.print(pstatus);
		delay(1000); 
	}
	if (pstatus.equals("Abort") == true) {
		Serial.print(pstatus);
		delay(1000); 
	}
}

void initialize(bool start) {
	if (start == true) {
		Serial.begin(9600);
		
	}
}