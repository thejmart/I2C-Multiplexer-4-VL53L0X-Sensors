/**
 * CODE by Johnathan Martin a.k.a the_jmart
 * By using the TCA9548A I2C Multiplexer Breakout you can read
 * four VL53L0X Time-of-Flight range sensors at the same time over 
 * one I2C address. This code is written specific for the devices 
 * used. 
 * 
 * TCA9548 I2CScanner.pde -- I2C bus scanner for Arduino
 * Based on code c. 2009, Tod E. Kurt, http://todbot.com/blog/
 *
 */

#include "Wire.h"
extern "C" { 
#include "utility/twi.h"  // from Wire library, so we can do bus scanning
}
#include "Adafruit_VL53L0X.h"

Adafruit_VL53L0X lox = Adafruit_VL53L0X();


#define TCAADDR 0x70

void tcaselect(uint8_t i) {
  if (i > 7) return;
 
  Wire.beginTransmission(TCAADDR);
  Wire.write(1 << i);
  Wire.endTransmission();  
}
// standard Arduino setup()
void setup()
{
    while (!Serial);
    delay(1000);
    Wire.begin();
    Serial.begin(9600);

    Serial.print("Start.");
    
    tcaselect(0);
    if (!lox.begin()) {
    Serial.println(F("Failed to boot VL53L0X"));
    while(1);
    }
    tcaselect(1);
    if (!lox.begin()) {
    Serial.println(F("Failed to boot VL53L0X"));
    while(1);
    }
    tcaselect(2);
    if (!lox.begin()) {
    Serial.println(F("Failed to boot VL53L0X"));
    while(1);
    }
    tcaselect(7);
    if (!lox.begin()) {
    Serial.println(F("Failed to boot VL53L0X"));
    while(1);
    }
    
    Serial.println(" End setup");
    delay(2000);
    
}

void loop() 
{
  
  VL53L0X_RangingMeasurementData_t measure;
  /*
  for(int x = 0; x < 20; x++){
    
    tcaselect(0);
    
    Serial.print("Reading a measurement... ");
    lox.rangingTest(&measure, false); // pass in 'true' to get debug data printout!

    if (measure.RangeStatus != 4) {  // phase failures have incorrect data
      Serial.print("LIDAR_0_Distance (mm): "); Serial.println(measure.RangeMilliMeter);
    } else {
      Serial.println(" out of range ");
    }
    
    delay(100);
  }

  for(int x = 0; x < 20; x++){
    
    tcaselect(1);
    
    Serial.print("Reading a measurement... ");
    lox.rangingTest(&measure, false); // pass in 'true' to get debug data printout!

    if (measure.RangeStatus != 4) {  // phase failures have incorrect data
      Serial.print("LIDAR_1_Distance (mm): "); Serial.println(measure.RangeMilliMeter);
    } else {
      Serial.println(" out of range ");
    }
    
    delay(100);
  }
  for(int x = 0; x < 20; x++){
   
    tcaselect(2);
    
    Serial.print("Reading a measurement... ");
    lox.rangingTest(&measure, false); // pass in 'true' to get debug data printout!

    if (measure.RangeStatus != 4) {  // phase failures have incorrect data
      Serial.print("LIDAR_2_Distance (mm): "); Serial.println(measure.RangeMilliMeter);
    } else {
      Serial.println(" out of range ");
    }
    
    delay(100);
  }
  for(int x = 0; x < 20; x++){
    
    tcaselect(7);
    
    Serial.print("Reading a measurement... ");
    lox.rangingTest(&measure, false); // pass in 'true' to get debug data printout!

    if (measure.RangeStatus != 4) {  // phase failures have incorrect data
      Serial.print("LIDAR_3_Distance (mm): "); Serial.println(measure.RangeMilliMeter);
    } else {
      Serial.println(" out of range ");
    }
    
    delay(100);
  }
  */
    tcaselect(0);
    lox.rangingTest(&measure, false); // pass in 'true' to get debug data printout!

    if (measure.RangeStatus != 4) {  // phase failures have incorrect data
      Serial.print("L0: "); Serial.print(measure.RangeMilliMeter);Serial.print(" ");
    } else {
      Serial.print("L0: "); Serial.print("OOR"); Serial.print(" ");
    }
    
    tcaselect(1);
    lox.rangingTest(&measure, false); // pass in 'true' to get debug data printout!

    if (measure.RangeStatus != 4) {  // phase failures have incorrect data
      Serial.print("L1: "); Serial.print(measure.RangeMilliMeter);Serial.print(" ");
    } else {
      Serial.print("L1: "); Serial.print("OOR");Serial.print(" ");
    }
    
    tcaselect(2);
    lox.rangingTest(&measure, false); // pass in 'true' to get debug data printout!

    if (measure.RangeStatus != 4) {  // phase failures have incorrect data
      Serial.print("L2: "); Serial.print(measure.RangeMilliMeter);Serial.print(" ");
    } else {
      Serial.print("L2: "); Serial.print("OOR");Serial.print(" ");
    }
    
    tcaselect(7);
    lox.rangingTest(&measure, false); // pass in 'true' to get debug data printout!

    if (measure.RangeStatus != 4) {  // phase failures have incorrect data
      Serial.print("L3: "); Serial.print(measure.RangeMilliMeter);Serial.print(" ");
    } else {
      Serial.print("L3: "); Serial.print("OOR");Serial.print(" ");
    }
    Serial.println("");
    
    delay(20);
 
}
