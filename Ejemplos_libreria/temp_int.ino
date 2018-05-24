#include "NXTIoT_dev.h"

NXTIoT_dev  mysigfox;

const int boton=6;
const int sensorPin = A0;

void setup() 
{
  Serial.begin(9600);
  pinMode(boton, INPUT);
}

void leer_distancia()
{
  int sensorVal=analogRead(sensorPin);
  float voltaje=(sensorVal/1024.0)*5;
  Serial.print("Voltaje: ");
  Serial.println(voltaje); 
  Serial.print("Grados Cº: ");
  int temp=((voltaje)*100);
  Serial.println(temp);
  mysigfox.initpayload();
  mysigfox.addint(temp);
  mysigfox.sendmessage();
}

void loop() 
{
  if (digitalRead(boton)==LOW)
  {
    leer_distancia();
    delay(1000);
  } 
}
