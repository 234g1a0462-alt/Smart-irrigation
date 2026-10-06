#include <LiquidCrystal.h>

int sensor = A0;
int motor = 13;
int ledRed = 12;
int ledGreen = 11;

LiquidCrystal lcd(2,3,4,5,6,7);

void setup()
{
  Serial.begin(9600);
  lcd.begin(16, 2);
  
  lcd.setCursor(5,0);
  lcd.print("Smart ");
  lcd.setCursor(0,1);
  lcd.print("IrrigationSystem");
  
  pinMode(motor, OUTPUT);
  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  delay(1500);
  
  lcd.clear();
  lcd.print("Moisture = ");
  lcd.setCursor(0,1);
  lcd.print("Water Pump = ");
}

void loop()
{
    int value = analogRead(sensor);
    float moisture = ((value / 539.0) * 100);
    lcd.setCursor(11,0);
    lcd.print(moisture);
    
    if(moisture <= 45)
    {
        digitalWrite(motor, HIGH);
        digitalWrite(ledRed, HIGH);
        digitalWrite(ledGreen, LOW);
        lcd.setCursor(13,1);
        lcd.print("ON ");
    }
    else
    {
        digitalWrite(motor, LOW);
        digitalWrite(ledRed, LOW);
        digitalWrite(ledGreen, HIGH);
        lcd.setCursor(13,1);
        lcd.print("OFF");
    }
    
    delay(1000);
}