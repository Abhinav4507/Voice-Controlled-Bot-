#include <SoftwareSerial.h>
SoftwareSerial BT (11 ,10);    //TX , RX Respectively for BT
String readdata ;

int LMotor1=3;
int LMotor2=5;
int RMotor1=6;
int RMotor2=9;

void setup() 
{
  BT.begin(9600);
  Serial.begin(9600);
  pinMode(LMotor1,OUTPUT);
  pinMode(LMotor2,OUTPUT);
  pinMode(RMotor1,OUTPUT);
  pinMode(RMotor2,OUTPUT);
}

void loop() {
  while(BT.available())
  {
    delay(10);
    char c = BT.read();
    readdata += c;
  }
  if (readdata.length()>0)
  {
    Serial.println(readdata);
    if (readdata == "forward")
    {
      Serial.println("UP");
      //Forward
      analogWrite(LMotor1,170);
      analogWrite(LMotor2,0);
      analogWrite(RMotor1,170);
      analogWrite(RMotor2,0);
      delay(10);
    }
    else if (readdata=="backward")
    {
      Serial.println("DOWN");
      analogWrite(LMotor1,0);
      analogWrite(LMotor2,170);
      analogWrite(RMotor1,0);
      analogWrite(RMotor2,170);
      delay(10);
    }
    else if (readdata=="stop")
    {
      Serial.println("STOP");
      analogWrite(LMotor1,0);
      analogWrite(LMotor2,0);
      analogWrite(RMotor1,0);
      analogWrite(RMotor2,0);
      delay(10);
    }
     else if (readdata=="left")
    {
      // Left
      analogWrite(LMotor1,0);
      analogWrite(LMotor2,170);
      analogWrite(RMotor1,170);
      analogWrite(RMotor2,0);
      delay(10);
    }
     else if (readdata=="right")
     {
      // Right
      analogWrite(LMotor1,170);
      analogWrite(LMotor2,0);
      analogWrite(RMotor1,0);
      analogWrite(RMotor2,170);
      delay(10);
     }
  }
 readdata="";
}
