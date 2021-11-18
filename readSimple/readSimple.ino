#include "/home/john/projets/Thermostat-tests/thermistor/thermistor_11.h"

#define therm_pin A0
float T_approx;
float V0 = 5; // voltage reference

int avg_size = 10; // averaging size

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(therm_pin,INPUT);
}

void loop() {
    unsigned int sensorValues = 0;
    for(uint8_t i = 0; i < avg_size; i++)
    {
      sensorValues += analogRead(therm_pin);
      delay(100);
    }
    sensorValues = sensorValues/10;
    uint8_t i = 0;
    while(temptable_11[i][0] < sensorValues) i++;
    Serial.print(temptable_11[i][1]*100);
    Serial.print(", ");
    
    int pente = (temptable_11[i-1][1]-temptable_11[i][1])*100 / (temptable_11[i-1][0]-temptable_11[i][0]);
    int fTemp= temptable_11[i][1]*100 + (temptable_11[i][0] - sensorValues)*pente;
    
    
    Serial.print(fTemp);
    Serial.print(", ");
    Serial.println(pente);
  delay(1000);
}
