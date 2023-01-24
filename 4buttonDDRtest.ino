
#include "USB.h"
#include "USBHIDKeyboard.h"
USBHIDKeyboard Keyboard;
const int upPin = 3;
const int rightPin = 4;
const int downPin = 2;
const int leftPin = 1;
const int escPin = 5;
const int enterPin = 6;
const int leftLightPin = 10;
const int downLightPin = 11;
const int upLightPin = 12;
const int rightLightPin = 13;

int upSensorValue = 0;
int rightSensorValue = 0;
int downSensorValue = 0;
int leftSensorValue = 0;
int escSensorValue = 0;
int enterSensorValue = 0;

void setup() {
  // make pin 0 an input and turn on the pull-up resistor so it goes high unless
  // connected to ground:
  Serial.begin(115200);
  pinMode(upPin,INPUT_PULLUP);
  pinMode(rightPin,INPUT_PULLUP);
  pinMode(downPin,INPUT_PULLUP);
  pinMode(leftPin,INPUT_PULLUP);
  pinMode(escPin,INPUT_PULLUP);
  pinMode(enterPin,INPUT_PULLUP);
  pinMode(leftLightPin,OUTPUT);
  pinMode(downLightPin,OUTPUT);
  pinMode(upLightPin,OUTPUT);
  pinMode(rightLightPin,OUTPUT);
  Keyboard.begin();
  USB.begin();
}

void loop() {
  upSensorValue = digitalRead(upPin);
  rightSensorValue = digitalRead(rightPin);
  downSensorValue = digitalRead(downPin);
  leftSensorValue = digitalRead(leftPin);
  escSensorValue = digitalRead(escPin);
  enterSensorValue = digitalRead(enterPin);
  if (upSensorValue == 0){
    Keyboard.press(KEY_UP_ARROW);
    digitalWrite(upLightPin,HIGH);
  }
  else{
    Keyboard.release(KEY_UP_ARROW);
    digitalWrite(upLightPin,LOW);
  }
  if (rightSensorValue == 0){
    Keyboard.press(KEY_RIGHT_ARROW);
    digitalWrite(rightLightPin,HIGH);
  }
  else{
    Keyboard.release(KEY_RIGHT_ARROW);
    digitalWrite(rightLightPin,LOW);
  }
  if (downSensorValue == 0){
    Keyboard.press(KEY_DOWN_ARROW);
    digitalWrite(downLightPin,HIGH);
  }
  else{
    Keyboard.release(KEY_DOWN_ARROW);
    digitalWrite(downLightPin,LOW);
  }
  if (leftSensorValue == 0){
    Keyboard.press(KEY_LEFT_ARROW);
    digitalWrite(leftLightPin,HIGH);
  }
  else{
    Keyboard.release(KEY_LEFT_ARROW);
    digitalWrite(leftLightPin,LOW);
  }
  if (escSensorValue == 0){
    Keyboard.press(KEY_ESC);
  }
  else{
    Keyboard.release(KEY_ESC);
  }
  if (enterSensorValue == 0){
    Keyboard.press(KEY_RETURN);
  }
  else{
    Keyboard.release(KEY_RETURN);
  }
}
