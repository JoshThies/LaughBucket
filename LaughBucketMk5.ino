#include <Keyboard.h>

int counter = 0;
bool selected = false;

const int buttonPin = 1;
const int leverPin = 2;
const int BLED = 3;
const int LED1 = 6;
const int LED2 = 7;
const int LED3 = 8;
const int LED4 = 9;
const int LED5 = 10;
bool myButton = false;
bool myLever = false;
int buttonState = 0;
int leverState = 0;


void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(leverPin, INPUT);
  pinMode(BLED, OUTPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  Serial.begin(9600);
  Keyboard.begin();
}

void loop() {
  if (counter > 3)
    {
      digitalWrite(LED1, HIGH);
      if (counter > 7)
      {
        digitalWrite(LED2, HIGH);
        if (counter > 11)
        {
          digitalWrite(LED3, HIGH);
          if (counter > 15)
          {
            digitalWrite(LED4, HIGH);
            if (counter > 19)
            {
              digitalWrite(LED5, HIGH);
            }
          }
        }
      }
    }
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH){
    myButton = true;
  }
  leverState = digitalRead(leverPin);
  if (leverState == LOW){
    myLever = true;
  }
    
    
  if (myButton) {
    buttonpress();
    myButton = false;
  }
  if (myLever) {
    if (counter > 5){
      play();
      counter = 0;
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);
      digitalWrite(LED4, LOW);
      digitalWrite(LED5, LOW);
    }
    myLever = false;
  }
  delay(100);
}

void buttonpress() {
  digitalWrite(BLED, HIGH);
  Keyboard.set_modifier(MODIFIERKEY_SHIFT);
  Keyboard.send_now();
  Keyboard.set_key1(KEY_R);
  Keyboard.send_now();
  delay(10);
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.send_now();
  delay(4000);
  Keyboard.press(KEY_SPACE); 
  delay(10);
  Keyboard.releaseAll();
  counter += 1;
  digitalWrite(BLED, LOW); 
}

void play() {
  navigate(1);
  delay(50);
  Keyboard.press(KEY_SPACE);
  delay(10);
  Keyboard.releaseAll();
  delay(5000);
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
  delay(100);
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



