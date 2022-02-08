#include <IRremote.h>
#include <ir_Lego_PF_BitStreamEncoder.h>

int IRPin=9;
int dT=1500;
unsigned long command;

int inputMotDir1=4;    //depending on the Signal the direction of the motor is controlled/    Input1 Input2  MotDir
int inputMotDir2=5;    //depending on the Signal the direction of the motor is controlled     LOW    HIGH    Forward
                                                                                           //HIGH   LOW     Backward 
int enPinSpeedContrl=5;
int motSpeed;  
int motSpeedOffset=15;
int defmotSpeed=225;

decode_results cmd;    //Structure decode_results for Results returned from the decoder
IRrecv IR(IRPin);      //Instantiate the IRrecv class

void setup() {
  IR.enableIRIn();              // Enable IR reception.
  Serial.begin(9600);
  pinMode(inputMotDir1,OUTPUT);
  pinMode(inputMotDir2,OUTPUT);
  pinMode(enPinSpeedContrl,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //Attempt to decode the recently receive IR signal
  
 while(IR.decode(&cmd)==0){
  
 }
 Serial.println(cmd.value,HEX);
 delay(dT);
 IR.resume();          //Called to re-enable IR reception.
 
  switch(cmd.value)
  {   
    case 0xFFA25D:
          Serial.println("Power");
          //start the Motor with deafult speed and direction
          analogWrite(enPinSpeedContrl,defmotSpeed);
          digitalWrite(inputMotDir1,LOW);
          delay(50);
          digitalWrite(inputMotDir2,HIGH); 
          
          break;
          
    case 0xFF629D:
          Serial.println("Vol Up");
          //Increase the speed of the Motor
            motSpeed=motSpeed+motSpeedOffset;
            analogWrite(enPinSpeedContrl,motSpeed);
            if(motSpeed>255)
            {
              motSpeed=255;
            }
            break;    
          
    case 0xFFA857:
            Serial.println("Vol Down");
          //Decrease the speed of the Motor
            motSpeed=motSpeed-motSpeedOffset;
            analogWrite(enPinSpeedContrl,motSpeed);
            if(motSpeed<0)
            {
              motSpeed=0;
            }
          break;
          
    case 0xFFC23D:
          Serial.println("Forward Play");
          //Change the direction of the motor to forward
          digitalWrite(inputMotDir1,LOW);
          delay(50);
          digitalWrite(inputMotDir2,HIGH); 
          break;
          
    case 0xFF22DD:
          Serial.println("Rewind Play");
          //Change the direction of the motor to Backward 
          digitalWrite(inputMotDir1,HIGH);
          delay(50);
          digitalWrite(inputMotDir2,LOW); 
          break;
    
    case 0xFFE21D:
          Serial.println("Fun/Stop");
          //Stop the Motor
          digitalWrite(inputMotDir1,LOW);
          delay(50);
          digitalWrite(inputMotDir2,LOW); 
          break;
          
    case 0xFFFFFFFF:   
          Serial.println("Repeat value detected...");
          break;
                  
    default:
         Serial.println("Unknown Code..... ERRROR!!!");    
         break; 
  }
}
