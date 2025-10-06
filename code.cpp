#include <LiquidCrystal.h>

const int rs = 8, en = 9, d4 = 10, d5 = 11, d6 = 12, d7 = 13;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int tr1=2;
int ec1=3;

int tr2=4;
int ec2=5;

int tr3=6;
int ec3=7;

int md=0;

int m1=A0;
int m2=A1;
int m3=A2;
int m4=A3;

int buz=A5;
int dst1,dst2,dst3;
int rly=A4;
int dis1()
{
  digitalWrite(tr1,1);
  delayMicroseconds(10);
  digitalWrite(tr1,0);
  delayMicroseconds(2);
  int dst1=pulseIn(ec1,1)/58.2;
  return dst1;
}

int dis2()
{
  digitalWrite(tr2,1);
  delayMicroseconds(10);
  digitalWrite(tr2,0);
  delayMicroseconds(2);
  int dst2=pulseIn(ec2,1)/58.2;
  return dst2;
}

int dis3()
{
  digitalWrite(tr3,1);
  delayMicroseconds(10);
  digitalWrite(tr3,0);
  delayMicroseconds(2);
  int dst3=pulseIn(ec3,1)/58.2;
  return dst3;
}




void setup() {
  Serial.begin(9600); 
 lcd.begin(16, 2);
 
  lcd.print("   WELCOME");
  pinMode(rly,OUTPUT);
  pinMode(m1,OUTPUT);
  pinMode(m2,OUTPUT);
  pinMode(m3,OUTPUT);
  pinMode(m4,OUTPUT);
 
  digitalWrite(m1,0);
  digitalWrite(m2,0);
  digitalWrite(m3,0);
  digitalWrite(m4,0);

  pinMode(tr1,OUTPUT);
  pinMode(ec1,INPUT);

  pinMode(tr2,OUTPUT);
  pinMode(ec2,INPUT);

   pinMode(tr3,OUTPUT);
  pinMode(ec3,INPUT);
 pinMode(buz,OUTPUT);
  digitalWrite(rly,0); 
   digitalWrite(buz,0); 
  delay(2000);

}

void loop() {


if(Serial.available())
{
  int x=Serial.read();
  if(x=='1')
  {
    md=1;
       digitalWrite(rly,0);
        delay(100);
        lcd.clear();
        lcd.print("MANUAL-");
  }
  if(x=='2')
  {
            lcd.clear();
        lcd.print("AUTO-");
       digitalWrite(rly,1);
        delay(100);
    md=0;
  }
  if(md==1)
  {
    if(x=='3')
    {
              lcd.clear();
        lcd.print("MANUAL-FRONT");
  digitalWrite(m1,1);
  digitalWrite(m2,0);
  digitalWrite(m3,1);
  digitalWrite(m4,0);
    }

     if(x=='4')
    {
              lcd.clear();
        lcd.print("MANUAL-BACK");
        digitalWrite(m1,0);
  digitalWrite(m2,1);
  digitalWrite(m3,0);
  digitalWrite(m4,1);
    }

     if(x=='5')
    {
              lcd.clear();
        lcd.print("MANUAL-RIGHT");
        digitalWrite(m1,1);
  digitalWrite(m2,0);
  digitalWrite(m3,0);
  digitalWrite(m4,1);
    }

     if(x=='6')
    {
              lcd.clear();
        lcd.print("MANUAL-LEFT ");
        digitalWrite(m1,0);
  digitalWrite(m2,1);
  digitalWrite(m3,1);
  digitalWrite(m4,0);
    }

     if(x=='7')
    {
              lcd.clear();
        lcd.print("MANUAL-STOP");
        digitalWrite(m1,0);
  digitalWrite(m2,0);
  digitalWrite(m3,0);
  digitalWrite(m4,0);
    }

        if(x=='8')
    {
              lcd.clear();
        lcd.print("MANUAL-PUMP-ON");
        digitalWrite(rly,1);
        delay(100);
     
    }

     if(x=='9')
    {
              lcd.clear();
        lcd.print("MANUAL-PUMP-OFF");
             digitalWrite(rly,0);
        delay(100);
    }
  }
}
if(md==0)
{
 dst1=dis1();
 dst2=dis2();
 dst3=dis3();
 Serial.println("FRONT:"+String(dst2));

if(dst2<20)
 {
         lcd.clear();
        lcd.print("AUTO-F-OBS");
  digitalWrite(m1,0);
  digitalWrite(m2,0);
  digitalWrite(m3,0);
  digitalWrite(m4,0);
  delay(1500);
  dst1=dis1();
  if(dst1>20)
  {
  digitalWrite(m1,1);
  digitalWrite(m2,0);
  digitalWrite(m3,0);
  digitalWrite(m4,1);
  delay(1000);    
  }
  else
  {
lcd.clear();
        lcd.print("AUTO-FR-OBS");
  dst3=dis3();
  if(dst3>20)
  {
  digitalWrite(m1,0);
  digitalWrite(m2,1);
  digitalWrite(m3,1);
  digitalWrite(m4,0);
   delay(1000);
  
  }

  else
  {
  lcd.clear();
        lcd.print("AUTO-FRL-OBS");
    
  digitalWrite(m1,0);
  digitalWrite(m2,0);
  digitalWrite(m3,0);
  digitalWrite(m4,0); 
  digitalWrite(rly,0);
  delay(3000);
   digitalWrite(buz,1);
  while(1);
  }
    
  }
 
  
  }
  else
  {
    lcd.clear();
        lcd.print("AUTO-");
  digitalWrite(m1,1);
  digitalWrite(m2,0);
  digitalWrite(m3,1);
  digitalWrite(m4,0);
  }
  delay(10);
}

 }
