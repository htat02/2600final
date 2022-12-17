#include <Keypad.h>
#include <PubSubClient.h>
#include <esp_wifi.h>

int player= 1; //set player 1

// define the symbols on the buttons of the keypad
char keys[4][4] = {
 {'1', '2', '3', 'A'},
 {'4', '5', '6', 'B'},
 {'7', '8', '9', 'C'},
 {'*', '0', '#', 'D'}
};
byte rowPins[4] = {14, 27, 26, 25}; // connect to the row pinouts of the keypad
byte colPins[4] = {33, 21, 22, 23}; // connect to the column pinouts of the keypad

// initialize an instance of class NewKeypad
Keypad myKeypad = Keypad(makeKeymap(keys), rowPins, colPins, 4, 4);

int latchPin = 2;          // Pin connected to ST_CP of 74HC595（Pin12）
int clockPin = 4;          // Pin connected to SH_CP of 74HC595（Pin11）
int dataPin = 15;          // Pin connected to DS of 74HC595（Pin14）


void setup() {
  Serial.begin(115200); // Initialize the serial port and set the baud rate to 115200
  Serial.println("ESP32 is ready! "); // Print the string "ESP32 is ready! "

  // set pins to output
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

void loop() {
  // Get the character input
 char keyPressed = myKeypad.getKey();
 // If there is a character input, sent it to the serial port
 if (keyPressed) {
 Serial.println(keyPressed);
 }

  // Define a one-byte variable (8 bits) which is used to represent the selected state of 8 column.
  int cols;
  // Display the static smiling pattern
  for (int j = 0; j < 500; j++ ) {  // repeat 500 times
    cols = 0x01;
      switch(keyPressed)
      case 1:
        if(player= 1){
          matrixRowsVal(0x40);
          delay(1);
          matrixRowsVal(0x80);
          cols+=
        }
        if(player= 2){
          matrixRowsVal(0xC0);
          delay(1);
          cols+=;
          matrixRowsVal(0xC0);
          cols+=;
        break;
        }
      case 2:
        if(player= 1){
          matrixRowsVal(0x40);
          delay(1);
          matrixRowsVal(0x80);
          cols+=
        }
        if(player= 2){
          matrixRowsVal(0xC0);
          delay(1);
          cols+=;
          matrixRowsVal(0xC0);
          cols+=;
        break;
        case 3:
        if(player= 1){
          matrixRowsVal(0x40);
          delay(1);
          matrixRowsVal(0x80);
          cols+=
        }
        if(player= 2){
          matrixRowsVal(0xC0);
          delay(1);
          cols+=;
          matrixRowsVal(0xC0);
          cols+=;
        break;
        case 4:
        if(player= 1){
          matrixRowsVal(0x40);
          delay(1);
          matrixRowsVal(0x80);
          cols+=
        }
        if(player= 2){
          matrixRowsVal(0xC0);
          delay(1);
          cols+=;
          matrixRowsVal(0xC0);
          cols+=;
        break;
        case 5:
        if(player= 1){
          matrixRowsVal(0x40);
          delay(1);
          matrixRowsVal(0x80);
          cols+=
        }
        if(player= 2){
          matrixRowsVal(0xC0);
          delay(1);
          cols+=;
          matrixRowsVal(0xC0);
          cols+=;
        break;
      case 6:
        if(player= 1){
          matrixRowsVal(0x40);
          delay(1);
          matrixRowsVal(0x80);
          cols +=;
        }
        if(player= 2){
          matrixRowsVal(0x80);
          delay(1);
          matrixRowsVal(0x40);
          cols+=
          matrixRowsVal(0x80);
          delay(1);
          matrixRowsVal(0x40);
          cols+=
        }
        break;
        case 7:
        if(player= 1){
          matrixRowsVal(0x40);
          delay(1);
          matrixRowsVal(0x80);
          cols +=;
        }
        if(player= 2){
          matrixRowsVal(0x80);
          delay(1);
          matrixRowsVal(0x40);
          cols+=
          matrixRowsVal(0x80);
          delay(1);
          matrixRowsVal(0x40);
          cols+=
        }
        break;
        case 8:
        if(player= 1){
          matrixRowsVal(0x40);
          delay(1);
          matrixRowsVal(0x80);
          cols+=
        }
        if(player= 2){
          matrixRowsVal(0xC0);
          delay(1);
          cols+=;
          matrixRowsVal(0xC0);
          cols+=;
        break;
        }

        
      }
      }                 
    }
  }
  player = (player % 2) ? 1 : 2;
}
}

void matrixRowsVal(int value) {
  // make latchPin output low level
  digitalWrite(latchPin, LOW);
  // Send serial data to 74HC595
  shiftOut(dataPin, clockPin, LSBFIRST, value);
  // make latchPin output high level, then 74HC595 will update the data to parallel output
  digitalWrite(latchPin, HIGH);
}

void matrixColsVal(int value) {
  // make latchPin output low level
  digitalWrite(latchPin, LOW);
  // Send serial data to 74HC595
  shiftOut(dataPin, clockPin, MSBFIRST, value);
  // make latchPin output high level, then 74HC595 will update the data to parallel output
  digitalWrite(latchPin, HIGH);
}
