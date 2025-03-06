/*
 * Personalized Lightbox Display - Arduino Mega
 * This project allows a user to type using a PS2 keyboard and display text on an LED matrix.
 * Components: Arduino Mega, PS2 Keyboard, LED Matrix
 * Libraries: PS2Keyboard.h, RGBmatrixPanel.h
 */

#include <PS2Keyboard.h>  // library for PS2 keyboard input
#include <RGBmatrixPanel.h>  // library for LED matrix display

using namespace std;  

// PS2 Keyboard Pins
const int DataPin = 4;
const int IRQpin = 3;

// LED Matrix Pins for Arduino Mega
#define CLK 11  
#define OE 9
#define LAT 10
#define A A0
#define B A1
#define C A2
#define D A3

// initialize keyboard and LED Matrix
PS2Keyboard keyboard;
RGBmatrixPanel matrix(A, B, C, D, CLK, LAT, OE, false, 64);

// Global Variables
String str = "";  // stores the input string from the keyboard
int enters = 0;   // tracks number of "Enter" key presses
int lineLeft = 10; // stores the left position of the text on the LED Matrix
int calls; 

void setup() {
    // Initialize the keyboard
    keyboard.begin(DataPin, IRQpin);

    // serial communication for debugging
    Serial.begin(9600);
    Serial.println("Keyboard Test: Ready");
}

void loop() {
    // check if serial data is available (for debugging purposes)
    if (Serial.available()) {
        Serial.println("Back at serial");
        delay(100);

        // process incoming serial data
        while (Serial.available() > 0) {
            if (calls > 0) {  
               ?
            }
        }
    }

    // check if a key is available from the PS2 keyboard
    if (keyboard.available()) {
        char c = keyboard.read();  // read key from keyboard
        Serial.print("Key Pressed: ");
        Serial.println(c);

        // handle backspace key
        if (c == PS2_DELETE || c == PS2_BACKSPACE) {
            if (str.length() > 0) {
                str.remove(str.length() - 1); // remove last character
                lineLeft -= 6;  // move cursor back
                Serial.println("Backspace pressed: Character removed.");
            }
        }
        // handle enter key (new line)
        else if (c == PS2_ENTER) {
            enters++;  // increase line counter
            lineLeft = 10;  // reset left position
            str = "";  // clear string buffer
            Serial.println("New Line Entered.");
        }
        // handle normal characters
        else {
            str += c;  // append character to string buffer
            lineLeft += 6;  // move cursor forward
        }

        // display the text on the LED Matrix
        matrix.fillScreen(0); // Clear screen before drawing
        matrix.setCursor(lineLeft, enters * 8);  // position text
        matrix.print(str);  // display string on LED matrix
        matrix.swapBuffers(false);  // refresh display
    }
}