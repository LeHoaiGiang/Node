#include "Node.H"
Q2HX711 hx711(hx711_data_pin, hx711_clock_pin);
void setup()
{
 Serial.begin(9600);
    pinMode(4, OUTPUT);
   setupLora();
   LoRa.sleep();
}

void loop()
{

LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);

  
 
  //Serial.println(hx711.read()/100);

  Serial.println(Read_Sensor());
  //Read_Sensor();
  //MessageReponse(DEVICE_ID,Level_water,5);
  delay(20);
 
}
