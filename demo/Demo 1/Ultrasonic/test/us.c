#include "stm32f10x.h"
#include "stdbool.h"
#include "string.h"


static int a=0;
void TIM1_CH3_CH3N_init(void);
void USART3_init(void);
void USARTSend(char*, unsigned long);
void TIM1_CC_IRQHandler(void);
void TIM2_delay(unsigned short);
void TIM2_delay(unsigned short period)
{
 	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
  	TIM_TimeBaseInitTypeDef initStructure;
  	initStructure.TIM_Prescaler = 7200; // 1(72MHz/72000) = 0.1ms
  	initStructure.TIM_CounterMode = TIM_CounterMode_Up;
  	initStructure.TIM_Period = period; // 1us*period = delay us
  	initStructure.TIM_ClockDivision = 0;
  	initStructure.TIM_RepetitionCounter = 0;
  	TIM_TimeBaseInit(TIM2, &initStructure);
  	TIM_Cmd(TIM2, ENABLE);
  	TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
}


// TIM1 Channel 3 and Channel 3N initialization8
void TIM1_CH3_CH3N_init()
{
  	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
  	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
  
  	// config TIM1 CH3 I/O
  	// echo inpute capture
  	GPIO_InitTypeDef init_gpio;//ECHOOOOOOOOOOOOOOOOOOOOOOOOOO
  	init_gpio.GPIO_Mode = GPIO_Mode_IPD; // the mode is not AF_PP
  	init_gpio.GPIO_Pin = GPIO_Pin_10; // TIM1 CH3 pin
  	init_gpio.GPIO_Speed = GPIO_Speed_50MHz;
  	GPIO_Init(GPIOA, &init_gpio);
  
  	//set TIM1 in 1000Hz
  	//pulse range: 0 to 1000
  	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);
  
  	// 1ms per cycle, 1000Hz
  	TIM_TimeBaseInitTypeDef timerInitStructure;
		timerInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
		timerInitStructure.TIM_CounterMode = TIM_CounterMode_Up;	
  	timerInitStructure.TIM_Prescaler = 72-1; // 1(72MHz/72) = 1us, 72
		timerInitStructure.TIM_Period = 10000-1; // 1us*10000 = 10ms, 10000
		timerInitStructure.TIM_RepetitionCounter = 0;
		TIM_TimeBaseInit(TIM1, &timerInitStructure);
		TIM_Cmd(TIM1, ENABLE);
 
  	//enable TIM1 CH3 Input Capture
  	TIM_ICInitTypeDef inputCapture_init;
		inputCapture_init.TIM_Channel = TIM_Channel_3; //seclect IC1
		inputCapture_init.TIM_ICPolarity = TIM_ICPolarity_Rising; //capture rising edge
		inputCapture_init.TIM_ICSelection = TIM_ICSelection_DirectTI; //map to TI3
		inputCapture_init.TIM_ICPrescaler = TIM_ICPSC_DIV1; //configure input frequency
		inputCapture_init.TIM_ICFilter = 0; //no filter
		TIM_ICInit(TIM1, &inputCapture_init);
  
	//enable input capture interrput
		NVIC_InitTypeDef nvic_init;
		nvic_init.NVIC_IRQChannel = TIM1_CC_IRQn; //TIM1 capture compare interrput
	//preemptive priority level 2
		nvic_init.NVIC_IRQChannelPreemptionPriority = 2;
	//from the priority level 0
		nvic_init.NVIC_IRQChannelSubPriority = 0;
	//the IRQ channel is enabled
		nvic_init.NVIC_IRQChannelCmd = ENABLE;
		NVIC_Init(&nvic_init);
	//allow update to interrput, allows the CC3IE to capture interrput
		TIM_ITConfig(TIM1, TIM_IT_Update|TIM_IT_CC3, ENABLE);
}

