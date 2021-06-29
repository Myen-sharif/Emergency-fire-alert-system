
const int buzzerPin = 12;
const int flamePin = 11;
const int LEDPin = 10;
int Flame = HIGH;

void setup() 
{
  pinMode(buzzerPin, OUTPUT);
  pinMode(flamePin, INPUT);
  pinMode(LEDPin, OUTPUT);
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