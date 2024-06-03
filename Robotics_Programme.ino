// this programme allows for the controlling of servos by potentialometers, along with the ability to turn on and of an inducible magnet with a mechanical switch.


#include <Servo.h>

Servo myservo;   // create servo object to control servo1
Servo myservo2;  // create servo object to control servo2
Servo myservo3;  // create servo object to control servo3

int potpin = A0;   // analog pin used to connect the potentiometer
int val;           // variable to read the value from the analog pin

int potpin2 = A1;  // analog pin used to connect the second potentiometer
int val2;          // variable to read the value from the second analog pin

int potpin3 = A2;  // analog pin used to connect the third potentiometer
int val3;          // variable to read the value from the third analog pin

int button_input = 6;  // digital pin used to connect the button
int EM_output = 7;     // digital pin used to control the electromagnet
int state = 0;         // variable to store the button state
bool EM_POWER = false; // boolean to store the state of the electromagnet

void setup() {

  myservo.attach(8); // Attach servos to corresponding pins 
  myservo2.attach(4);
  myservo3.attach(3);

  pinMode(8, OUTPUT); // Set pin modes for servo pins, button input, and electromagnet output
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(button_input, INPUT);
  pinMode(EM_output, OUTPUT);
}

void loop() {

  if (digitalRead(button_input) == HIGH) { // Check if the button is pressed
    EM_POWER = !EM_POWER; // Toggle the electromagnet power state
    digitalWrite(EM_output, EM_POWER); // Set the electromagnet output based on the new power state
  }

  
  val = analogRead(potpin); // Read the value from the first potentiometer
  val = map(val, 0, 1023, 0, 180); // Map the value to a range of 0 to 180 degrees
  myservo.write(val); // Write the mapped value to the first servo


  val2 = analogRead(potpin2);
  val2 = map(val2, 0, 1023, 0, 180);
  myservo2.write(val2);

  val3 = analogRead(potpin3);
  val3 = map(val3, 0, 1023, 0, 180);
  myservo3.write(val3);
}


/*

some specific advantages of our code include:
•we specifically chose to map a range of values from 0 to 180 to limit the movement of the servo, a movement of 360 degrees could have proven 
to implement error and may have made it harder to figure out in what position the servo was at any given momemnt during the competition 
•we also wanted to print the state of the button onto the terminal so we always knew whether the magnet was on or off during the competition.
if all of the sudden the magnet was on but we thought it was of, this could have delayed us or introduced error during the competition.


Our code is comprised of 3 segments.

Initialization:

Three Servo objects (myservo, myservo2, myservo3) are created to control three different servos.
Three potentiometers are connected to analog pins A0, A1, and A2.
A button is connected to digital pin 6 to toggle the state of the electromagnet.
An electromagnet is controlled via digital pin 7.
Variables are defined to store the state of the potentiometers (val, val2, val3), button (button_input), and electromagnet (EM_output and EM_POWER).
Setup Function:

Attach the servos to digital pins 8, 4, and 3.
Set the pin modes for the servo pins, button input, and electromagnet output.
Loop Function:

The state of the button is read. If the button is pressed, it toggles the EM_POWER boolean variable and updates the electromagnet state accordingly.
The values from the potentiometers are read and mapped from the range [0, 1023] to [0, 180] degrees.
The mapped values are then written to the corresponding servos, causing them to rotate to the position based on the potentiometer readings.

Setup Function:

Attach the servos to digital pins 8, 4, and 3.
Set the pin modes for the servo pins, button input, and electromagnet output.

Loop Function:

The state of the button is read. If the button is pressed, it toggles the EM_POWER boolean variable and updates the electromagnet state accordingly.
The values from the potentiometers are read and mapped from the range [0, 1023] to [0, 180] degrees.
The mapped values are then written to the corresponding servos, causing them to rotate to the position based on the potentiometer readings.

*/
