
int triggerPin=12;
int echoPin=11;
float pingTraveltime;
float pingTraveldistance;
float targetDistance;
int waitT=1000;

void setup() {
  Serial.begin(9600);
  pinMode(triggerPin,OUTPUT);
  pinMode(echoPin,INPUT);

}

void loop() {
  digitalWrite(triggerPin,LOW);
  //delayMicroseconds(10);
  digitalWrite(triggerPin,HIGH);
 // delayMicroseconds(10);
  digitalWrite(triggerPin,LOW);
  pingTraveltime=pulseIn(echoPin,HIGH);
  //Serial.print("Ping Travel Time:");
  //Serial.print(pingTraveltime);
  //Serial.print("micro Seconds");
  pingTraveldistance=(pingTraveltime*765.*5820.*12.)/(3600UL*1000000UL);
  targetDistance=pingTraveldistance/2;
  /* Commenting to see on serial plotter
  Serial.print("PingTravel Distance: ");
  Serial.print(pingTraveldistance);
  Serial.print("inches");
  targetDistance=pingTraveldistance/2;
  Serial.print("Target Distance is: ");
  Serial.print(targetDistance);
  Serial.println("inches");
  delay(waitT);
  */
  //Serial plotter
  Serial.print(0);
  Serial.print(",");
  Serial.print(targetDistance);
  Serial.print(",");
  Serial.println(10);
}
