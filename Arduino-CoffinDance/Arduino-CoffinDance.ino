#include "notes.h"
#include "CoffinDance.h"
int buzzerPin = 9;
int looptune = 5;

void setup()
{
  looptune = looptune * 72;
  delay(5000);
}

void loop()
{
  for (int i = 0; i < looptune; i++)
  {
    int noteDuration = 750 / 4;
    tone(buzzerPin, CoffinDance[i % 72], noteDuration);
    int delayTime = noteDuration * 1.30;
    delay(delayTime);
  }
}
