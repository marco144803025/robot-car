#include <stm32f10x.h>
#include "os.h"

unsigned char status = 0;

void __attribute__((weak)) on_buttons(char button) 
{		
	if (button == 0x50)
	{
		status = 1;
	}
	else if (button == 0x60)
	{
		status = 0;
	}
	else if (button == 0x40)
	{
		pwmLeft(0);
		pwmRight(0);
	}
}
void __attribute__((weak)) on_x(unsigned x) 
{
  if ((x == 0x80) && (status == 1))
	{
		wheel_forward_fast();
	}
	else if ((x == 0x90) && (status == 1))
	{
		wheel_backward_fast();
	}
	else if ((x == 0x80) && (status == 0))
	{
	 wheel_forward();
  }
	else if ((x == 0x90) && (status == 0))
	{
		wheel_backward();
	}
}
void __attribute__((weak)) on_y(unsigned y) 
{
	if ( y == 0xc0)
	{
		wheel_right();
	}
	else if ( y == 0xd0)
	{
		wheel_left();
	}
}

namespace {

const char *ptr;
unsigned x, y;
int iflag;
char buttons, byte;

}

bool uart2_print(const char* p) {
  if (ptr) return false;
  ptr = p;
  return (USART2->CR1 |= USART_CR1_TXEIE);  // ie return true
}

void loop_remote(void) {
  static int flag;
  int f = flag ^ iflag;
  if (!f) return;
  if (f & 1) { flag ^= 1; on_buttons(buttons); }
  if (f & 2) { flag ^= 2; on_x(x); }
  if (f & 4) { flag ^= 4; on_y(y); }
}

extern "C" void USART2_IRQHandler(void) {
  if (USART2->SR & USART_SR_TXE) {
    if (ptr) {
      if (*ptr) USART2->DR = *ptr++; else ptr = 0;
    } else USART2->CR1 &= ~USART_CR1_TXEIE;
  }
	
  if (USART2->SR & USART_SR_RXNE) {
    char c = USART2->DR;
    switch (c & 0xc0) {
      case 0x40: buttons = c; iflag ^= 1; break;
			case 0x50: buttons = c; iflag ^= 1; break;
			case 0x60: buttons = c; iflag ^= 1; break;
      case 0x80: x = c/*(c & 0x3f) << 6 | byte*/; iflag ^= 2; break;
			case 0x90: x = c; iflag ^= 2; break;
			case 0xa0: x = c; iflag ^= 2; break;
			case 0xb0: x = c; iflag ^= 2; break;
      case 0xc0: y = c/*(c & 0x3f) << 6 | byte*/; iflag ^= 4; break;
			case 0xd0: y = c; iflag ^= 4; break;
      default: pwmLeft(0); pwmRight(0); byte = c; 
    }
  }
	
}