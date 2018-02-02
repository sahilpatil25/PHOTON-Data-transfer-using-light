int ledPin = 13;
String input,out;
int num;
void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if(Serial.available())
  {
    input = Serial.readString();
    num= input.toInt();
    out=intToBin(num);
  }
  
  
}
String intToBin(int num)
{
  long binary=0,remainder,base=1;;
      while (num > 0)

    {

        remainder = num % 2;

        binary = binary + remainder * base;

        num = num / 2;

        base = base * 10;

    }
    
    String output = String(binary);
    sendToLED(output);
    Serial.println(output);
    return output;
}
int sendToLED(String out)
{
    int i=0;
    while(i<out.length())
    {
      if(out.charAt(i)=='0')
      {
        digitalWrite(ledPin,HIGH);
        delay(200);
        digitalWrite(ledPin,LOW);
        delay(800);
      }
      if(out.charAt(i)=='1')
      {
        digitalWrite(ledPin,HIGH);
        delay(700);
        digitalWrite(ledPin,LOW);
        delay(300);
      }
      i++;
    }
    return 0;
}

