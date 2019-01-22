/*****************************************************************
Serial_Passthrough.ino

Set up a software serial port to pass data between another serial 
device and the serial monitor.

Hardware Hookup:

Connect your serial devices TX pin to Arduino pin D2 (Software RX)
Connect your serial devices RX pin to Arduino pin D3 (Software TX)
Connect ground on your serial device to ground on the Arduino
*****************************************************************/

// We'll use SoftwareSerial to communicate with the serial device.
#include <SoftwareSerial.h>
// Devices DOUT (TX) is connected to pin 2 (Arduino's Software RX)
// Devices DIN (RX) is connected to pin 3 (Arduino's Software TX)
SoftwareSerial Device(2,3); // RX, TX

void setup()
{
  // Set up both ports at 9600 baud. This value is most important
  // for the XBee. Make sure the baud rate matches the config
  // setting of your XBee.
  Device.begin(9600);     //Create a new 'software' UART on the Arduino and name it 'Device'
  Serial.begin(9600);     //Connect the Arduino to the serial monitor over USB.
  
}

void loop()
{
  if (Serial.available())
  { // If data comes in from serial monitor, send it out to XBee
    Device.write(Serial.read());
  }
  if (Device.available())
  { // If data comes in from XBee, send it out to serial monitor
    Serial.write(Device.read());
  }
}

