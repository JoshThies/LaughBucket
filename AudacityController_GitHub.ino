#include "DEV_Config.h"
#include <Keyboard.h>

const int buttonPin = 1;
const int leverPin = 2;
bool myButton = false;
bool myLever = false;
int counter = 0;
int buttonState = 0;
int leverState = 0;


void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(leverPin, INPUT);
  Serial.begin(9600);
  Keyboard.begin();
}

void loop() {
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH){
    myButton = true;
  }
  leverState = digitalRead(leverPin);
  if (leverState == HIGH){
    myLever = true;
  }
  if (myButton) {
    buttonpress();
    myButton = false;
  }
  if (myLever) {
    if (counter >= 2){
      play();
      counter = 0;
    }
    myLever = false;
  }

}

void buttonpress() {
  Keyboard.set_modifier(MODIFIERKEY_SHIFT);
  Keyboard.send_now();
  Keyboard.set_key1(KEY_R);
  Keyboard.send_now();
  delay(10);
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.send_now();
  delay(5000);
  Keyboard.press(KEY_SPACE);
  delay(10);
  Keyboard.releaseAll();
  Keyboard.set_modifier(MODIFIERKEY_SHIFT);
  Keyboard.send_now();
  Keyboard.set_key1(KEY_U);
  Keyboard.send_now();
  delay(10);
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.send_now();
  counter += 1;
}

void play() {
  Keyboard.set_modifier(MODIFIERKEY_CTRL);
  Keyboard.send_now();
  Keyboard.set_modifier(MODIFIERKEY_CTRL | MODIFIERKEY_SHIFT);
  Keyboard.send_now();
  Keyboard.set_key1(KEY_U);
  Keyboard.send_now();
  delay(10);
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.send_now();
  delay(10);
  Keyboard.press(KEY_SPACE);
  delay(10);
  Keyboard.releaseAll();
  delay(7000);
  for(int i=0; i<=counter; i++){
    Keyboard.set_modifier(MODIFIERKEY_CTRL);
    Keyboard.send_now();
    Keyboard.set_key1(KEY_Z);
    Keyboard.send_now();
    delay(10);
    Keyboard.set_modifier(0);
    Keyboard.set_key1(0);
    Keyboard.send_now();
  }
}

