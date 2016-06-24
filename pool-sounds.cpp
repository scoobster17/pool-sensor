// ------------
// Blink a LED the hard way, using macros found in the Arduino environment...
// Sketch works on both Photon and Uno...
// ------------

#include "Arduino/Arduino.h"

#define LOUDNESS_PIN A0
#define SOUND_PIN D1

// ------------
#ifdef SPARK_CORE // Particle...

int LED_PIN = D7; // This one is the little blue LED on your board.
		  // On the Photon it is next to D7, and on the Core it is next to the USB jack.

#else // ... Arduino...

int LED_PIN = 13; // normal LED location on UNO...

#endif
// ------------

void setup()
{
	Serial.begin(9600);

	pinMode(LOUDNESS_PIN, INPUT);
}

void loop()
{
	int result = analogRead(LOUDNESS_PIN);

	if (result > 700)
	{
	    Serial.println(result);
	    tone(SOUND_PIN, 2000, 250);
	    delay(50);
	    noTone(SOUND_PIN);
	}
}