// Enable USART2 to show the measurement
void USART3_init(void)
{
  	//USART1 TX RX
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_AFIO, ENABLE);
  
  	//TX pin, PB10
  	GPIO_InitTypeDef gpio_init;
  	gpio_init.GPIO_Pin = GPIO_Pin_10;
  	gpio_init.GPIO_Speed = GPIO_Speed_50MHz;
  	gpio_init.GPIO_Mode = GPIO_Mode_AF_PP;
  	GPIO_Init(GPIOB, &gpio_init);
  
  	//RX pin, PB11
  	gpio_init.GPIO_Pin = GPIO_Pin_11;
  	gpio_init.GPIO_Mode = GPIO_Mode_IN_FLOATING;
  	GPIO_Init(GPIOB, &gpio_init);
  
  	//USART2 ST-LINK USB
  	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3,ENABLE);
  
  	USART_InitTypeDef usart_init;
  	usart_init.USART_BaudRate = 9600;
  	usart_init.USART_WordLength = USART_WordLength_8b;
  	usart_init.USART_StopBits = USART_StopBits_1;
  	usart_init.USART_Parity = USART_Parity_No;
  	usart_init.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
  	usart_init.USART_Mode = USART_Mode_Rx |USART_Mode_Tx;
  
  	USART_Init(USART3, &usart_init);
  	USART_Cmd(USART3,ENABLE);
}

// use polling to send out a string through USART2
void USARTSend(char *pucBuffer, unsigned long ulCount)
{
  	//loop until the whole string is sent
  	while(ulCount--)
	{
    		USART_SendData(USART3, *pucBuffer++);
    		/* loop until the end of transmission */
    		while(USART_GetFlagStatus(USART3, USART_FLAG_TC) == RESET)
		{
    		}
  	}
}

char buffer[50] = {'\0'};
__IO bool pulseHigh = false;
__IO bool generate_pulse = true;
__IO u32 pulseWidth = 0;
__IO u32 captureValue = 0;
__IO u32 distance = 0;

int main(void)
{
  	TIM1_CH3_CH3N_init();
  	USART3_init();
  	//pulse_generate(10);
		TIM2_delay(10);
  	// config TIM1 CH3N I/O (PB15) BUT do not enable TIM1 CH3N	
	 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
		GPIO_InitTypeDef init_gpio;
  	init_gpio.GPIO_Mode = GPIO_Mode_Out_PP;
  	init_gpio.GPIO_Pin = GPIO_Pin_15;
  	init_gpio.GPIO_Speed = GPIO_Speed_2MHz;
  	GPIO_Init(GPIOB, &init_gpio);

   	while(1)
	{
		//generate a pulse to PB15 (TIM1_CH3N)
		//10us to trigger**
		GPIO_SetBits(GPIOB, GPIO_Pin_15);
		TIM2_delay(10);
		GPIO_ResetBits(GPIOB, GPIO_Pin_15);
		//you can use a timer and GPIO to generate the pulse
  }
}

// Get the measurement from the ultrasonic sensor
void TIM1_CC_IRQHandler(void)
{
    	if(TIM_GetITStatus(TIM1, TIM_IT_CC3) != RESET)
	{
      		if(!pulseHigh)
		{
        		pulseHigh = true;   //pulse starts
        		TIM_SetCounter(TIM1, 0);
		        //change to detect the falling edge
        		TIM_OC3PolarityConfig(TIM1, TIM_ICPolarity_Falling);
	      	}
		else
		{
        		pulseWidth += TIM_GetCounter(TIM1);
        		captureValue = pulseWidth;
			// output an integer only not a floating point number
			// very similar to captureValue/2*330/1000000
        		distance = (captureValue/2)/30; // in cm
						
						
        		sprintf(buffer, "%d\r\n", distance);
        		USARTSend(buffer, sizeof(buffer));
        
        		//change to detect the rising edge
	        	TIM_OC3PolarityConfig(TIM1, TIM_ICPolarity_Rising);
		        pulseHigh = false;
		        pulseWidth = 0;
	      	}
    	}
	//clear interrupt flag
  	TIM_ClearITPendingBit(TIM1, TIM_IT_Update|TIM_IT_CC3);
}
