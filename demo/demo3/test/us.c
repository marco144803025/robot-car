#include "stm32f10x.h"
#include "stdbool.h"
#include "string.h"

#define PWM 0x6870
#define CAPTURE 0x6801
#define IDLE 0x6803
void wheelinit(void);
void ultrasoundinit(void);
void enableTimer1();
void disableTimer1();
int getdistance();
static __IO uint32_t msTicks;
void DelayMs(uint32_t ms);
void TIM1_CH3_CH3N_init(void);
void TIM1_CC_IRQHandler(void);
void TIM2_delay(unsigned short);
void Wheel(unsigned int left, unsigned int right);
void sr04(unsigned phase);
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


#define TRIG_PIN GPIO_Pin_0
#define TRIG_PORT GPIOA
#define ECHO_PIN GPIO_Pin_10
#define ECHO_PORT GPIOB

volatile uint32_t pulse_start_time = 0;
volatile uint32_t pulse_end_time = 0;
volatile uint8_t pulse_started = 0;

static unsigned distance;

unsigned getDistance(void) {
  return distance / 1050;
}

void sr04_interrupt(void) {
  if (TIM1->SR & TIM_SR_CC3IF) {
    distance = TIM1->CCR3;
    TIM1->SR &= ~TIM_SR_CC3IF;
  }
}


void init_gpio(void) {
  GPIO_InitTypeDef GPIO_InitStructure;

  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB, ENABLE);

  GPIO_InitStructure.GPIO_Pin = TRIG_PIN;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_Init(TRIG_PORT, &GPIO_InitStructure);

  GPIO_InitStructure.GPIO_Pin = ECHO_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
  GPIO_Init(ECHO_PORT, &GPIO_InitStructure);
}

unsigned int state=0;
char buffer[50] = {'\0'};
__IO bool pulseHigh = false;
__IO bool generate_pulse = true;
__IO u32 pulseWidth = 0;
__IO u32 captureValue = 0;

int main(void)
{
   	while(1)
	{
		enableTimer1();
		ultrasoundinit();
		distance = getdistance();
		disableTimer1();
		
		if (distance>(1000*50)){
		
		}else if((distance>(1000*50))){ Wheel(140,140);
		}else if((distance>(1000*20))){ Wheel(100,100);
		}else if((distance>(1000*10))){ Wheel(80,80);
		}else if((distance>(1000*5))){ Wheel(50,50);
		}else if((distance>(1000*2))){ Wheel(30,30);
		}else if((distance>(1000*0.5))){ Wheel(0,0);
		}
	}
}


void Wheel(unsigned int left, unsigned int right){
	//Enable Tim1 CH1 PWM PA8 PA13
			enabletimer1();
			wheelinit();
			TIM_OCInitTypeDef CH1;
			CH1.TIM_OCMode = TIM_OCMode_PWM1;
			CH1.TIM_Pulse =left;//
			CH1.TIM_OutputState = TIM_OutputState_Enable;
			CH1.TIM_OCPolarity = TIM_OCPolarity_High;
			//CH1.TIM_OCIdleState=TIM_OCIdleState_Reset;
			CH1.TIM_OutputNState = TIM_OutputNState_Disable;//N
			CH1.TIM_OCNPolarity = TIM_OCNPolarity_Low;//N
			//CH1.TIM_OCNIdleState=TIM_OCNIdleState_Reset;//N
			TIM_OC1Init(TIM1, &CH1);//PA8 
			
			TIM_OCInitTypeDef CH2;
			CH2.TIM_OCMode = TIM_OCMode_PWM1;
			CH2.TIM_Pulse =right;//
			CH2.TIM_OutputState = TIM_OutputState_Disable;
			CH2.TIM_OCPolarity = TIM_OCPolarity_Low;
			//CH2.TIM_OCIdleState=TIM_OCIdleState_Reset;
			CH2.TIM_OutputNState = TIM_OutputNState_Enable;//N
			CH2.TIM_OCNPolarity = TIM_OCNPolarity_High;//N
			//CH2.TIM_OCNIdleState=TIM_OCNIdleState_Reset;//N
			TIM_OC2Init(TIM1, &CH2);//PA9
			
			
			DelayMs(30);
			
			//Enable Tim1 CH1 PWM PA8 PA13
			CH1.TIM_OCMode = TIM_OCMode_PWM1;
			CH1.TIM_Pulse =0;//
			CH1.TIM_OutputState = TIM_OutputState_Enable;
			CH1.TIM_OCPolarity = TIM_OCPolarity_High;
			//CH1.TIM_OCIdleState=TIM_OCIdleState_Reset;
			CH1.TIM_OutputNState = TIM_OutputNState_Disable;//N
			CH1.TIM_OCNPolarity = TIM_OCNPolarity_Low;//N
			//CH1.TIM_OCNIdleState=TIM_OCNIdleState_Reset;//N
			TIM_OC1Init(TIM1, &CH1);//PA8 
			
			CH2.TIM_OCMode = TIM_OCMode_PWM1;
			CH2.TIM_Pulse =0;//
			CH2.TIM_OutputState = TIM_OutputState_Disable;
			CH2.TIM_OCPolarity = TIM_OCPolarity_Low;
			//CH2.TIM_OCIdleState=TIM_OCIdleState_Reset;
			CH2.TIM_OutputNState = TIM_OutputNState_Enable;//N
			CH2.TIM_OCNPolarity = TIM_OCNPolarity_High;//N
			//CH2.TIM_OCNIdleState=TIM_OCNIdleState_Reset;//N
			TIM_OC2Init(TIM1, &CH2);//PA9
			disabletimer1();
}

