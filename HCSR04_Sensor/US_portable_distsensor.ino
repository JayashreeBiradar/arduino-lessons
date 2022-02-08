#include <LiquidCrystal.h>
int trigPin=4;
int echoPin=5;
float pingTraveltime;
float pingTraveldistance;
float targetDistance;
int rs=7;
int es=8;
int d4=9;
int d5=10;
int d6=11;
int d7=12;
int dT=5000;

int buttonPin=A0;
int buttonState;
int butnWait=250;

LiquidCrystal lcd(rs,es,d4,d5,d6,d7);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.begin(16,2);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(buttonPin,INPUT);
  digitalWrite(buttonPin,HIGH);
 }
 
void loop() {

   lcd.setCursor(0,0);
   lcd.print("Place a Target..");
   lcd.setCursor(0,1);
   lcd.print("Press to Measure..");
   buttonState=digitalRead(buttonPin);
   while(buttonState==1)
   {
      buttonState=digitalRead(buttonPin);
   }
   lcd.clear();
   digitalWrite(trigPin,LOW);
   digitalWrite(trigPin,HIGH);
   digitalWrite(trigPin,LOW);
   pingTraveltime=pulseIn(echoPin,HIGH);
   pingTraveldistance=(pingTraveltime*765.*5860.*12.)/(3600UL*1000000UL);
   targetDistance=pingTraveldistance/2;
   lcd.setCursor(0,0);
   lcd.print("Ping Dist: ");
   lcd.print(pingTraveldistance);
   lcd.setCursor(0,1);
   lcd.print("Target Dist:");
   lcd.print(targetDistance);
   delay(dT);
  }
