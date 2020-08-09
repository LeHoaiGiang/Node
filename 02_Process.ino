void MessageReponse(int myID, unsigned long watermetter,int battery)
{ 
  Serial.println("send reponse");
  String loraMessage ="";
  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();
  Serial.println("sendLoRaMessage");
  root["ID"] = DEVICE_ID;
  root["Level_water"] = watermetter;
  root["Pin"] = battery;
  root.printTo(loraMessage);
  Serial.println(loraMessage);
  sendLoRaMessage(string2Char(loraMessage));
}
char* string2Char(String str)
{
    if(str.length()!=0)
    {
        char *p = const_cast<char*>(str.c_str());
        return p;
    }
}
