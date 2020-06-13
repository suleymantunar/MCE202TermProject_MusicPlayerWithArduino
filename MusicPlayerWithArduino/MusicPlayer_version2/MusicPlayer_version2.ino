#include <SD.h> 
#define SDPin 4 
#include <TMRpcm.h> 
#include <SPI.h> 
#include <LiquidCrystal.h>

LiquidCrystal lcd(2, 3 , A4 , A3 , A2, A1);

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
 

 
 tmrpcm.speakerPin = 9; 
 Serial.begin(9600);
 lcd.begin(16, 2);
 lcd.cursor();
 if (!SD.begin(SDPin))
 {
  Serial.println("SD fail");
  lcd.print("SD Fail");
  }
 else{
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
      lcd.clear(); 
      lcd.setCursor(0,0);
      lcd.print("pause/play >|");
      lcd.setCursor(1,1);
      lcd.print("Music");
      lcd.print(temp);
      delay(1000);
      
      
    }
    else if(digitalRead(next)==LOW)
    {
      if(temp<5) 
      temp=temp+1;
      while(digitalRead(next)==LOW);
      lcd.clear(); 
      lcd.setCursor(0,0);
      lcd.print("next >>");
      delay(1000);
      
      song();
    }
    else if(digitalRead(prev)==LOW)
    {
      if(temp>1)
      temp=temp-1;
      while(digitalRead(prev)==LOW);
      lcd.setCursor(0,0);
      lcd.clear(); 
      lcd.print("previous <<");
      delay(1000);
      song();
    }
  }
}

void song (void)
{
  if(temp==1)
  {
    tmrpcm.play("1.wav");
      lcd.clear(); 
    lcd.setCursor(0,0);
     lcd.print("**1. Music**");
  }
  else if(temp==2)
  {
    tmrpcm.play("2.wav");
      lcd.clear(); 
    lcd.setCursor(0,0);
    lcd.print("**2.Music**");
  }
  else if(temp==3)
  {
    tmrpcm.play("3.wav");
    lcd.clear();  
    lcd.setCursor(0,0);
    lcd.print("**3.Music**");
  }
  else if(temp==4)
  {
    tmrpcm.play("4.wav");
    lcd.clear(); 
    lcd.setCursor(0,0);
    lcd.print("**4.Music**"); 
     
  }
}
