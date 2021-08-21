#include<LiquidCrystal.h>
LiquidCrystal lcd (12,11,5,4,3,2);
float hb = A0;             //hb- heartbeat
float temp = A1;           //temp-temperature
float hb1=0,s=0;           // hb1- intital state of heartbeat equal to 0 same temp is also 0
int pb = 7, is=0;        // pb- push button nd is- initial state

void setup(){
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(7,INPUT);
  
  Serial.begin(9600);
  lcd.begin(16,2);

String str = "HEART RATE MONITORING SYSTEM";
lcd.print(str);
Serial.println(str);
delay(500);

for(int i=0; i<str.length(); i++)
{
  lcd.scrollDisplayLeft();
  delay(100);
 }
lcd.clear();

lcd.print("PRESS THE BUTTON TO START");

Serial.println("PRESS THE BUTTON TO START");
delay(1000);
//lcd.clear();
}


void loop(){
  
  is = digitalRead(7);
  
if(is==LOW){

  lcd.clear();
  
  lcd.print("PLACE THE FINGER");
//  delay(1000);
  Serial.println("PLACE THE FINGER");
  delay(500);
  lcd.clear();
  hb1 = analogRead(A0);
  s = analogRead(A1);
//   hb1 = hb1/9;
   s = s* (5.0 / 1023.0*100);
  

lcd.setCursor(0,0);
lcd.print("BODY TEMPERATURE:");
Serial.print("BODY TEMPERATURE:");
lcd.setCursor(0,1);
lcd.print(s);
Serial.println(s);
delay(1500);
lcd.clear();
  
lcd.setCursor(0,0);
lcd.print("HEART RATE:");
Serial.print("HEART RATE:");
lcd.setCursor(0,1);
lcd.print(hb1);
Serial.println(hb1);
delay(1500);
lcd.clear();



if(hb1>=72 && hb1<=85){
String str1 = "YOU ARE HEALTHLY";
lcd.print(str1);
Serial.println(str1);
delay(1000);

for(int i=0; i<str1.length(); i++)
{
  lcd.scrollDisplayLeft();
  delay(150);
 }
  lcd.clear();
}

if(hb1>=86 && hb1<100){
String str2 = "PRACTISE MEDITATION";
lcd.print(str2);
Serial.println(str2);
delay(1000);

for(int i=0; i<str2.length(); i++)
{
  lcd.scrollDisplayLeft();
  delay(150);
   }
lcd.clear();
}

if(hb1>=60 && hb1<=71){
String str3 = "SLOW HEART RATE DETECTED";
lcd.print(str3);
Serial.println(str3);
delay(1000);

for(int i=0; i<str3.length(); i++)
{
  lcd.scrollDisplayLeft();
  delay(150);
   }
lcd.clear();
 }

if(hb1>100 || hb1<=59){
  String str4 = "CONSULT DOCTOR IMMEDIATELY";
lcd.print(str4);
Serial.println(str4);
delay(500);

for(int i=0; i<str4.length(); i++)
{
  lcd.scrollDisplayLeft();
  delay(150);
   }
lcd.clear();
}
else{
  lcd.print("PRESS THE BUTTON");
  delay(2000);
  Serial.println("PRESS THE BUTTON");
}
}
}
