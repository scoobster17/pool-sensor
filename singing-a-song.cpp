// singing-a-song

// ---------------------
// Example 01: Singing a song
// ---------------------
#include "application.h"

// name the pins
#define BUTTONPIN D2
#define BUZZERPIN D1

int melody[] = {1998, 2551, 2551, 2273, 2251, 0, 2024, 1908};
int noteDurations[] = {4,8,8,4,4,4,4,4};

// This routine runs only once upon reset
void setup()
{
  pinMode(BUTTONPIN, INPUT);
}

void loop()
{
  if(digitalRead(BUTTONPIN) == 1) {
    for (int thisNote = 0; thisNote < 8; thisNote++) {
      int noteDuration = 1000/noteDurations[thisNote];
      tone(BUZZERPIN, melody[thisNote], noteDuration);
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      noTone(BUZZERPIN);
    }
  }
}
