#include <Servo.h>

#define RAIN_PIN D0
#define SERVO_PIN D1

Servo myservo;

void setup() {
  pinMode(RAIN_PIN, INPUT);
  myservo.attach(SERVO_PIN);
  Serial.begin(115200);

  myservo.write(0);
}

void loop() {
  int rainDetected = digitalRead(RAIN_PIN);

  if (rainDetected == LOW) { 
    Serial.println("Rain detected!");
    myservo.write(90);
  } else {
    Serial.println("No rain.");
    myservo.write(0);
  }

  delay(1000);
}
