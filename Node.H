#include "LowPower.h"
#include <ArduinoJson.h>
const byte hx711_data_pin = A1;
const byte hx711_clock_pin = A0;

#define ScaleVolt 0.6791666
#define BAT_pin A7
float battery=0;
double Level_water=0;
char Max_Sample=10;
//=====================================================================================+
//                                                                                     |
//                                    Lora SET                                         |
//                                                                                     |
//=====================================================================================+
#include <SPI.h>
#include <LoRa.h>
// Lora Pin
#define SS 10
//#define RST 8
//#define DIO0 7
#define RST 9
#define DIO0 2
int DEVICE_ID=2;
// Lora Config Value
#define LORA_FREQ_TX 433E6
#define LORA_FREQ_RX 433E6
#define LORA_SF 7 // 7 is the fastest. 12 is is farthest
#define LORA_CR 5
long LORA_BW=500E3; // 41.7E3, 125E3, 62.5E3
#define LORA_PREAMBLE_LENGTH  8
#include <Q2HX711.h>

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

static bool reponse_publish = false;
