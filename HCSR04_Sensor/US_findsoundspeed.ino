int trigPin=13;       //Trigger I/O pin connected to ardunio pin 13
int echoPin=11;       //Echo I/O pin connected to ardunio pin 11
float pingTime;       
float objDist=5.5;     // object distance in inches 
float speedOfSound;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2000);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);

  pingTime=pulseIn(echoPin,HIGH);
  speedOfSound = 2*objDist/pingTime;      //Speed measured in inches/microseconds
  speedOfSound=speedOfSound/63360*1000000*3600;   //Speed measured in miles/hr
  Serial.print("Speed of the sound is: ");
  Serial.print(speedOfSound);
  Serial.println("miles/hr ");
  delay(3000);
}
