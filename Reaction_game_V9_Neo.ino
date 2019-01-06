#include <Adafruit_NeoPixel.h>
int P1Score=0;
int P2Score=0;
int P1Red=1;
int P1Green=1;
int P1Blue=1;
int P2Red=1;
int P2Green=1;
int P2Blue=1;
int Value;
int holder = 0;
int RandomDelay;

 Adafruit_NeoPixel strip = Adafruit_NeoPixel(10, 7, NEO_GRB + NEO_KHZ800);
 
void setup() {
  strip.begin();
  strip.setPixelColor(0, 0,100,0);
  strip.setPixelColor(5, 0,100,0);
  strip.show(); 
  Serial.begin(9600);
  Value = random(1,4);
  Serial.println(Value);
  // put your setup code here, to run once:
pinMode(2, INPUT); //P1 Blue button
pinMode(3, INPUT); //P1 Green button
pinMode(4, INPUT); //P1 Red button

pinMode(8, OUTPUT); //LED Red
pinMode(9, OUTPUT); //LED Green
pinMode(10, OUTPUT); //LED Blue
pinMode(11, INPUT); //P2 Red button
pinMode(12, INPUT); //P2 Green button
pinMode(13, INPUT); //P2 Blue button
digitalWrite(8, HIGH);
digitalWrite(9, HIGH);
digitalWrite(10, HIGH);
  switch (Value)
  {
case 1:
digitalWrite(8, HIGH); //red
digitalWrite(9, HIGH); 
digitalWrite(10, LOW);
break;
case 2:
digitalWrite(8, HIGH);
digitalWrite(9, LOW); //green
digitalWrite(10, HIGH);
break;
case 3:
digitalWrite(8, LOW);
digitalWrite(9, HIGH);
digitalWrite(10, HIGH); //blue
break;
  }
}

void loop() {
P1Red = digitalRead(2);
P1Green = digitalRead(3);
P1Blue = digitalRead(4);
P2Red = digitalRead(11);
P2Green = digitalRead(12);
P2Blue = digitalRead(13);
//Serial.print("Blue is ");
//Serial.println(P2Blue);
//Serial.print("Red is ");
//Serial.println(P2Red);
//Serial.print("Green is ");
//Serial.println(P2Green);
//delay(2000);
//Serial.print("Value is ");
//Serial.println(Value);
Serial.print("P1score= ");
Serial.println(P1Score);
Serial.print("P2score= ");
Serial.println(P2Score);
delay(1000);
if (Value==0)
{
  delay(400);
  Value = random(1,4);
  Serial.println(Value);
  switch (Value)
  {
case 1:
digitalWrite(8, LOW); //red
digitalWrite(9, HIGH); 
digitalWrite(10, HIGH);
break;
case 2:
digitalWrite(8, HIGH);
digitalWrite(9, LOW); //green
digitalWrite(10, HIGH);
break;
case 3:
digitalWrite(8, HIGH);
digitalWrite(9, HIGH);
digitalWrite(10, LOW); //blue
break;
  }
}

if ((Value==3) && (P1Red == 1))
{
  Serial.println("Red pressed");
digitalWrite(8, HIGH);
digitalWrite(9, HIGH); //green
digitalWrite(10, LOW);
delay(200);
digitalWrite(8, HIGH);
digitalWrite(9, HIGH); //green
digitalWrite(10, HIGH);
delay(200);
digitalWrite(8, HIGH);
digitalWrite(9, HIGH); //green
digitalWrite(10, LOW);
delay(200);
digitalWrite(8, HIGH);
digitalWrite(9, HIGH); //green
digitalWrite(10, HIGH);
P1Score=P1Score+1;
UpdateP1();
Value=0;
}
if ((Value==3) && (P2Red == 1))
{
  Serial.println("Red pressed");
digitalWrite(8, HIGH);
digitalWrite(9, HIGH); //green
digitalWrite(10, LOW);
delay(200);
digitalWrite(8, HIGH);
digitalWrite(9, HIGH); //green
digitalWrite(10, HIGH);
delay(200);
digitalWrite(8, HIGH);
digitalWrite(9, HIGH); //green
digitalWrite(10, LOW);
delay(200);
digitalWrite(8, HIGH);
digitalWrite(9, HIGH); //green
digitalWrite(10, HIGH);
P2Score=P2Score+1;
UpdateP1();
Value=0;
}
if ((Value==2)&&(P1Green == 1))
{
digitalWrite(8, HIGH);
digitalWrite(9, LOW); //green
digitalWrite(10, HIGH);
delay(200);
digitalWrite(8, HIGH);
digitalWrite(9, HIGH); //green
digitalWrite(10, HIGH);
delay(200);
digitalWrite(8, HIGH);
digitalWrite(9, LOW); //green
digitalWrite(10, HIGH);
delay(200);
digitalWrite(8, HIGH);
digitalWrite(9, HIGH); //green
digitalWrite(10, HIGH);
P1Score=P1Score+1;
UpdateP1();
Value=0;
}
if ((Value==2)&&(P1Green == 2))
{
digitalWrite(8, HIGH);
digitalWrite(9, LOW); //green
digitalWrite(10, HIGH);
delay(200);
digitalWrite(8, HIGH);
digitalWrite(9, HIGH); //green
digitalWrite(10, HIGH);
delay(200);
digitalWrite(8, HIGH);
digitalWrite(9, LOW); //green
digitalWrite(10, HIGH);
delay(200);
digitalWrite(8, HIGH);
digitalWrite(9, HIGH); //green
digitalWrite(10, HIGH);
P2Score=P2Score+1;
UpdateP1();
Value=0;
}
if ((Value==1)&&(P1Blue == 1))
{
digitalWrite(8, LOW);
digitalWrite(9, HIGH); //green
digitalWrite(10, HIGH);
delay(200);
digitalWrite(8, HIGH);
digitalWrite(9, HIGH); //green
digitalWrite(10, HIGH);
delay(200);
digitalWrite(8, LOW);
digitalWrite(9, HIGH); //green
digitalWrite(10, HIGH);
delay(200);
digitalWrite(8, HIGH);
digitalWrite(9, HIGH); //green
digitalWrite(10, HIGH);
P1Score=P1Score+1;
UpdateP1();
Value=0;
}
if ((Value==1)&&(P2Blue == 1))
{
digitalWrite(8, LOW);
digitalWrite(9, HIGH); //green
digitalWrite(10, HIGH);
delay(200);
digitalWrite(8, HIGH);
digitalWrite(9, HIGH); //green
digitalWrite(10, HIGH);
delay(200);
digitalWrite(8, LOW);
digitalWrite(9, HIGH); //green
digitalWrite(10, HIGH);
delay(200);
digitalWrite(8, HIGH);
digitalWrite(9, HIGH); //green
digitalWrite(10, HIGH);
P2Score=P2Score+1;
UpdateP1();
Value=0;
}

}

void UpdateP1()
{
 strip.setPixelColor((P1Score), 100,0,0);
 strip.setPixelColor((P2Score+5), 0,0,100);
 // strip.setPixelColor((P1Score-2), 0,0,0);
  strip.show(); 
}


