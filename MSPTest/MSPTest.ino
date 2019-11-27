#include <c_library_v2/common/mavlink.h>
#include <pins_energia.h>
#include "TFMini.h"

// Setup software serial port
TFMini tfmini;
void setup() {
  // Step 1: Initialize hardware serial port (serial debug port)
  Serial.begin(9600);
  // wait for serial port to connect. Needed for native USB port only
  while (!Serial);
  Serial.println ("Initializing...");

  // Step 2: Initialize the data rate for the SoftwareSerial port
  Serial1.begin(TFMINI_BAUDRATE);

  // Step 3: Initialize the TF Mini sensor
  tfmini.begin(&Serial1);
}


void loop() {
  // Take one TF Mini distance measurement
  uint16_t dist = tfmini.getDistance();
  uint16_t strength = tfmini.getRecentSignalStrength();

  // Display the measurement
  Serial.print(dist);
  //Serial.print("\r\n");
  Serial.print(" cm      sigstr:");
  Serial.print(strength);
  Serial.print("\r\n");

  // Wait some short time before taking the next measurement
  delay(25);
}
