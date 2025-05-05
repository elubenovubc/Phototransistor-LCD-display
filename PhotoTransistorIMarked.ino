#include <LiquidCrystal.h>

#define PT A0
//PT for PhotoTransistor

LiquidCrystal lcd(2, 4, 5, 6, 7, 8);
//               RS, E, 4, 5, 6, 7

void setup()
{
  pinMode(PT, INPUT);
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.print("Phototransistor!");
  lcd.setCursor(0, 1);
  lcd.print("Light(%): ");
  lcd.setCursor(10, 1);
  //Sets up the lcd to initialize unchangable text.
}

void loop()
{
  int value = analogRead(PT);
  int logVal = log(value - 12);
  //For whatever reason, given phototransistor took a max raw value of 13, so the logarithmic plotting has to account for that.
  logVal = map(logVal, 0, log(1023 - 12), 100, 0);
  //Maps the value along a curve.
  int mapped = constrain(logVal, 0, 100);
  //Constrains the logarithm to 0 - 100 %.
  lcd.setCursor(10, 1);
  lcd.print(logVal);
  delay(200);
  lcd.setCursor(10, 1);
  lcd.print("       ");
  //This last piece just helps me keep the readings clean.
  
}