void wheelinit(void){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1,ENABLE);

  TIM_TimeBaseInitTypeDef timerInitStructure; 
  timerInitStructure.TIM_Prescaler = 720-1;//1/(72Mhz/720)=0.01ms=0.00001s
  timerInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
  timerInitStructure.TIM_Period = 200-1;//0.00001s*200=0.002s=1/500Hz
  timerInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
  timerInitStructure.TIM_RepetitionCounter = 0;
  TIM_TimeBaseInit(TIM1, &timerInitStructure);
  TIM_Cmd(TIM1, ENABLE);
	
	
	TIM_OC1PreloadConfig(TIM1,TIM_OCPreload_Enable);
	TIM_OC2PreloadConfig(TIM1,TIM_OCPreload_Enable);
	
  TIM_CtrlPWMOutputs(TIM1,ENABLE);
}




void ultrasoundinit(void){
	
}

void sr04(unsigned phase) {
  if (phase == 7) {
    if (TIM1->CCMR2 == CAPTURE) distance = 0;
    TIM1->CCER &= ~TIM_CCER_CC3E;     //disable capture 
    TIM1->CCR3 = 44820;               //10us
    TIM1->CCMR2 = PWM;
    TIM1->CCER |= TIM_CCER_CC3NE;     //enable o/p pin
  } else {
    if (!phase) {
      TIM1->CCER &= ~TIM_CCER_CC3NE;  //disable o/p pin
      TIM1->CCMR2 = CAPTURE;
      TIM1->CCER |= TIM_CCER_CC3E;    //enable capture 
      TIM1->SR &= ~TIM_SR_CC3IF;
    } else {
      if (TIM1->SR & TIM_SR_CC3IF) {
        distance = phase * 45000 + TIM1->CCR3;
        if (TIM1->CCR3 > TIM1->CNT) distance -= 45000;
        TIM1->SR &= ~TIM_SR_CC3IF;
        TIM1->CCER &= ~TIM_CCER_CC3E; //disable capture
        TIM1->CCMR2 = IDLE;
      }
    }
  }
}




// function to enable Timer 1
void enableTimer1()
{
  TIM1->CR1 |= TIM_CR1_CEN; // set the CEN bit in the Control Register 1 to enable the timer
}

// function to disable Timer 1
void disableTimer1()
{
  TIM1->CR1 &= ~(TIM_CR1_CEN); // clear the CEN bit in the Control Register 1 to disable the timer
}

void DelayMs(uint32_t ms)
{
	// Reload ms value
	msTicks = ms;
	// Wait until msTick reach zero
	while (msTicks);
}

// SysTick_Handler function will be called every 1 ms
void SysTick_Handler()
{
	if (msTicks != 0)
	{
		msTicks--;
	}
}

