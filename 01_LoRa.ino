  void setupLora()
  {
  //  SPI.begin(SCK, MISO, MOSI, SS);
    LoRa.setPins(SS, RST, DIO0);
    if (!LoRa.begin(LORA_FREQ_RX))
    {
      Serial.println("Starting LoRa failed!");
      while (1);
    }
    LoRa.setSpreadingFactor(LORA_SF);
    LoRa.setCodingRate4(LORA_CR); //4/5
    LoRa.setSignalBandwidth(LORA_BW);
    LoRa.setPreambleLength(LORA_PREAMBLE_LENGTH);
    LoRa.setTxPower(20);
    LoRa.enableCrc();
    Serial.println("LoRa Node started");
    //LoRa.onReceive(receiveLoRaMessage);  
   // LoRa_rxMode();
  }
  
  
  //=======================================================================================================================
  //=======================================================================================================================
  //=======================================================================================================================

  //=======================================================================================================================
  //=======================================================================================================================
  void sendLoRaMessage(const char* outgoing)
  {
    
    LoRa.beginPacket();                   // start packet
    LoRa.print(outgoing);                 // add payload
    LoRa.endPacket(true);                 // More reliable for RPC, may corrupt packet
  }
  //=======================================================================================================================
  //=======================================================================================================================
  void receiveLoRaMessage()
  {
       int packetSize = LoRa.parsePacket();
      if (packetSize) 
      {
        String message = "";
        //  Serial.println(packetSize);
        while (LoRa.available())
          {
            message += (char)LoRa.read();
          }
        Serial.print("Received Lora message: "); 
        Serial.println(message);
    
        //   parseLoraMessage(message);
      processLoraMessage(message);
        //   processDownlinkMessage(string2Char(message));
      }
  
   }



  
