// ------------
// Blink a LED the hard way, using macros found in the Arduino environment...
// Sketch works on both Photon and Uno...
// ------------

#include <time.h>
#include "Arduino/Arduino.h"

#define LOUDNESS_PIN A0
#define SOUND_PIN D1

time_t startTime = 0;
long accumulator = 0;
long numSamples = 0;

void setup()
{
	Serial.begin(9600);

	pinMode(LOUDNESS_PIN, INPUT);
	startTime = time(NULL);
}

void loop()
{
    time_t currentTime = time(NULL);

    if (currentTime - startTime > 30)
    {
        /* Calculate and send average. */
        int average = accumulator / numSamples;


        /* Reset globals. */
        accumulator = 0;
        numSamples = 0;
        startTime = currentTime;
    }
    else
    {
        accumulator += analogRead(LOUDNESS_PIN);
        ++numSamples;
        delay(50);
    }
}
