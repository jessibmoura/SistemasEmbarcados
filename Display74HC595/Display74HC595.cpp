/*
  Display74HC595.cpp - Library
  Altered by Jessica Brito and Elizamara Almeida July 03, 2023
*/

#include "Display74HC595.h"
#include <Arduino.h>

unsigned char _LED_0F[16];
   
Display74HC595::Display74HC595(int SCLK, int RCLK, int DIO)
{
  pinMode(SCLK, OUTPUT);
  pinMode(RCLK, OUTPUT);
  pinMode(DIO, OUTPUT);
    
  _SCLK = SCLK;
  _RCLK = RCLK;
  _DIO = DIO;
  
  _LED_0F[0] = 0xC0; //0
  _LED_0F[1] = 0xF9; //1
  _LED_0F[2] = 0xA4; //2
  _LED_0F[3] = 0xB0; //3
  _LED_0F[4] = 0x99; //4
  _LED_0F[5] = 0x92; //5
  _LED_0F[6] = 0x82; //6
  _LED_0F[7] = 0xF8; //7
  _LED_0F[8] = 0x80; //8
  _LED_0F[9] = 0x90; //9

  _LED_0F[10] = 0x88; //A
  _LED_0F[11] = 0x83; //b
  _LED_0F[12] = 0xC6; //C
  _LED_0F[13] = 0xA1; //d
  _LED_0F[14] = 0x86; //E
  _LED_0F[15] = 0x8E; //F
  
  clear_all();
}

void Display74HC595::clear_all(){
  _DATA[0]= 0xFF;
  _DATA[1]= 0xFF;
  _DATA[2]= 0xFF;
  _DATA[3]= 0xFF;
}

void Display74HC595::clear(int display){
  if (display >= 0 && display < 4){
    _DATA[display] = 0xFF;
  }
}

void Display74HC595::timerIsr()
{
  send(_DATA[0]);
  send(0b0001);
  digitalWrite(_RCLK, LOW);
  digitalWrite(_RCLK, HIGH);
  send(_DATA[1]);
  send(0b0010);
  digitalWrite(_RCLK, LOW);
  digitalWrite(_RCLK, HIGH);
  send(_DATA[2]);
  send(0b0100);
  digitalWrite(_RCLK, LOW);
  digitalWrite(_RCLK, HIGH);
  send(_DATA[3]);
  send(0b1000);
  digitalWrite(_RCLK, LOW);
  digitalWrite(_RCLK, HIGH);
}


void Display74HC595::send(unsigned char X)
{

  for (int i = 8; i >= 1; i--)
  {
    if (X & 0x80)
    {
      digitalWrite(_DIO, HIGH);
    }
    else
    {
      digitalWrite(_DIO, LOW);
    }
    X <<= 1;
    digitalWrite(_SCLK, LOW);
    digitalWrite(_SCLK, HIGH);  
  }
}

void Display74HC595::send(unsigned char X, unsigned char port)
{
  send(X);
  send(port);
  digitalWrite(_RCLK, LOW);
  digitalWrite(_RCLK, HIGH);
}

void Display74HC595::digit(unsigned char valor, int display){ //coloca o valor para exibir no display escolhido (opção entre 0 e 4)
  if (display >= 0 && display < 4){
    _DATA[display] = valor;
  }
}






