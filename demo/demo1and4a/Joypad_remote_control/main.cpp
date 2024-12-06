#include "stm32f10x.h"                  // Device header
#include "os.h"
#include "stdio.h"
#include "misc.h"

void ADC_select(short X, short Y);

char msg[] = "0";
char msg_1[] = "^";
char msg_2[] = "V";
char msg_3[] = "<";
char msg_4[] = ">";
int top = 0;
int bottom = 0;
int left = 0;
int right = 0;
char buffer[50] = {'\0'};

int main(void)
{
	init();
	while(1)
	{
		ADC1->CR2 |= ADC_CR2_ADON; 
		
		if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_13) != 1)
		{
			//uart1_send(msg,sizeof(msg));
			uart3_send(0x40);
		}
		else if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_5) != 1)
		{
			//uart1_send(msg_1,sizeof(msg_1));
			uart3_send(0x50);
		}
		else if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_9) != 1)
		{
			//uart1_send(msg_2,sizeof(msg_2));
			uart3_send(0x60);
		}
		else if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_8) != 1)
		{
			//uart1_send(msg_3,sizeof(msg_3));
			uart3_send(0x40);
		}
		else if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_6) != 1)
		{
			//uart1_send(msg_4,sizeof(msg_4));
			uart3_send(0x40);
		}
		
		 ADC_select(getX(), getY());
		sprintf(buffer, "Voltage=%d X=%d Y=%d\r\n", getV(), getX(), getY()); // show data on tera term
		uart1_send(buffer, sizeof(buffer));
	}
}

void ADC_select(short X, short Y)
{
	if (X > 3000)
	{
		uart3_send(0x80);
	}
	else if (X < 1000)
	{
		uart3_send(0x90);
	}
	else if ( Y > 3000)
	{
		uart3_send(0xc0);
	}
	else if (Y < 1000)
	{
		uart3_send(0xd0);
	}
	else
	{
		uart3_send(0x40);
	}
}
