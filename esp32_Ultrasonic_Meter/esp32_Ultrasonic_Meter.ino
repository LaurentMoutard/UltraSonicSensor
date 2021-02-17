// ESP32 Dev Module
#include "oled.h"
// Connecter le oled 0.91 sur SDA<-> broche 21 et SCL <-> broche 22

// pins de l'utrasonic
#define TRIGGER_PIN  4  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     15  // Arduino pin tied to echo pin on the ultrasonic sensor.
//Maximum sensor distance is rated at 400-500cm.

long duration, distance;  // For Ping sensor 


void setup() {
  pinMode(TRIGGER_PIN, OUTPUT); // Sets the trigPin as an Output
  pinMode(ECHO_PIN, INPUT); // Sets the echoPin as an Input
  Serial.begin(115200); // Open serial monitor at 115200 baud to see ping results.
  Wire.begin();
  u8g2.begin();
}

void loop() {

  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(5);

  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIGGER_PIN, LOW);
  duration = pulseIn(ECHO_PIN, HIGH);

//Instead of using the Speed of Sound, we can also use the "Pace of Sound".
//The Pace of Sound = 1 / Speed of Sound = 1 / 0.03435 = 29.1 ms/cm
//In this case the equation to calculate the distance become: D = (Δt/2) / Pace of sound
//and for the example above: D = 250 / 29.1 = 8.6 cm

  
  distance = (duration/2) / 29.1; // Aller-retour 
  distance = distance + 16;
  
  Serial.print("Durée : ");
  Serial.println(duration); // Convert ping time to distance and print result (0 = outside set distance range, no ping echo)
  Serial.print("Ping : ");
  Serial.print(distance); // Convert ping time to distance and print result (0 = outside set distance range, no ping echo)
  Serial.println(" cm");
  Serial.println(ltoa(distance, buffer, 10));

  oledPrint(distance);
//  oledPrint(duration);
  delay(500);  // Wait 500ms between pings (about 2 pings/sec). 29ms should be the shortest delay between pings.

 
 }
