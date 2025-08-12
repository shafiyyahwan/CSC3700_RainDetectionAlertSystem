#include <EEPROM.h>

const int addr_eventCount   = 0;
const int eventSize         = 10;  // Byte per event
const int addr_events_start = 1;   // Data starts from EEPROM[1]

void setup() {
  Serial.begin(9600);   // Begin serial communication
  delay(500);

  int count = EEPROM.read(addr_eventCount);  // Read the number of saved rain events
  Serial.println();
  Serial.println("Rain Detection and Alert System");  // Print header
  Serial.print("Rain Event Count: ");                  
  Serial.println(count);  // Print rain count
  Serial.println();
  Serial.println("Rain   End Time              Duration"); // Print table header

  // Loop through all stored events
  for (int i = 0; i < count; i++) {                              
    int base = addr_events_start + i * eventSize;

    // Read stored date and time
    byte day    = EEPROM.read(base);
    byte month  = EEPROM.read(base + 1);
    byte year   = EEPROM.read(base + 2);
    byte hour   = EEPROM.read(base + 3);
    byte minute = EEPROM.read(base + 4);
    byte second = EEPROM.read(base + 5);

    // Read duration (hours, minutes, seconds)
    byte durH = EEPROM.read(base + 7);
    byte durM = EEPROM.read(base + 8);
    byte durS = EEPROM.read(base + 9);

    // Print row
    Serial.print(i + 1);
    Serial.print("      ");

    // Print formatted end time (DD/MM/YY HH:MM:SS)
    if (day < 10) Serial.print("0");
    Serial.print(day); Serial.print("/");
    if (month < 10) Serial.print("0");
    Serial.print(month); Serial.print("/");
    Serial.print(year); Serial.print(" ");
    if (hour < 10) Serial.print("0");
    Serial.print(hour); Serial.print(":");
    if (minute < 10) Serial.print("0");
    Serial.print(minute); Serial.print(":");
    if (second < 10) Serial.print("0");
    Serial.print(second); Serial.print("   ");

    // Print formatted duration (HH:MM:SS)
    if (durH < 10) Serial.print("0");
    Serial.print(durH); Serial.print(":");
    if (durM < 10) Serial.print("0");
    Serial.print(durM); Serial.print(":");
    if (durS < 10) Serial.print("0");
    Serial.println(durS);
  }
}

void loop() {
}
