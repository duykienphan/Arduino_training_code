#include <Arduino.h>

byte trig = 8;     // chân trig của HC-SR04
byte echo = 9;     // chân echo của HC-SR04

unsigned long duration; // biến đo thời gian
float distance;         // biến lưu khoảng cách
 
void setup(){
    Serial.begin(9600);     // giao tiếp Serial với baudrate 9600
    pinMode(trig, OUTPUT);   // chân trig sẽ phát tín hiệu
    pinMode(echo, INPUT);    // chân echo sẽ nhận tín hiệu
}
 
void loop(){
    digitalWrite(trig, LOW);   // tắt chân trig
    delayMicroseconds(2);
    digitalWrite(trig, HIGH);   // phát xung từ chân trig
    delayMicroseconds(5);   // xung có độ dài 5 microSeconds
    digitalWrite(trig, LOW);   // tắt chân trig
   
    duration = pulseIn(echo, HIGH); 
    distance = duration/2/29.412;
    
    Serial.print(distance);
    Serial.println(" cm");
    delay(100);
} 
