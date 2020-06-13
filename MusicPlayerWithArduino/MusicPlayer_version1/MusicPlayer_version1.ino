#include <SD.h> 
#define SDPin 4 
#include <TMRpcm.h> 
#include <SPI.h> 

TMRpcm tmrpcm; 
int temp=2;
int pp=5;
int next=6;
int prev=7;
void setup()
{ 
 pinMode(pp,INPUT_PULLUP);
 pinMode(next,INPUT_PULLUP);
 pinMode(prev,INPUT_PULLUP);
 pinMode (2,OUTPUT);
 pinMode (3,OUTPUT);
 pinMode (8,OUTPUT);
 pinMode (1,OUTPUT);

 
 tmrpcm.speakerPin = 9; 
 Serial.begin(9600);
 if (!SD.begin(SDPin)) 
 {
  Serial.println("SD fail");
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(10, HIGH);}
 else{
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(8, LOW);
  digitalWrite(10, LOW);
  
  return;
 }
 


                     
}


void loop() 
{  
  while(digitalRead(pp)==LOW || digitalRead(next)==LOW || digitalRead(prev)==LOW)
  {
    if(digitalRead(pp)==LOW)
    {
      tmrpcm.pause();
      while(digitalRead(pp)==LOW);
      delay(200);
    }
    else if(digitalRead(next)==LOW)
    {
      if(temp<5)//temp should be lesser than no. of songs 
      temp=temp+1;
      while(digitalRead(next)==LOW);
      delay(200);
      song();
    }
    else if(digitalRead(prev)==LOW)
    {
      if(temp>1)
      temp=temp-1;
      while(digitalRead(prev)==LOW);
      delay(200);
      song();
    }
  }
}

void song (void)
{
  if(temp==1)
  {
    tmrpcm.play("1.wav"); 
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(8, LOW);
    digitalWrite(10, LOW); 
  }
  else if(temp==2)
  {
    tmrpcm.play("2.wav"); 
    digitalWrite(2, LOW); 
    digitalWrite(3, HIGH);
    digitalWrite(8, LOW);
    digitalWrite(10, LOW);
  }
  else if(temp==3)
  {
    tmrpcm.play("3.wav"); 
    digitalWrite(2, LOW); 
    digitalWrite(3, LOW);
    digitalWrite(8, HIGH);
    digitalWrite(10, LOW);
  }
  else if(temp==4)
  {
    tmrpcm.play("4.wav"); 
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(8, LOW);
    digitalWrite(10, HIGH); 
  }
}
