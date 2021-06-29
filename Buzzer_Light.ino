
#include <SoftwareSerial.h>
const int buzzerPin = 12;
const int flamePin = 11;
const int LEDPin = 13;
int Flame = HIGH;
SoftwareSerial mySerial(9, 10);

int sms_count=0,Fire_Set;

void setup() 
{
  pinMode(buzzerPin, OUTPUT);
  pinMode(flamePin, INPUT);
  pinMode(LEDPin, OUTPUT);
  mySerial.begin(9600); 
  Serial.begin(9600);
}

void loop() 
{
  Flame = digitalRead(flamePin);
  if (Flame== LOW)
  {
    Serial.println("Agun Lagse vai!!!");
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(LEDPin, HIGH);
  }
  else
  {
    Serial.println("No worries");
    digitalWrite(buzzerPin, LOW);
    digitalWrite(LEDPin, LOW);
  }
}



void SetAlert()
{
while(sms_count<3) //Number of SMS Alerts to be sent
{  
SendTextMessage(); // Function to send AT Commands to GSM module
}
Fire_Set=1; 

}

void SendTextMessage()
{
  mySerial.println("AT+CMGF=1");    //To send SMS in Text Mode
  delay(2000);
  mySerial.println("AT+CMGS=\"+8801769924911\"\r"); // change to the phone number you using 
  delay(2000);
  mySerial.println("Fire in NEW ROOM!");//the content of the message
  delay(200);
  mySerial.println((char)26);//the stopping character
  delay(5000);
   mySerial.println("AT+CMGS=\"++8801769924911\"\r"); // change to the phone number you using 
  delay(2000);
  mySerial.println("Fire in NEW ROOM!");//the content of the message
  delay(200);
  mySerial.println((char)26);//the message stopping character
  delay(5000);
  sms_count++;
}
