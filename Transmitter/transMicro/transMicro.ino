int ledPin = 8, i=0;
String input,out;
int num;
void setup()
{
  pinMode(ledPin, OUTPUT);
  Serial.begin(250000);
}

void loop() {
  if(Serial.available())
  {
    input = Serial.readString();
    sendToLED(input);
    //Serial.println(input);
    //encodeMsg(input);
    digitalWrite(ledPin,HIGH);
    delayMicroseconds(2500);
    digitalWrite(ledPin,LOW);
    delayMicroseconds(2500);
  }
}

int sendToLED(String out)
{
    int i=0;
    while(i<out.length())
    {
      digitalWrite(ledPin,HIGH);
      if(out.charAt(i)=='1')
      { 
        delayMicroseconds(600);
      }
      else
      {
        delayMicroseconds(300);
      }
      digitalWrite(ledPin,LOW);
      delayMicroseconds(200);
      i++;
    }
    return 0;
}
