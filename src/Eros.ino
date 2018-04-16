/*Author: Mwape
 * Date: 2018
 * V1
 * For use with Arduino UNO R3

*/

#include <LiquidCrystal.h>
#include <Wire.h>
#include <DS1302.h>


// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {

 Wire.begin(8);                // join i2c bus with address #8
  Wire.onReceive(receiveEvent); // register receive event
  Wire.onRequest(requestEvent); // register request event
  Serial.begin(9600);           // start serial for debug
  
  // put your setup code here, to run once:

    // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Setting up...");
  delay(1000);
  lcd.clear();
   lcd.print("Project Cleo");
   delay(1000);
  lcd.clear();

}

void loop() {
  delay(1000);
  lcd.setCursor(0,0);
 lcd.clear();
}

// function that executes whenever data is received from master
void receiveEvent(int howMany) {
  while (0 < Wire.available()) {
    char c = Wire.read(); // receive byte as a character
    Serial.print(c);         // print the character
  //  lcd.print(c);
   
  }
  Serial.println();         // to newline
}

// function that executes whenever data is requested from master
void requestEvent() {
  Wire.write("Hello NodeMCU");//send string on request
  lcd.print("NCU, I Read you");
}



