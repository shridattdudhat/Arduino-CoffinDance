#include "notes.h"
#include "CoffinDance.h"
int buzzerPin = 9;
int buzzPin = 13;
int looptune = 5;
unsigned long previousMillis = 0;
bool ledState = LOW;

void setup()
{
  looptune = looptune * 72;
  pinMode(buzzPin, OUTPUT);
  delay(3000);
  digitalWrite(buzzPin, HIGH);
  delay(500);
}

void loop()
{
  for (int i = 0; i < looptune; i++)
  {
    blinkMe(); //For the indication
    int noteDuration = 750 / 4;
    tone(buzzerPin, CoffinDance[i % 72], noteDuration);
    int delayTime = noteDuration * 1.30;
    delay(delayTime);
  }
}

void blinkMe()
{
  if (millis() - previousMillis >= 200)
  {
    previousMillis = millis();

    if (ledState == LOW)
    {
      ledState = HIGH;
    }
    else
    {
      ledState = LOW;
    }
    digitalWrite(buzzPin, ledState);
  }

}
