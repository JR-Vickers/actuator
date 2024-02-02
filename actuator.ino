#include <Servo.h>

Servo myServo;           // create servo object to control a servo
const int servoPin = 9;  // the pin where the servo is connected

void setup() {
  myServo.attach(servoPin);  // attaches the servo on the pin to the servo object
  Serial.begin(9600);        // start serial communication at 9600 baud
  myServo.write(0);          // stop the servo at startup (90 is typically the stop position for continuous servos)
}

void loop() {
  if (Serial.available() > 0) {                     // check if any data is available from the Serial Monitor
    String command = Serial.readStringUntil('\n');  // read the data as a string until a newline character
    command.trim();                                 // Trim any whitespace or newline characters

    // if we receive 'OPEN', start spinning the servo
    if (command.equals("OPEN")) {
      myServo.write(180);  // you can adjust this value for the desired speed
      Serial.println("Servo Spinning");
    }
    // if we receive 'CLOSE', stop spinning the servo
    else if (command.equals("CLOSE")) {
      myServo.write(0);  // 90 is typically the stop position for continuous servos
      Serial.println("Servo Stopped");
    } else if (command.toInt() >= 0 && command.toInt() <= 100) {
      int angle = map(command.toInt(), 0, 100, 0, 180);  // map the percentage to an angle between 0 and 180
      myServo.write(angle);                              // rotate the servo to the mapped angle
      Serial.print("Servo rotated to ");
      Serial.print(angle);
      Serial.println(" degrees");
    }
  }
}