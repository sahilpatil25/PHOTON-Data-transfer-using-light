#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 8, 9, 10, 11, 12); 
int value=0,printCount=0;
int cx=0,cy=0,s=0;
String val="";
const int buttonPin = 2;
int buttonState = 0;
unsigned long time;
String temp="";
void setup() 
{
  pinMode(buttonPin, INPUT);
  lcd.begin(16, 2);
  Serial.begin(1000000);
}

void loop() {
  
  buttonState=digitalRead(buttonPin);
  if(buttonState==HIGH)
  {
    lcd.clear(); 
  }
  time=micros();
  while(analogRead(A0) < 800)
  {
     
  }
  time=micros()-time;
  if(time>220)
  {
     Serial.println(time);
  }
  if(Serial.available())
  {
    s=0;
    cx=0;
    printCount=0;
    temp=Serial.readString();
    while(s<temp.length())
    {
      lcd.setCursor(cx,cy);
      lcd.print(temp.charAt(s));
      printCount++;
      cx++;
      if(printCount%16==0&&printCount%32!=0)
      {
        cx=0;
        cy=1;
      }
      s++;
    }
  }
}
