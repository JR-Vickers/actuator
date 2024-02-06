#include <Servo.h>

Servo myServo;           // create servo object to control a servo
const int servoPin = 9;  // the pin where the servo is connected

void setup() {
  myServo.attach(servoPin);  // attaches the servo on the pin to the servo object
  Serial.begin(9600);        // start serial communication at 9600 baud
  myServo.write(0);          // keep the servo closed at startup
}

void loop() {
  if (Serial.available() > 0) {                     // check if any data is available from the Serial Monitor
    String command = Serial.readStringUntil('\n');  // read the data as a string until a newline character
    command.trim();                                 // Trim any whitespace or newline characters

    if (command.toInt() >= 0 && command.toInt() <= 100) {
      int angle = map(command.toInt(), 0, 100, 0, 180);  // map the percentage to an angle between 0 and 180
      myServo.write(angle);                              // rotate the servo to the mapped angle
      Serial.print("Servo rotated to ");
      Serial.print(angle);
      Serial.println(" degrees");
    }
  }
}