#include <RCSwitch.h>

// named constant for the pin the sensor is connected to
const int sensorPin = A0;
RCSwitch mySwitch = RCSwitch();

void setup(){
  // open a serial connection to display values
  Serial.begin(9600);
  mySwitch.enableTransmit(12);
}

void loop(){
  // read the value on AnalogIn pin 0 
  // and store it in a variable
  int sensorVal = analogRead(sensorPin);

  // convert the ADC reading to voltage
  float voltage = (sensorVal/1024.0) * 5.0;

  // convert the voltage to temperature in degrees C
  // the sensor changes 10 mV per degree
  // the datasheet says there's a 500 mV offset
  // ((volatge - 500mV) times 100)
  Serial.print("degrees C: "); 
  float temperature = (voltage - .5) * 100;
  Serial.println(temperature);
  mySwitch.send("test");
  delay(1000);
}
