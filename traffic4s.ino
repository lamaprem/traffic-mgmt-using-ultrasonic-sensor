#include <NewPing.h>

#define TRIGGER_PIN1 2
#define ECHO_PIN1 3
#define TRIGGER_PIN2 4
#define ECHO_PIN2 5
#define TRIGGER_PIN3 6
#define ECHO_PIN3 7
#define TRIGGER_PIN4 8
#define ECHO_PIN4 9

#define RED_LED1 A0
#define GREEN_LED1 A1
#define YELLOW_LED1 A2
#define RED_LED2 A3
#define GREEN_LED2 A4
#define YELLOW_LED2 A5
#define RED_LED3 10
#define GREEN_LED3 11
#define YELLOW_LED3 12
#define RED_LED4 13
#define GREEN_LED4 14
#define YELLOW_LED4 15

#define MAX_DISTANCE 200 // Maximum distance (in cm) to ping.

NewPing sonar1(TRIGGER_PIN1, ECHO_PIN1, MAX_DISTANCE);
NewPing sonar2(TRIGGER_PIN2, ECHO_PIN2, MAX_DISTANCE);
NewPing sonar3(TRIGGER_PIN3, ECHO_PIN3, MAX_DISTANCE);
NewPing sonar4(TRIGGER_PIN4, ECHO_PIN4, MAX_DISTANCE);

void setup() {
  Serial.begin(9600);

  pinMode(RED_LED1, OUTPUT);
  pinMode(GREEN_LED1, OUTPUT);
  pinMode(YELLOW_LED1, OUTPUT);
  pinMode(RED_LED2, OUTPUT);
  pinMode(GREEN_LED2, OUTPUT);
  pinMode(YELLOW_LED2, OUTPUT);
  pinMode(RED_LED3, OUTPUT);
  pinMode(GREEN_LED3, OUTPUT);
  pinMode(YELLOW_LED3, OUTPUT);
  pinMode(RED_LED4, OUTPUT);
  pinMode(GREEN_LED4, OUTPUT);
  pinMode(YELLOW_LED4, OUTPUT);

  // Initialize all LEDs to OFF state
  digitalWrite(RED_LED1, LOW);
  digitalWrite(GREEN_LED1, LOW);
  digitalWrite(YELLOW_LED1, LOW);
  digitalWrite(RED_LED2, LOW);
  digitalWrite(GREEN_LED2, LOW);
  digitalWrite(YELLOW_LED2, LOW);
  digitalWrite(RED_LED3, LOW);
  digitalWrite(GREEN_LED3, LOW);
  digitalWrite(YELLOW_LED3, LOW);
  digitalWrite(RED_LED4, LOW);
  digitalWrite(GREEN_LED4, LOW);
  digitalWrite(YELLOW_LED4, LOW);
}

void loop() {
  int distance1 = sonar1.ping_cm();
  int distance2 = sonar2.ping_cm();
  int distance3 = sonar3.ping_cm();
  int distance4 = sonar4.ping_cm();

  // Traffic management logic
  if (distance1 <= 10) { // If sensor 1 detects an obstacle
    // Set traffic lights for sensor 1
    digitalWrite(RED_LED1, LOW);
    digitalWrite(GREEN_LED1, HIGH);
    digitalWrite(YELLOW_LED1, LOW);
    digitalWrite(RED_LED2, HIGH);
    digitalWrite(RED_LED3, HIGH);
    digitalWrite(RED_LED4, HIGH);
   
  } else if (distance2 <= 10) { // If sensor 2 detects an obstacle
    // Set traffic lights for sensor 2
    digitalWrite(RED_LED2, LOW);
    digitalWrite(GREEN_LED2, HIGH);
    digitalWrite(YELLOW_LED2, LOW);
    digitalWrite(RED_LED1, HIGH);
    digitalWrite(RED_LED3, HIGH);
    digitalWrite(RED_LED4, HIGH);
  } else if (distance3 <= 10) { // If sensor 3 detects an obstacle
    // Set traffic lights for sensor 3
    digitalWrite(RED_LED3, LOW);
    digitalWrite(GREEN_LED3, HIGH);
    digitalWrite(YELLOW_LED3, LOW);
    digitalWrite(RED_LED2, HIGH);
    digitalWrite(RED_LED1, HIGH);
    digitalWrite(RED_LED4, HIGH);
  } else if (distance4 <= 10) { // If sensor 4 detects an obstacle
    // Set traffic lights for sensor 4
    digitalWrite(RED_LED4, LOW);
    digitalWrite(GREEN_LED4, HIGH;
    digitalWrite(YELLOW_LED4, LOW);
    digitalWrite(RED_LED2, HIGH);
    digitalWrite(RED_LED3, HIGH);
    digitalWrite(RED_LED1, HIGH);
  } else { // If no obstacle detected
    // Set all traffic lights to green
    digitalWrite(RED_LED1, LOW);
    digitalWrite(GREEN_LED1, HIGH);
    digitalWrite(YELLOW_LED1, LOW);
    digitalWrite(RED_LED2, LOW);
    digitalWrite(GREEN_LED2, HIGH);
    digitalWrite(YELLOW_LED2, LOW);
    digitalWrite(RED_LED3, LOW);
    digitalWrite(GREEN_LED3, HIGH);
    digitalWrite(YELLOW_LED3, LOW);
    digitalWrite(RED_LED4, LOW);
    digitalWrite(GREEN_LED4, HIGH);
    digitalWrite(YELLOW_LED4, LOW);
  }

  delay(100); // Adjust delay according to your application
}
