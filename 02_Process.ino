
void processLoraMessage(String message)
{
  StaticJsonBuffer<500> jsonBuffer;
  JsonObject& root = jsonBuffer.parseObject(message);
  
  // Test if parsing succeeds.
  if (!root.success())
    {
    Serial.println("Failed to parse Lora message");
    return;
    }
  int request_id = root["id"];
  String cmd = root["cmd"];
    
      if((request_id==DEVICE_ID)&&(cmd=="STOP"))
  {
    reponse_publish=false;
  }

}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void MessageReponse(int myID, unsigned long watermetter,int battery)
{ 
  Serial.println("send reponse");
  String loraMessage ="";
  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();
  Serial.println("sendLoRaMessage");
  root["ID"] = DEVICE_ID;
  root["Level_Water"] = watermetter;
  root["Volt"] = battery;
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
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
