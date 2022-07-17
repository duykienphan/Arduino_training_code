#include <Arduino.h>

byte led = 9;
float val = 0.0;
float state = 0.0;

void print_sensor_value(){
  Serial.print("val: ");
  Serial.println(val);
  delay(200);
}

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(A5);

  state = 0.24927*val;
  /*Serial.print("state: ");
  Serial.println((int)state);

  print_sensor_value();*/
  
  analogWrite(led, (int)state);
}