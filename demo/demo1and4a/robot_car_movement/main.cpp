#include "stm32f10x.h"                  // Device header
#include "os.h"
#include "stdio.h"
#include "misc.h"

void left_wheel_forward(void);
void Right_wheel_forward(void);
void left_wheel_backward(void);
void Right_wheel_backward(void);

char buffer[] = {"Yes"};
	
int main()
{
	init();
	while(1)
	{
		loop_remote();
	}
	
	
}

void left_wheel_forward(void) // ok
{
	pwmLeft(13000);
	pwmRight(0);
	dirLeft(true);
	dirRight(true);
	
}

void Right_wheel_forward(void) // ok
{
	pwmLeft(0);
	pwmRight(13000);
	dirLeft(true);
	dirRight(true);
	
}

void left_wheel_backward(void) // ok
{
	pwmLeft(13000);
	pwmRight(5000);
	dirLeft(false);
	dirRight(false);
}

void Right_wheel_backward(void) // ok
{
	pwmLeft(5000);
	pwmRight(13000);
	dirLeft(false);
	dirRight(false);
}

void wheel_forward(void)
{
	pwmLeft(14000); // 9000 passed
	pwmRight(11000); // 8000 not passed
	dirLeft(true);
	dirRight(true);
}

void wheel_backward(void)
{
	pwmLeft(14000);
	pwmRight(11000);
	dirLeft(false);
	dirRight(false);
}

void wheel_left (void)
{
	pwmLeft(10000);
	pwmRight(16000);
	dirLeft(true);
	dirRight(true);
}

void wheel_right (void)
{
	pwmLeft(18000); // fastMode: left:13000 right:15000
	pwmRight(8000);
	dirLeft(true);
	dirRight(true);
}

void wheel_forward_fast(void)
{
	pwmLeft(20000); // 9000 passed
	pwmRight(16000); // 8000 not passed
	dirLeft(true);
	dirRight(true);
}

void wheel_backward_fast(void)
{
	pwmLeft(20000);
	pwmRight(17000);
	dirLeft(false);
	dirRight(false);
}
	