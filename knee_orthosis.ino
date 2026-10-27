#include <Wire.h>                  // Include the I2C library
#include <Adafruit_Sensor.h>        // Include Adafruit Sensor library
#include <Adafruit_ADXL345_U.h>     // Include the Adafruit ADXL345 library
Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified();
const int piezoPin = A1;  // Piezoelectric sensor connected to analog pin A0
const int threshold = 100;  // Adjust this value based on your sensor sensitivity
int psr_frontshole = A0;     // the FSR and 10K pulldown are connected to a0
int psr_Reading;
int voltage = 5; 
void setup() {
Serial.begin(9600);
Wire.begin();
!accel.begin();
}

void loop() {
sensors_event_t event;
accel.getEvent(&event);
Serial.print(" |X:");
Serial.print(event.acceleration.x);
Serial.print(" |Y:");
Serial.print(event.acceleration.y);
Serial.print(" |Z:");
Serial.println(event.acceleration.z);
int piezoValue = analogRead(piezoPin);
Serial.print("Pizzo elecric =");
Serial.print(piezoValue*voltage);
Serial.println("pC/N");
delay(2000);
psr_Reading = analogRead(psr_frontshole);  
Serial.print("psr_front =");
Serial.print(psr_Reading); 
Serial.println("kpa"); 
delay(2000);
}
