#include "heltec.h" 
#include "string.h"
#include "SoftwareSerial.h"
#define BAND    433E6  //LoRa频段
SoftwareSerial mySerial2(38,39);//GPS模块在38、39GPIO端口输出数据

void setup()
{
  delay(2000);
  //打开串口
  Serial.begin(9600);
  Serial.println();
  //打开GPS模块GPIO端口
  mySerial2.begin(9600);
  Heltec.begin(true /*DisplayEnable Enable*/, true /*Heltec.LoRa Disable*/, true /*Serial Enable*/, true /*PABOOST Enable*/, BAND /*long BAND*/);
}

void loop()
{
String gps = ""; 
   while (mySerial2.available() > 0)
  { 
    byte gpsData = mySerial2.read(); 
    //向串口发送GPS数据
    Serial.write(gpsData); 
      // send packet
    gps += (char)gpsData;
  }
  //在LORA32模块的OLED显示屏上显示
    Heltec.display->clear();
    Heltec.display->setTextAlignment(TEXT_ALIGN_LEFT);
    Heltec.display->setFont(ArialMT_Plain_10);
    Heltec.display->drawString(0, 0, gps);  
    Heltec.display->display();
  
  //通过LoRa发送到Receiver
    LoRa.beginPacket();
    LoRa.setTxPower(14,RF_PACONFIG_PASELECT_PABOOST);
    LoRa.print(gps);
    LoRa.endPacket();
  
  delay(1500);
}
