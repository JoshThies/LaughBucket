/// #include "DEV_Config.h"
#include "Keyboard.h"
vq1


int counter = 0;
bool selected = false;

const int buttonPin = 1;
const int leverPin = 2;
const int cam1Pin = 3;
const int cam2Pin = 4;
const int cam3Pin = 5;
bool myButton = false;
bool myLever = false;
bool cam1 = false;
bool cam2 = false;
bool cam3 = false;
int buttonState = 0;
int leverState = 0;
int cam1State = 0;
int cam2State = 0;
int cam3State = 0;


void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(leverPin, INPUT);
  pinMode(cam1Pin, INPUT);
  pinMode(cam2Pin, INPUT);
  pinMode(cam3Pin, INPUT);
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
  cam1State = digitalRead(cam1Pin);
  cam2State = digitalRead(cam2Pin);
  cam3State = digitalRead(cam3Pin);
  if(counter > 0){
    if (cam1State == HIGH){
      cam1 = true;
    }
    else if (cam2State == HIGH){
      cam2 = true;
    }
    else if (cam3State == HIGH){
      cam3 = true;
    }
    if(cam1) {
      navigate(1);
      selected = true;
      cam1 = false;
    }
    if(cam2) {
      navigate(2);
      selected = true;
      cam2 = false;
    }
    if(cam3) {
      navigate(3);
      selected = true;
      cam3 = false;
    }
  }

    
    
  if (myButton) {
    buttonpress();
    myButton = false;
  }
  if (myLever) {
    if (selected){
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
  selected = false;
  navigate(0);
}

void navigate(int channel) {
  altTab();
  delay(50);
  discordNavi();
  Keyboard.press(KEY_V);
  delay(50);
  Keyboard.releaseAll();
  Keyboard.press(KEY_Q);
  delay(50);
  Keyboard.releaseAll();
  if(channel == 0){
    Keyboard.press(KEY_0);
  }
  if(channel == 1){
    Keyboard.press(KEY_1);
  }
  if(channel == 2){
    Keyboard.press(KEY_2);
  }
  if(channel == 3){
    Keyboard.press(KEY_3);
  }
  delay(50);
  Keyboard.releaseAll(); 
  Keyboard.press(KEY_ENTER);
  delay(50);
  Keyboard.releaseAll();
  altTab();
}

void altTab() {
  Keyboard.set_modifier(MODIFIERKEY_ALT);
  Keyboard.send_now();
  Keyboard.set_key1(KEY_TAB);
  Keyboard.send_now();
  delay(50);
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.send_now();
}

void discordNavi() {
  Keyboard.set_modifier(MODIFIERKEY_CTRL);
  Keyboard.send_now();
  Keyboard.set_key1(KEY_K);
  Keyboard.send_now();
  delay(50);
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.send_now();
}