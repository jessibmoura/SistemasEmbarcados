/*
Trabalho Final Compiladores

Alunas:
 Jessica Brito Moura
 Elizamara Almeida

*/


#include <Display74HC595.h>
#include <TimerOne.h>

int SCLK = 7;
int RCLK = 6;
int DIO = 5;

int i;
int start = 0;
int dig = 3;

Display74HC595 disp(SCLK, RCLK, DIO);
unsigned char LED_0F[16];

void setup() {
  LED_0F[0] = 0xC0; //0
  LED_0F[1] = 0xF9; //1
  LED_0F[2] = 0xA4; //2
  LED_0F[3] = 0xB0; //3
  LED_0F[4] = 0x99; //4
  LED_0F[5] = 0x92; //5
  LED_0F[6] = 0x82; //6
  LED_0F[7] = 0xF8; //7
  LED_0F[8] = 0x80; //8
  LED_0F[9] = 0x90; //9
  LED_0F[10] = 0x88; //A
  LED_0F[11] = 0x83; //b
  LED_0F[12] = 0xC6; //C
  LED_0F[13] = 0xA1; //d
  LED_0F[14] = 0x86; //E
  LED_0F[15] = 0x8E; //F

  
  Timer1.initialize(1500); // set a timer of length 1500
  Timer1.attachInterrupt(timerIsr); // attach the service routine here

}

void loop() {  

  /*
  disp.digit(LED_0F[1], 0);    //send digital "I" to 1st indicator
  disp.digit(LED_0F[0], 1);    //send digital "O" to 2nd indicator
  delay(1000);
  */
  showHexSequence();
  
}

void showHexSequence() {
  int vez = 0;
  while (1) {
    for (int i = vez; i < vez + 4; i++) {
      disp.digit(LED_0F[i % 16],3-(i-vez));
    }
    delay(1000); // Delay de 1 segundo
    vez = (vez + 1) % 16;
    if (vez == 13)
      vez = 14;
  }
}

void timerIsr()
{
  disp.timerIsr();
}

