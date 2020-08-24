#include "Node.H"
Q2HX711 hx711(hx711_data_pin, hx711_clock_pin);
double Sensor_Data=0;
double Val_Calib=0;
double LEVEL_WATER=0;
char Count_send=0;
void setup()
{
 Serial.begin(9600);

 Val_Calib=Read_Sensor_t(60);
 Serial.println(Val_Calib);
setupLora();
LoRa.sleep();
}

void loop()
{
 
  


delay(20);
 if(reponse_publish==true)// nếu cờ gửi được bật thì Thiết bị gửi liên tục gói tin
    {
      while((reponse_publish==true)){
        
       MessageReponse(DEVICE_ID,random(0,120),random(0,6));
       Delay(2000,receiveLoRaMessage);// lắng nghe lệnh trong 2 giây
       Count_send++;
       if (Count_send>10)
          {
            reponse_publish=false;
            Count_send=0;
          }
      }
    }

  delay(200);
  LoRa.sleep();
  MCU_Sleep(3);
/*



 */

  
  //Sensor_Data=((Read_Sensor()-Val_Calib)/6925);
// digitalWrite(4,HIGH);
// delay(200);
// Val_Calib=Read_Sensor_t(60);
// Serial.println(Val_Calib);
// Sensor_Data=(Read_Sensor());
// LEVEL_WATER=((Sensor_Data-Val_Calib)/6910);
//  Serial.println((LEVEL_WATER));
// // digitalWrite(4,LOW);
 
}


void MCU_Sleep(int times)
{
  for(int i=0; i<times; i++) 
  {
    // Enter power down state for 8s with ADC and BOD module disabled
    LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);  
   if(i<(times-1)) reponse_publish=true;
  }
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Delay(float delayTime, void (func)())
{  Serial.println("Nhan du lieu");
    unsigned long endTime = millis() + delayTime;
    while(millis() < endTime)
    {
      func();
     
    }
}
