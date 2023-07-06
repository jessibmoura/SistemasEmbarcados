/*
  Display74HC595.h - Library for use 4LED display with 2 TM74HC595.
  Created by Kostarev V., February 23, 2016.
  Updated and Altered by Jessica and Elizamara Almeida July 03, 2023
*/
#ifndef Display74HC595_h
#define Display74HC595_h
  
class Display74HC595
{
  public:
    Display74HC595(int SCLK, int RCLK, int DIO);
	void timerIsr();
        void send(unsigned char X);
	void digit(unsigned char valor, int display);
	void clear_all();
	void clear(int display);

  private:
    int _SCLK;
	int _RCLK;
	int _DIO;
	int _DATA[4];
};
 
#endif
