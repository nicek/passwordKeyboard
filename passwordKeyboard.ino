/*
 * 
 *  Project     Password keyboard
 *  @author     Nicek
 *
 */


// Pin definitions
#define BUTTON_PIN1 2
#define BUTTON_PIN2 3
#define BUTTON_PIN3 4
#define BUTTON_PIN4 5
#define BUTTON_PIN5 6
#define BUTTON_PIN6 7

#include "Keyboard.h"

class button {
  public:
  const uint8_t pin;
  button(uint8_t p) : pin(p){}

  void press(boolean state){
    if (state) {
      switch(pin)
      {
        case 2:
          Keyboard.print("password1");
          break;
        case 3:
          Keyboard.print("password2");
          break;
        case 4:
          Keyboard.print("password3");
          break;
        case 5:
          Keyboard.print("password4");
          break;
        case 6:
          Keyboard.print("password5");
          break;
        case 7:
          Keyboard.print("password6");
          break;
      }
      Keyboard.write(176);
      delay(500);
    }
    pressed = state;
  }

  void update(){
    press(!digitalRead(pin));
  }

  private:
  boolean pressed = 0;
} ;

button buttons[] = {
  {BUTTON_PIN1},
  {BUTTON_PIN2},
  {BUTTON_PIN3},
  {BUTTON_PIN4},
  {BUTTON_PIN5},
  {BUTTON_PIN6},
};

const uint8_t NumButtons = sizeof(buttons) / sizeof(button);
const uint8_t ledPin = 17;

void setup() { 

  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);
  TXLED0;

  for(int i = 0; i < NumButtons; i++){
    pinMode(buttons[i].pin, INPUT_PULLUP);
  }
}

void loop() {
  for(int i = 0; i < NumButtons; i++){
    buttons[i].update();
  }
}
