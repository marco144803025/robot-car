#include <stdio.h>

char SPI_data = 0;

void wait(unsigned int);   //background jobs are being serviced through this function
unsigned int getADC(void);
char getPath(void);
unsigned int getLeft(void);
unsigned int getRight(void);
void pwmLeft(unsigned int);
void pwmRight(unsigned int);
void setLeft(bool);
void setRight(bool);
int getDistance(void);

enum led_state { ON, OFF, NORMAL, FAST, SLOW };
enum led_color { BLUE, GREEN, YELLOW };
void led(led_color, led_state);

bool uart2_print(const char*);
bool uart3_print(const char*);
int uart2_read(void);          //return -1 for none
int uart3_read(void);

char buffer[30];
int rx;
unsigned int pwm;
int forward = 1;
int back = 0;

int distance = 0;

int main(void) {

  while (1) {
    wait(40);
		char c = getPath();

    sprintf(buffer, "\r0123 4567   distance=%d   ", getDistance());
		buffer[1] = c & 1? '0' : '.';
		buffer[2] = c & 2? '0' : '.';
		buffer[3] = c & 4? '0' : '.';
		buffer[4] = c & 8? '0' : '.';
		buffer[6] = c & 16? '0' : '.';
		buffer[7] = c & 32? '0' : '.';
		buffer[8] = c & 64? '0' : '.';
		buffer[9] = c & 128? '0' : '.';
    uart3_print(buffer);
		
		distance = getDistance();
		
		if (distance > 43) {
			
			pwmLeft(10000); pwmRight(10000);
			setLeft(forward);
			setRight(forward);
			
		} 
		if (distance < 43 & distance > 35) {
			
			pwmLeft(10000); pwmRight(10000);
			setLeft(forward);
			setRight(forward);
		
		} else if (distance < 35 & distance > 25) {
			
			pwmLeft(9500); pwmRight(9500);
			setLeft(forward);
			setRight(forward);
			
		} else if (distance < 25 & distance > 20) {
			
			pwmLeft(7800); pwmRight(7800);
			setLeft(forward);
			setRight(forward);
			
		} else if (distance < 20 & distance > 15) {
			
			pwmLeft(5500); pwmRight(5500);
			setLeft(forward);
			setRight(forward);
			
		} else if (distance < 15 & distance > 12) {
			
			pwmLeft(4200); pwmRight(4200);
			setLeft(forward);
			setRight(forward);
			
		}	else if (distance < 12 & distance > 8) {
			
			pwmLeft(0); pwmRight(0);
			setLeft(forward);
			setRight(forward);
			
		} else if (distance < 8) {
			pwm = 0;
			pwmLeft(pwm); pwmRight(pwm);
			setLeft(back);
			setRight(back);
		}
  }
}

void on_button(bool b) {
  //static int state;
	//unsigned int pwm = 15000;
	/*
  if (b) {
		pwmLeft(pwm); pwmRight(pwm);
    setLeft(2);
    setRight(2);
		*/
		/*
		++state;
		
		if (state > 2) {
			state = 0;
		}
		if (state == 0) {
			pwm = 10000;
			pwmLeft(pwm); pwmRight(pwm);
			setLeft(state);
			setRight(state);

		}
		
		if (state == 1 && state > 0) {
			pwm = 10000;
			pwmLeft(pwm); pwmRight(pwm);
			setLeft(state);
			setRight(state);

		}
		if (state == 2 && state > 0) {
			pwm = 0;
			pwmLeft(pwm); pwmRight(pwm);
			setLeft(state);
			setRight(state);
		}
		*/

    //if (++state > 2) state = 0;
    //unsigned int pwm = state == 2 ? 0 : 10000;
    //pwmLeft(pwm); pwmRight(pwm);
    //setLeft(state);
    //setRight(state);
  //}
}
