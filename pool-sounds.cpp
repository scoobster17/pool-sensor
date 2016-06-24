// ------------
// Blink a LED the hard way, using macros found in the Arduino environment...
// Sketch works on both Photon and Uno...
// ------------

#include <stdio.h>
#include "application.h"

#define LOUDNESS_PIN A0
#define SOUND_PIN D1

int startTime = 0;
long accumulator = 0;
long numSamples = 0;

void setup()
{
	Serial.begin(9600);

	pinMode(LOUDNESS_PIN, INPUT);
	startTime = Time.now();
}

void loop()
{
    int currentTime = Time.now();

    if (currentTime - startTime > 10)
    {
        /* Calculate and send average. */
        int average = accumulator / numSamples;

        char str[15];
        sprintf(str, "%d", average);
        Particle.publish("sound", str, PRIVATE);

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
