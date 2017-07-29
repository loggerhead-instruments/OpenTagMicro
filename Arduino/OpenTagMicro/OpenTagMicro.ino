// OpenTagMicro
// c 2017 Loggerhead Instruments

// To Do
// - read sensors: KMX62
// - read/set RTC
// - microSd
// - FIFO interrupt
// - sleep between interrupts

#include <Wire.h>

#define LED 4
// RTC
byte hour, minute, second, year, month, date;

// Accerometer/Magnetometer
int accelX, accelY, accelZ;
int magX, magY, magZ;
int accel_x_int, accel_y_int, accel_z_int;

void setup() {
   Serial.begin(9600);
   Serial.println("OpenTag micro");
   delay(1000);

   pinMode(LED, OUTPUT);
   digitalWrite(LED, HIGH);

   Wire.begin();
   delay(10);
   setTime2(0, 0, 0, 1, 1, 18);
//  Accel_Init(0x53, 100, 0 , 0);
    Serial.println("KMX reset");
    kmx62Reset();
    delay(1000);
    Serial.print(kmx62Init());
}

void loop() {
   readRtc();
   Serial.print(year); Serial.print("-");
   Serial.print(month); Serial.print("-");
   Serial.print(date); Serial.print("T");
   Serial.print(hour); Serial.print(":");
   Serial.print(minute); Serial.print(":");
   Serial.println(second);
   
   Serial.print(kmx62TestResponse()); Serial.print(" ");
   readKMX62();
   Serial.println(accelX);

   // Read_Accel(0x53);
   // Serial.println(accel_x_int);
   
   delay(1000);
}
