#include <Keyboard.h>

int counter = 0;
bool selected = false;

const int buttonPin = 1;
const int leverPin = 2;
const int LED1 = 6;
const int LED2 = 7;
const int LED3 = 8;
const int LED4 = 9;
const int LED5 = 10;
int LED1State = 0;
int LED2State = 0;
int LED3State = 0;
int LED4State = 0;
int LED5State = 0;
bool myButton = false;
bool myLever = false;
int buttonState = 0;
int leverState = 0;


void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(leverPin, INPUT);
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
      LED1State == HIGH;
      if (counter > 7)
      {
        LED2State == HIGH;
        if (counter > 11)
        {
          LED3State == HIGH;
          if (counter > 15)
          {
            LED4State == HIGH;
            if (counter > 19)
            {
              LED5State == HIGH;
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
  if (leverState == HIGH){
    myLever = true;
  }
    
    
  if (myButton) {
    buttonpress();
    myButton = false;
  }
  if (myLever) {
    if (LED5State == HIGH){
      play();
      counter = 0;
      LED1State == LOW;
      LED2State == LOW;
      LED3State == LOW;
      LED4State == LOW;
      LED5State == LOW;
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
  delay(3000);
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
}



