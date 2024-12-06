///*log
//Tested USART3 and successfully send out character
//SPI2.c change the char c in unsigned
//SPI2.c change all PB13 to PA5,PB15 to PA7
//SPI2.c change SPI2 to SPI1 
//SPI2.c change RCC_APB1ENR_SPI2EN to RCC_APB2ENR_SPI1EN



//*/
//#include "stm32f10x.h"                  // Device header
//#include "stdio.h"
//#include "misc.h"
//unsigned char state=0;
//unsigned char c;
//static __IO uint32_t msTicks;
//void DelayMs(uint32_t ms);
//unsigned char character;
//unsigned char led8bit=1;
//void readFloor();
//char buffer[] = {"Yes"};
//int count = 0;
//int repeat = 0;
//static int PWMmode=0;
//void PWMODE(void);
//static unsigned int pwm_left;
//static unsigned int pwm_right;

//void pwm(unsigned int l, unsigned int r){
//    pwm_left=l;
//    pwm_right=r;
//}
//int main(void)
//{
//	// Update SystemCoreClock value
//	SystemCoreClockUpdate();
//	
//	// Configure the SysTick timer to overflow every 1 ms
//	SysTick_Config(SystemCoreClock / 1000);

//	// Setup PA5 and PA7
//	// PA5 = SPI1_SCK, PA7 = IR LED / MODE
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
//	GPIO_InitTypeDef GPIO_InitStructure;
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
//	GPIO_Init(GPIOA, &GPIO_InitStructure);
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7|GPIO_Pin_4;
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
//	GPIO_Init(GPIOA, &GPIO_InitStructure);
//	
//	//GPIO_WriteBit(GPIOA, GPIO_Pin_4, Bit_SET);
//	
//	RCC_APB2PeriphClockCmd(RCC_APB2ENR_SPI1EN, ENABLE);

//	SPI_InitTypeDef   SPI_InitStructure;
//	SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
//  SPI_InitStructure.SPI_Mode = SPI_Mode_Master;
//  SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;
//  SPI_InitStructure.SPI_CPOL = SPI_CPOL_High;
//  SPI_InitStructure.SPI_CPHA = SPI_CPHA_2Edge;
//  SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;
//  // 36 MHz / 256 = 140.625 kHz
//  SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_256;
//  SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;
//  SPI_Init(SPI1, &SPI_InitStructure);
//	// Enable the receive interrupt
//	SPI_I2S_ITConfig(SPI1, SPI_I2S_IT_RXNE, ENABLE);
//  // Enable SPI1
//  SPI_Cmd(SPI1, ENABLE);
//	
//	// Enable USART3 and GPIOB clocks
//  RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3, ENABLE);
//  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
//	
//	// Configure PB10 and PB11 as USART3 pins
//  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
//  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
//  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//  GPIO_Init(GPIOB, &GPIO_InitStructure);

//  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
//  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
//  GPIO_Init(GPIOB, &GPIO_InitStructure);

//  // Initialize USART3
//	USART_InitTypeDef USART_InitStructure;
//  USART_InitStructure.USART_BaudRate = 9600;
//  USART_InitStructure.USART_WordLength = USART_WordLength_8b;
//  USART_InitStructure.USART_StopBits = USART_StopBits_1;
//  USART_InitStructure.USART_Parity = USART_Parity_No;
//  USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
//  USART_InitStructure.USART_Mode = USART_Mode_Tx;
//  USART_Init(USART3, &USART_InitStructure);
//	
//	// Enable USART2 and GPIOA clocks
//  RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);
//  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
//	
//	// Configure PA2 and PA3 as USART3 pins
//  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
//  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
//  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//  GPIO_Init(GPIOA, &GPIO_InitStructure);

//  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
//  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
//  GPIO_Init(GPIOA, &GPIO_InitStructure);
//	
//	
//	USART_InitStructure.USART_BaudRate = 115200;
//  USART_InitStructure.USART_WordLength = USART_WordLength_8b;
//  USART_InitStructure.USART_StopBits = USART_StopBits_1;
//  USART_InitStructure.USART_Parity = USART_Parity_No;
//  USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
//  USART_InitStructure.USART_Mode = USART_Mode_Tx;
//  USART_Init(USART2, &USART_InitStructure);

//  // Enable USART2,USART23
//  USART_Cmd(USART3, ENABLE);
//	USART_Cmd(USART2, ENABLE);
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOB, ENABLE);
//	//GPIO set up for PA8(green) PA9(blue) PA10(red) 
//	//GPIO_InitTypeDef GPIO_InitStructure;
//	GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_8|GPIO_Pin_9;
//  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
//  GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF_PP;
//	GPIO_Init(GPIOA, &GPIO_InitStructure);
//	//GPIO set up for PB13 
//	GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_13|GPIO_Pin_14;
//  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
//  GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF_PP;
//	GPIO_Init(GPIOB, &GPIO_InitStructure);
//	//PB6 LED
//	GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_6;
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
//	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_Out_PP;
//	GPIO_Init(GPIOB, &GPIO_InitStructure);	
//	
//	//Timer 1 set up 
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1,ENABLE);

//  TIM_TimeBaseInitTypeDef timerInitStructure; 
//  timerInitStructure.TIM_Prescaler = 720-1;//1/(72Mhz/720)=0.01ms=0.00001s
//  timerInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
//  timerInitStructure.TIM_Period = 200-1;//0.00001s*200=0.002s=1/500Hz
//  timerInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
//  timerInitStructure.TIM_RepetitionCounter = 0;
//  TIM_TimeBaseInit(TIM1, &timerInitStructure);
//  TIM_Cmd(TIM1, ENABLE);
//	
//	

//	
//	
//	TIM_OC1PreloadConfig(TIM1,TIM_OCPreload_Enable);
//	TIM_OC2PreloadConfig(TIM1,TIM_OCPreload_Enable);
//	
//  TIM_CtrlPWMOutputs(TIM1,ENABLE);
//	
//	while(1)
//	{
//		readFloor();
//		DelayMs(3);//can not too fast, maybe need to clear some flag
//		if(PWMmode==2)//_____________________________________________________________forward
//		{
//			//Enable Tim1 CH1 PWM PA8 PA13
//			TIM_OCInitTypeDef CH1;
//			CH1.TIM_OCMode = TIM_OCMode_PWM1;
//			CH1.TIM_Pulse =50;//
//			CH1.TIM_OutputState = TIM_OutputState_Enable;
//			CH1.TIM_OCPolarity = TIM_OCPolarity_High;
//			//CH1.TIM_OCIdleState=TIM_OCIdleState_Reset;
//			CH1.TIM_OutputNState = TIM_OutputNState_Disable;//N
//			CH1.TIM_OCNPolarity = TIM_OCNPolarity_Low;//N
//			//CH1.TIM_OCNIdleState=TIM_OCNIdleState_Reset;//N
//			TIM_OC1Init(TIM1, &CH1);//PA8 
//			
//			TIM_OCInitTypeDef CH2;
//			CH2.TIM_OCMode = TIM_OCMode_PWM1;
//			CH2.TIM_Pulse =52;//
//			CH2.TIM_OutputState = TIM_OutputState_Disable;
//			CH2.TIM_OCPolarity = TIM_OCPolarity_Low;
//			//CH2.TIM_OCIdleState=TIM_OCIdleState_Reset;
//			CH2.TIM_OutputNState = TIM_OutputNState_Enable;//N
//			CH2.TIM_OCNPolarity = TIM_OCNPolarity_High;//N
//			//CH2.TIM_OCNIdleState=TIM_OCNIdleState_Reset;//N
//			TIM_OC2Init(TIM1, &CH2);//PA9
//			
//			
//			DelayMs(200);
//			
//			//Enable Tim1 CH1 PWM PA8 PA13
//			CH1.TIM_OCMode = TIM_OCMode_PWM1;
//			CH1.TIM_Pulse =0;//
//			CH1.TIM_OutputState = TIM_OutputState_Enable;
//			CH1.TIM_OCPolarity = TIM_OCPolarity_High;
//			//CH1.TIM_OCIdleState=TIM_OCIdleState_Reset;
//			CH1.TIM_OutputNState = TIM_OutputNState_Disable;//N
//			CH1.TIM_OCNPolarity = TIM_OCNPolarity_Low;//N
//			//CH1.TIM_OCNIdleState=TIM_OCNIdleState_Reset;//N
//			TIM_OC1Init(TIM1, &CH1);//PA8 
//			
//			CH2.TIM_OCMode = TIM_OCMode_PWM1;
//			CH2.TIM_Pulse =0;//
//			CH2.TIM_OutputState = TIM_OutputState_Disable;
//			CH2.TIM_OCPolarity = TIM_OCPolarity_Low;
//			//CH2.TIM_OCIdleState=TIM_OCIdleState_Reset;
//			CH2.TIM_OutputNState = TIM_OutputNState_Enable;//N
//			CH2.TIM_OCNPolarity = TIM_OCNPolarity_High;//N
//			//CH2.TIM_OCNIdleState=TIM_OCNIdleState_Reset;//N
//			TIM_OC2Init(TIM1, &CH2);//PA9
//		
//			
//			PWMmode=-1;
//		}
//		if(PWMmode==3)//_____________________________________________________________backward
//		{
//			//Enable Tim1 CH1 PWM PA8 PA13
//			TIM_OCInitTypeDef DCH1;
//			DCH1.TIM_OCMode = TIM_OCMode_PWM1;
//			DCH1.TIM_Pulse =188;//
//			DCH1.TIM_OutputState = TIM_OutputState_Disable;
//			DCH1.TIM_OCPolarity = TIM_OCPolarity_Low;
//			//DCH2.TIM_OCIdleState=TIM_OCIdleState_Reset;
//			DCH1.TIM_OutputNState = TIM_OutputNState_Enable;//N
//			DCH1.TIM_OCNPolarity = TIM_OCNPolarity_High;//N
//			//DCH2.TIM_OCNIdleState=TIM_OCNIdleState_Reset;//N
//			TIM_OC1Init(TIM1, &DCH1);//PB13 CH1N
//			
//			TIM_OCInitTypeDef DCH2;
//			DCH2.TIM_OCMode = TIM_OCMode_PWM1;
//			DCH2.TIM_Pulse =188;//
//			DCH2.TIM_OutputState = TIM_OutputState_Enable;
//			DCH2.TIM_OCPolarity = TIM_OCPolarity_High;
//			//DCH2.TIM_OCIdleState=TIM_OCIdleState_Reset;
//			DCH2.TIM_OutputNState = TIM_OutputNState_Disable;//N
//			DCH2.TIM_OCNPolarity = TIM_OCNPolarity_Low;//N
//			//DCH2.TIM_OCNIdleState=TIM_OCNIdleState_Reset;//N
//			TIM_OC2Init(TIM1, &DCH2);//PA9 CH2
//		
//			DelayMs(200);
//			
//			//Enable Tim1 CH1 PWM PA8 PA13
//			DCH1.TIM_OCMode = TIM_OCMode_PWM1;
//			DCH1.TIM_Pulse =0;//
//			DCH1.TIM_OutputState = TIM_OutputState_Enable;
//			DCH1.TIM_OCPolarity = TIM_OCPolarity_High;
//			//DCH1.TIM_OCIdleState=TIM_OCIdleState_Reset;
//			DCH1.TIM_OutputNState = TIM_OutputNState_Disable;//N
//			DCH1.TIM_OCNPolarity = TIM_OCNPolarity_Low;//N
//			//DCH1.TIM_OCNIdleState=TIM_OCNIdleState_Reset;//N
//			TIM_OC1Init(TIM1, &DCH1);//PA8 
//			
//			DCH2.TIM_OCMode = TIM_OCMode_PWM1;
//			DCH2.TIM_Pulse =0;//
//			DCH2.TIM_OutputState = TIM_OutputState_Disable;
//			DCH2.TIM_OCPolarity = TIM_OCPolarity_Low;
//			//DCH2.TIM_OCIdleState=TIM_OCIdleState_Reset;
//			DCH2.TIM_OutputNState = TIM_OutputNState_Enable;//N
//			DCH2.TIM_OCNPolarity = TIM_OCNPolarity_High;//N
//			//DCH2.TIM_OCNIdleState=TIM_OCNIdleState_Reset;//N
//			TIM_OC2Init(TIM1, &DCH2);//PA9
//		
//		
//			PWMmode=-1;
//		}
//		if(PWMmode==4)//_____________________________________________________________LEFT
//		{
//			//Enable Tim1 CH1 PWM PA8 PA13
//			TIM_OCInitTypeDef CH1;
//			CH1.TIM_OCMode = TIM_OCMode_PWM1;
//			CH1.TIM_Pulse = 70;//b4 65
//			CH1.TIM_OutputState = TIM_OutputState_Enable;
//			CH1.TIM_OCPolarity = TIM_OCPolarity_High;
//			//CH1.TIM_OCIdleState=TIM_OCIdleState_Reset;
//			CH1.TIM_OutputNState = TIM_OutputNState_Disable;//N
//			CH1.TIM_OCNPolarity = TIM_OCNPolarity_Low;//N
//			//CH1.TIM_OCNIdleState=TIM_OCNIdleState_Reset;//N
//			TIM_OC1Init(TIM1, &CH1);//PA8 
//			
//			TIM_OCInitTypeDef CH2;
//			CH2.TIM_OCMode = TIM_OCMode_PWM1;
//			CH2.TIM_Pulse = 87;//
//			CH2.TIM_OutputState = TIM_OutputState_Disable;
//			CH2.TIM_OCPolarity = TIM_OCPolarity_Low;
//			//CH2.TIM_OCIdleState=TIM_OCIdleState_Reset;
//			CH2.TIM_OutputNState = TIM_OutputNState_Enable;//N
//			CH2.TIM_OCNPolarity = TIM_OCNPolarity_High;//N
//			//CH2.TIM_OCNIdleState=TIM_OCNIdleState_Reset;//N
//			TIM_OC2Init(TIM1, &CH2);//PA9
//			
//			
//			DelayMs(10);
//			
//			//Enable Tim1 CH1 PWM PA8 PA13
//			CH1.TIM_OCMode = TIM_OCMode_PWM1;
//			CH1.TIM_Pulse =0;//
//			CH1.TIM_OutputState = TIM_OutputState_Enable;
//			CH1.TIM_OCPolarity = TIM_OCPolarity_High;
//			//CH1.TIM_OCIdleState=TIM_OCIdleState_Reset;
//			CH1.TIM_OutputNState = TIM_OutputNState_Disable;//N
//			CH1.TIM_OCNPolarity = TIM_OCNPolarity_Low;//N
//			//CH1.TIM_OCNIdleState=TIM_OCNIdleState_Reset;//N
//			TIM_OC1Init(TIM1, &CH1);//PA8 
//			
//			CH2.TIM_OCMode = TIM_OCMode_PWM1;
//			CH2.TIM_Pulse =0;//
//			CH2.TIM_OutputState = TIM_OutputState_Disable;
//			CH2.TIM_OCPolarity = TIM_OCPolarity_Low;
//			//CH2.TIM_OCIdleState=TIM_OCIdleState_Reset;
//			CH2.TIM_OutputNState = TIM_OutputNState_Enable;//N
//			CH2.TIM_OCNPolarity = TIM_OCNPolarity_High;//N
//			//CH2.TIM_OCNIdleState=TIM_OCNIdleState_Reset;//N
//			TIM_OC2Init(TIM1, &CH2);//PA9
//		
//			
//			PWMmode=-1;
//		}
//		if(PWMmode==5)//_____________________________________________________________RIGHT
//		{
//			//Enable Tim1 CH1 PWM PA8 PA13
//			TIM_OCInitTypeDef CH1;
//			CH1.TIM_OCMode = TIM_OCMode_PWM1;
//			CH1.TIM_Pulse =87;//
//			CH1.TIM_OutputState = TIM_OutputState_Enable;
//			CH1.TIM_OCPolarity = TIM_OCPolarity_High;
//			//CH1.TIM_OCIdleState=TIM_OCIdleState_Reset;
//			CH1.TIM_OutputNState = TIM_OutputNState_Disable;//N
//			CH1.TIM_OCNPolarity = TIM_OCNPolarity_Low;//N
//			//CH1.TIM_OCNIdleState=TIM_OCNIdleState_Reset;//N
//			TIM_OC1Init(TIM1, &CH1);//PA8 
//			
//			TIM_OCInitTypeDef CH2;
//			CH2.TIM_OCMode = TIM_OCMode_PWM1;
//			CH2.TIM_Pulse =70;//b4 65
//			CH2.TIM_OutputState = TIM_OutputState_Disable;
//			CH2.TIM_OCPolarity = TIM_OCPolarity_Low;
//			//CH2.TIM_OCIdleState=TIM_OCIdleState_Reset;
//			CH2.TIM_OutputNState = TIM_OutputNState_Enable;//N
//			CH2.TIM_OCNPolarity = TIM_OCNPolarity_High;//N
//			//CH2.TIM_OCNIdleState=TIM_OCNIdleState_Reset;//N
//			TIM_OC2Init(TIM1, &CH2);//PA9
//			
//			
//			DelayMs(15);
//			
//			//Enable Tim1 CH1 PWM PA8 PA13
//			CH1.TIM_OCMode = TIM_OCMode_PWM1;
//			CH1.TIM_Pulse =0;//
//			CH1.TIM_OutputState = TIM_OutputState_Enable;
//			CH1.TIM_OCPolarity = TIM_OCPolarity_High;
//			//CH1.TIM_OCIdleState=TIM_OCIdleState_Reset;
//			CH1.TIM_OutputNState = TIM_OutputNState_Disable;//N
//			CH1.TIM_OCNPolarity = TIM_OCNPolarity_Low;//N
//			//CH1.TIM_OCNIdleState=TIM_OCNIdleState_Reset;//N
//			TIM_OC1Init(TIM1, &CH1);//PA8 
//			
//			CH2.TIM_OCMode = TIM_OCMode_PWM1;
//			CH2.TIM_Pulse =0;//
//			CH2.TIM_OutputState = TIM_OutputState_Disable;
//			CH2.TIM_OCPolarity = TIM_OCPolarity_Low;
//			//CH2.TIM_OCIdleState=TIM_OCIdleState_Reset;
//			CH2.TIM_OutputNState = TIM_OutputNState_Enable;//N
//			CH2.TIM_OCNPolarity = TIM_OCNPolarity_High;//N
//			//CH2.TIM_OCNIdleState=TIM_OCNIdleState_Reset;//N
//			TIM_OC2Init(TIM1, &CH2);//PA9
//		
//			
//			PWMmode=-1;
//		}
//		if(PWMmode==6)//_____________________________________________________________HardLeft
//		{
//			//Enable Tim1 CH1 PWM PA8 PA13
//			TIM_OCInitTypeDef CH1;
//			CH1.TIM_OCMode = TIM_OCMode_PWM1;
//			CH1.TIM_Pulse =60;//b4 marco 40,55
//			CH1.TIM_OutputState = TIM_OutputState_Enable;
//			CH1.TIM_OCPolarity = TIM_OCPolarity_High;
//			//CH1.TIM_OCIdleState=TIM_OCIdleState_Reset;
//			CH1.TIM_OutputNState = TIM_OutputNState_Disable;//N
//			CH1.TIM_OCNPolarity = TIM_OCNPolarity_Low;//N
//			//CH1.TIM_OCNIdleState=TIM_OCNIdleState_Reset;//N
//			TIM_OC1Init(TIM1, &CH1);//PA8 
//			
//			TIM_OCInitTypeDef CH2;
//			CH2.TIM_OCMode = TIM_OCMode_PWM1;
//			CH2.TIM_Pulse =75;//before marco 60 ,70
//			CH2.TIM_OutputState = TIM_OutputState_Disable;
//			CH2.TIM_OCPolarity = TIM_OCPolarity_Low;
//			//CH2.TIM_OCIdleState=TIM_OCIdleState_Reset;
//			CH2.TIM_OutputNState = TIM_OutputNState_Enable;//N
//			CH2.TIM_OCNPolarity = TIM_OCNPolarity_High;//N
//			//CH2.TIM_OCNIdleState=TIM_OCNIdleState_Reset;//N
//			TIM_OC2Init(TIM1, &CH2);//PA9
//			
//			
//			DelayMs(15);//before marco 25
//			
//			//Enable Tim1 CH1 PWM PA8 PA13
//			CH1.TIM_OCMode = TIM_OCMode_PWM1;
//			CH1.TIM_Pulse =0;//
//			CH1.TIM_OutputState = TIM_OutputState_Enable;
//			CH1.TIM_OCPolarity = TIM_OCPolarity_High;
//			//CH1.TIM_OCIdleState=TIM_OCIdleState_Reset;
//			CH1.TIM_OutputNState = TIM_OutputNState_Disable;//N
//			CH1.TIM_OCNPolarity = TIM_OCNPolarity_Low;//N
//			//CH1.TIM_OCNIdleState=TIM_OCNIdleState_Reset;//N
//			TIM_OC1Init(TIM1, &CH1);//PA8 
//			
//			CH2.TIM_OCMode = TIM_OCMode_PWM1;
//			CH2.TIM_Pulse =0;//
//			CH2.TIM_OutputState = TIM_OutputState_Disable;
//			CH2.TIM_OCPolarity = TIM_OCPolarity_Low;
//			//CH2.TIM_OCIdleState=TIM_OCIdleState_Reset;
//			CH2.TIM_OutputNState = TIM_OutputNState_Enable;//N
//			CH2.TIM_OCNPolarity = TIM_OCNPolarity_High;//N
//			//CH2.TIM_OCNIdleState=TIM_OCNIdleState_Reset;//N
//			TIM_OC2Init(TIM1, &CH2);//PA9
//		
//			
//			PWMmode=-1;
//		}
//		if(PWMmode==7)//_____________________________________________________________HardRIGHT
//		{
//			//Enable Tim1 CH1 PWM PA8 PA13
//			TIM_OCInitTypeDef CH1;
//			CH1.TIM_OCMode = TIM_OCMode_PWM1;
//			CH1.TIM_Pulse =75;//before marco 65
//			CH1.TIM_OutputState = TIM_OutputState_Enable;
//			CH1.TIM_OCPolarity = TIM_OCPolarity_High;
//			//CH1.TIM_OCIdleState=TIM_OCIdleState_Reset;
//			CH1.TIM_OutputNState = TIM_OutputNState_Disable;//N
//			CH1.TIM_OCNPolarity = TIM_OCNPolarity_Low;//N
//			//CH1.TIM_OCNIdleState=TIM_OCNIdleState_Reset;//N
//			TIM_OC1Init(TIM1, &CH1);//PA8 
//			
//			TIM_OCInitTypeDef CH2;
//			CH2.TIM_OCMode = TIM_OCMode_PWM1;
//			CH2.TIM_Pulse =55;//before marco 45
//			CH2.TIM_OutputState = TIM_OutputState_Disable;
//			CH2.TIM_OCPolarity = TIM_OCPolarity_Low;
//			//CH2.TIM_OCIdleState=TIM_OCIdleState_Reset;
//			CH2.TIM_OutputNState = TIM_OutputNState_Enable;//N
//			CH2.TIM_OCNPolarity = TIM_OCNPolarity_High;//N
//			//CH2.TIM_OCNIdleState=TIM_OCNIdleState_Reset;//N
//			TIM_OC2Init(TIM1, &CH2);//PA9
//			
//			
//			DelayMs(15);
//			
//			//Enable Tim1 CH1 PWM PA8 PA13
//			CH1.TIM_OCMode = TIM_OCMode_PWM1;
//			CH1.TIM_Pulse =0;//
//			CH1.TIM_OutputState = TIM_OutputState_Enable;
//			CH1.TIM_OCPolarity = TIM_OCPolarity_High;
//			//CH1.TIM_OCIdleState=TIM_OCIdleState_Reset;
//			CH1.TIM_OutputNState = TIM_OutputNState_Disable;//N
//			CH1.TIM_OCNPolarity = TIM_OCNPolarity_Low;//N
//			//CH1.TIM_OCNIdleState=TIM_OCNIdleState_Reset;//N
//			TIM_OC1Init(TIM1, &CH1);//PA8 
//			
//			CH2.TIM_OCMode = TIM_OCMode_PWM1;
//			CH2.TIM_Pulse =0;//
//			CH2.TIM_OutputState = TIM_OutputState_Disable;
//			CH2.TIM_OCPolarity = TIM_OCPolarity_Low;
//			//CH2.TIM_OCIdleState=TIM_OCIdleState_Reset;
//			CH2.TIM_OutputNState = TIM_OutputNState_Enable;//N
//			CH2.TIM_OCNPolarity = TIM_OCNPolarity_High;//N
//			//CH2.TIM_OCNIdleState=TIM_OCNIdleState_Reset;//N
//			TIM_OC2Init(TIM1, &CH2);//PA9
//		
//			
//			PWMmode=-1;
//		}
//		if(PWMmode==8)//_____________________________________________________________ExtremeLeft
//		{
//			//Enable Tim1 CH1 PWM PA8 PA13
//			TIM_OCInitTypeDef DCH1;
//			DCH1.TIM_OCMode = TIM_OCMode_PWM1;
//			DCH1.TIM_Pulse =15;//
//			DCH1.TIM_OutputState = TIM_OutputState_Disable;
//			DCH1.TIM_OCPolarity = TIM_OCPolarity_Low;
//			//DCH2.TIM_OCIdleState=TIM_OCIdleState_Reset;
//			DCH1.TIM_OutputNState = TIM_OutputNState_Enable;//N
//			DCH1.TIM_OCNPolarity = TIM_OCNPolarity_High;//N
//			//DCH2.TIM_OCNIdleState=TIM_OCNIdleState_Reset;//N
//			TIM_OC1Init(TIM1, &DCH1);//PB13 CH1N
//			
//			TIM_OCInitTypeDef CH2;
//			CH2.TIM_OCMode = TIM_OCMode_PWM1;
//			CH2.TIM_Pulse = 45;//
//			CH2.TIM_OutputState = TIM_OutputState_Disable;
//			CH2.TIM_OCPolarity = TIM_OCPolarity_Low;
//			//CH2.TIM_OCIdleState=TIM_OCIdleState_Reset;
//			CH2.TIM_OutputNState = TIM_OutputNState_Enable;//N
//			CH2.TIM_OCNPolarity = TIM_OCNPolarity_High;//N
//			//CH2.TIM_OCNIdleState=TIM_OCNIdleState_Reset;//N
//			TIM_OC2Init(TIM1, &CH2);//PA9
//			
//			
//			DelayMs(200);
//			
//			//Enable Tim1 CH1 PWM PA8 PA13
//			DCH1.TIM_OCMode = TIM_OCMode_PWM1;
//			DCH1.TIM_Pulse =0;//
//			DCH1.TIM_OutputState = TIM_OutputState_Enable;
//			DCH1.TIM_OCPolarity = TIM_OCPolarity_High;
//			//DCH1.TIM_OCIdleState=TIM_OCIdleState_Reset;
//			DCH1.TIM_OutputNState = TIM_OutputNState_Disable;//N
//			DCH1.TIM_OCNPolarity = TIM_OCNPolarity_Low;//N
//			//DCH1.TIM_OCNIdleState=TIM_OCNIdleState_Reset;//N
//			TIM_OC1Init(TIM1, &DCH1);//PA8 
//			
//			CH2.TIM_OCMode = TIM_OCMode_PWM1;
//			CH2.TIM_Pulse =0;//
//			CH2.TIM_OutputState = TIM_OutputState_Disable;
//			CH2.TIM_OCPolarity = TIM_OCPolarity_Low;
//			//CH2.TIM_OCIdleState=TIM_OCIdleState_Reset;
//			CH2.TIM_OutputNState = TIM_OutputNState_Enable;//N
//			CH2.TIM_OCNPolarity = TIM_OCNPolarity_High;//N
//			//CH2.TIM_OCNIdleState=TIM_OCNIdleState_Reset;//N
//			TIM_OC2Init(TIM1, &CH2);//PA9
//		
//			
//			PWMmode=-1;
//		}
//		if(PWMmode==9)//_____________________________________________________________ExtremeRight
//		{
//			//Enable Tim1 CH1 PWM PA8 PA13
//			TIM_OCInitTypeDef CH1;
//			CH1.TIM_OCMode = TIM_OCMode_PWM1;
//			CH1.TIM_Pulse =62;//
//			CH1.TIM_OutputState = TIM_OutputState_Enable;
//			CH1.TIM_OCPolarity = TIM_OCPolarity_High;
//			//CH1.TIM_OCIdleState=TIM_OCIdleState_Reset;
//			CH1.TIM_OutputNState = TIM_OutputNState_Disable;//N
//			CH1.TIM_OCNPolarity = TIM_OCNPolarity_Low;//N
//			//CH1.TIM_OCNIdleState=TIM_OCNIdleState_Reset;//N
//			TIM_OC1Init(TIM1, &CH1);//PA8 
//			
//			TIM_OCInitTypeDef CH2;
//			CH2.TIM_OCMode = TIM_OCMode_PWM1;
//			CH2.TIM_Pulse =0;//
//			CH2.TIM_OutputState = TIM_OutputState_Disable;
//			CH2.TIM_OCPolarity = TIM_OCPolarity_Low;
//			//CH2.TIM_OCIdleState=TIM_OCIdleState_Reset;
//			CH2.TIM_OutputNState = TIM_OutputNState_Enable;//N
//			CH2.TIM_OCNPolarity = TIM_OCNPolarity_High;//N
//			//CH2.TIM_OCNIdleState=TIM_OCNIdleState_Reset;//N
//			TIM_OC2Init(TIM1, &CH2);//PA9
//			
//			
//			DelayMs(200);
//			
//			//Enable Tim1 CH1 PWM PA8 PA13
//			CH1.TIM_OCMode = TIM_OCMode_PWM1;
//			CH1.TIM_Pulse =0;//
//			CH1.TIM_OutputState = TIM_OutputState_Enable;
//			CH1.TIM_OCPolarity = TIM_OCPolarity_High;
//			//CH1.TIM_OCIdleState=TIM_OCIdleState_Reset;
//			CH1.TIM_OutputNState = TIM_OutputNState_Disable;//N
//			CH1.TIM_OCNPolarity = TIM_OCNPolarity_Low;//N
//			//CH1.TIM_OCNIdleState=TIM_OCNIdleState_Reset;//N
//			TIM_OC1Init(TIM1, &CH1);//PA8 
//			
//			CH2.TIM_OCMode = TIM_OCMode_PWM1;
//			CH2.TIM_Pulse =0;//
//			CH2.TIM_OutputState = TIM_OutputState_Disable;
//			CH2.TIM_OCPolarity = TIM_OCPolarity_Low;
//			//CH2.TIM_OCIdleState=TIM_OCIdleState_Reset;
//			CH2.TIM_OutputNState = TIM_OutputNState_Enable;//N
//			CH2.TIM_OCNPolarity = TIM_OCNPolarity_High;//N
//			//CH2.TIM_OCNIdleState=TIM_OCNIdleState_Reset;//N
//			TIM_OC2Init(TIM1, &CH2);//PA9
//		
//			
//			PWMmode=-1;
//		}
//		if(PWMmode==10)//_____________________________________________________________First turn
//		{
//			DelayMs(100);
//			
//			//Enable Tim1 CH1 PWM PA8 PA13
//			TIM_OCInitTypeDef CH1;
//			CH1.TIM_OCMode = TIM_OCMode_PWM1;
//			CH1.TIM_Pulse =35;//b4 10
//			CH1.TIM_OutputState = TIM_OutputState_Enable;
//			CH1.TIM_OCPolarity = TIM_OCPolarity_High;
//			//CH1.TIM_OCIdleState=TIM_OCIdleState_Reset;
//			CH1.TIM_OutputNState = TIM_OutputNState_Disable;//N
//			CH1.TIM_OCNPolarity = TIM_OCNPolarity_Low;//N
//			//CH1.TIM_OCNIdleState=TIM_OCNIdleState_Reset;//N
//			TIM_OC1Init(TIM1, &CH1);//PA8 
//			
//			TIM_OCInitTypeDef CH2;
//			CH2.TIM_OCMode = TIM_OCMode_PWM1;
//			CH2.TIM_Pulse =127;//b4 marco 140
//			CH2.TIM_OutputState = TIM_OutputState_Disable;
//			CH2.TIM_OCPolarity = TIM_OCPolarity_Low;
//			//CH2.TIM_OCIdleState=TIM_OCIdleState_Reset;
//			CH2.TIM_OutputNState = TIM_OutputNState_Enable;//N
//			CH2.TIM_OCNPolarity = TIM_OCNPolarity_High;//N
//			//CH2.TIM_OCNIdleState=TIM_OCNIdleState_Reset;//N
//			TIM_OC2Init(TIM1, &CH2);//PA9
//			
//			
//			DelayMs(380);//B4 350
//			
//			//Enable Tim1 CH1 PWM PA8 PA13
//			CH1.TIM_OCMode = TIM_OCMode_PWM1;
//			CH1.TIM_Pulse =0;//
//			CH1.TIM_OutputState = TIM_OutputState_Enable;
//			CH1.TIM_OCPolarity = TIM_OCPolarity_High;
//			//CH1.TIM_OCIdleState=TIM_OCIdleState_Reset;
//			CH1.TIM_OutputNState = TIM_OutputNState_Disable;//N
//			CH1.TIM_OCNPolarity = TIM_OCNPolarity_Low;//N
//			//CH1.TIM_OCNIdleState=TIM_OCNIdleState_Reset;//N
//			TIM_OC1Init(TIM1, &CH1);//PA8 
//			
//			CH2.TIM_OCMode = TIM_OCMode_PWM1;
//			CH2.TIM_Pulse =0;//
//			CH2.TIM_OutputState = TIM_OutputState_Disable;
//			CH2.TIM_OCPolarity = TIM_OCPolarity_Low;
//			//CH2.TIM_OCIdleState=TIM_OCIdleState_Reset;
//			CH2.TIM_OutputNState = TIM_OutputNState_Enable;//N
//			CH2.TIM_OCNPolarity = TIM_OCNPolarity_High;//N
//			//CH2.TIM_OCNIdleState=TIM_OCNIdleState_Reset;//N
//			TIM_OC2Init(TIM1, &CH2);//PA9
//		
//			
//			PWMmode=-1;
//		}
//		if(PWMmode==11)//_____________________________________________________________SlowLEFT
//		{
//			//Enable Tim1 CH1 PWM PA8 PA13
//			TIM_OCInitTypeDef CH1;
//			CH1.TIM_OCMode = TIM_OCMode_PWM1;
//			CH1.TIM_Pulse =40;//
//			CH1.TIM_OutputState = TIM_OutputState_Enable;
//			CH1.TIM_OCPolarity = TIM_OCPolarity_High;
//			//CH1.TIM_OCIdleState=TIM_OCIdleState_Reset;
//			CH1.TIM_OutputNState = TIM_OutputNState_Disable;//N
//			CH1.TIM_OCNPolarity = TIM_OCNPolarity_Low;//N
//			//CH1.TIM_OCNIdleState=TIM_OCNIdleState_Reset;//N
//			TIM_OC1Init(TIM1, &CH1);//PA8 
//			
//			TIM_OCInitTypeDef CH2;
//			CH2.TIM_OCMode = TIM_OCMode_PWM1;
//			CH2.TIM_Pulse =65;//
//			CH2.TIM_OutputState = TIM_OutputState_Disable;
//			CH2.TIM_OCPolarity = TIM_OCPolarity_Low;
//			//CH2.TIM_OCIdleState=TIM_OCIdleState_Reset;
//			CH2.TIM_OutputNState = TIM_OutputNState_Enable;//N
//			CH2.TIM_OCNPolarity = TIM_OCNPolarity_High;//N
//			//CH2.TIM_OCNIdleState=TIM_OCNIdleState_Reset;//N
//			TIM_OC2Init(TIM1, &CH2);//PA9
//			
//			
//			DelayMs(50);
//			
//			//Enable Tim1 CH1 PWM PA8 PA13
//			CH1.TIM_OCMode = TIM_OCMode_PWM1;
//			CH1.TIM_Pulse =0;//
//			CH1.TIM_OutputState = TIM_OutputState_Enable;
//			CH1.TIM_OCPolarity = TIM_OCPolarity_High;
//			//CH1.TIM_OCIdleState=TIM_OCIdleState_Reset;
//			CH1.TIM_OutputNState = TIM_OutputNState_Disable;//N
//			CH1.TIM_OCNPolarity = TIM_OCNPolarity_Low;//N
//			//CH1.TIM_OCNIdleState=TIM_OCNIdleState_Reset;//N
//			TIM_OC1Init(TIM1, &CH1);//PA8 
//			
//			CH2.TIM_OCMode = TIM_OCMode_PWM1;
//			CH2.TIM_Pulse =0;//
//			CH2.TIM_OutputState = TIM_OutputState_Disable;
//			CH2.TIM_OCPolarity = TIM_OCPolarity_Low;
//			//CH2.TIM_OCIdleState=TIM_OCIdleState_Reset;
//			CH2.TIM_OutputNState = TIM_OutputNState_Enable;//N
//			CH2.TIM_OCNPolarity = TIM_OCNPolarity_High;//N
//			//CH2.TIM_OCNIdleState=TIM_OCNIdleState_Reset;//N
//			TIM_OC2Init(TIM1, &CH2);//PA9
//		
//			
//			PWMmode=-1;
//		}
//		if(PWMmode==12)//_____________________________________________________________SlowRIGHT
//		{
//			//Enable Tim1 CH1 PWM PA8 PA13
//			TIM_OCInitTypeDef CH1;
//			CH1.TIM_OCMode = TIM_OCMode_PWM1;
//			CH1.TIM_Pulse =67;//
//			CH1.TIM_OutputState = TIM_OutputState_Enable;
//			CH1.TIM_OCPolarity = TIM_OCPolarity_High;
//			//CH1.TIM_OCIdleState=TIM_OCIdleState_Reset;
//			CH1.TIM_OutputNState = TIM_OutputNState_Disable;//N
//			CH1.TIM_OCNPolarity = TIM_OCNPolarity_Low;//N
//			//CH1.TIM_OCNIdleState=TIM_OCNIdleState_Reset;//N
//			TIM_OC1Init(TIM1, &CH1);//PA8 
//			
//			TIM_OCInitTypeDef CH2;
//			CH2.TIM_OCMode = TIM_OCMode_PWM1;
//			CH2.TIM_Pulse =42;//
//			CH2.TIM_OutputState = TIM_OutputState_Disable;
//			CH2.TIM_OCPolarity = TIM_OCPolarity_Low;
//			//CH2.TIM_OCIdleState=TIM_OCIdleState_Reset;
//			CH2.TIM_OutputNState = TIM_OutputNState_Enable;//N
//			CH2.TIM_OCNPolarity = TIM_OCNPolarity_High;//N
//			//CH2.TIM_OCNIdleState=TIM_OCNIdleState_Reset;//N
//			TIM_OC2Init(TIM1, &CH2);//PA9
//			
//			
//			DelayMs(50);
//			
//			//Enable Tim1 CH1 PWM PA8 PA13
//			CH1.TIM_OCMode = TIM_OCMode_PWM1;
//			CH1.TIM_Pulse =0;//
//			CH1.TIM_OutputState = TIM_OutputState_Enable;
//			CH1.TIM_OCPolarity = TIM_OCPolarity_High;
//			//CH1.TIM_OCIdleState=TIM_OCIdleState_Reset;
//			CH1.TIM_OutputNState = TIM_OutputNState_Disable;//N
//			CH1.TIM_OCNPolarity = TIM_OCNPolarity_Low;//N
//			//CH1.TIM_OCNIdleState=TIM_OCNIdleState_Reset;//N
//			TIM_OC1Init(TIM1, &CH1);//PA8 
//			
//			CH2.TIM_OCMode = TIM_OCMode_PWM1;
//			CH2.TIM_Pulse =0;//
//			CH2.TIM_OutputState = TIM_OutputState_Disable;
//			CH2.TIM_OCPolarity = TIM_OCPolarity_Low;
//			//CH2.TIM_OCIdleState=TIM_OCIdleState_Reset;
//			CH2.TIM_OutputNState = TIM_OutputNState_Enable;//N
//			CH2.TIM_OCNPolarity = TIM_OCNPolarity_High;//N
//			//CH2.TIM_OCNIdleState=TIM_OCNIdleState_Reset;//N
//			TIM_OC2Init(TIM1, &CH2);//PA9
//		
//			
//			PWMmode=-1;
//		}
//		if(PWMmode==13)//_____________________________________________________________Middle Left
//		{
//			//Enable Tim1 CH1 PWM PA8 PA13
//			TIM_OCInitTypeDef CH1;
//			CH1.TIM_OCMode = TIM_OCMode_PWM1;
//			CH1.TIM_Pulse =30;//
//			CH1.TIM_OutputState = TIM_OutputState_Enable;
//			CH1.TIM_OCPolarity = TIM_OCPolarity_High;
//			//CH1.TIM_OCIdleState=TIM_OCIdleState_Reset;
//			CH1.TIM_OutputNState = TIM_OutputNState_Disable;//N
//			CH1.TIM_OCNPolarity = TIM_OCNPolarity_Low;//N
//			//CH1.TIM_OCNIdleState=TIM_OCNIdleState_Reset;//N
//			TIM_OC1Init(TIM1, &CH1);//PA8 
//			
//			TIM_OCInitTypeDef CH2;
//			CH2.TIM_OCMode = TIM_OCMode_PWM1;
//			CH2.TIM_Pulse = 70;//
//			CH2.TIM_OutputState = TIM_OutputState_Disable;
//			CH2.TIM_OCPolarity = TIM_OCPolarity_Low;
//			//CH2.TIM_OCIdleState=TIM_OCIdleState_Reset;
//			CH2.TIM_OutputNState = TIM_OutputNState_Enable;//N
//			CH2.TIM_OCNPolarity = TIM_OCNPolarity_High;//N
//			//CH2.TIM_OCNIdleState=TIM_OCNIdleState_Reset;//N
//			TIM_OC2Init(TIM1, &CH2);//PA9
//			
//			
//			DelayMs(10);
//			
//			//Enable Tim1 CH1 PWM PA8 PA13
//			CH1.TIM_OCMode = TIM_OCMode_PWM1;
//			CH1.TIM_Pulse =0;//
//			CH1.TIM_OutputState = TIM_OutputState_Enable;
//			CH1.TIM_OCPolarity = TIM_OCPolarity_High;
//			//CH1.TIM_OCIdleState=TIM_OCIdleState_Reset;
//			CH1.TIM_OutputNState = TIM_OutputNState_Disable;//N
//			CH1.TIM_OCNPolarity = TIM_OCNPolarity_Low;//N
//			//CH1.TIM_OCNIdleState=TIM_OCNIdleState_Reset;//N
//			TIM_OC1Init(TIM1, &CH1);//PA8 
//			
//			CH2.TIM_OCMode = TIM_OCMode_PWM1;
//			CH2.TIM_Pulse =0;//
//			CH2.TIM_OutputState = TIM_OutputState_Disable;
//			CH2.TIM_OCPolarity = TIM_OCPolarity_Low;
//			//CH2.TIM_OCIdleState=TIM_OCIdleState_Reset;
//			CH2.TIM_OutputNState = TIM_OutputNState_Enable;//N
//			CH2.TIM_OCNPolarity = TIM_OCNPolarity_High;//N
//			//CH2.TIM_OCNIdleState=TIM_OCNIdleState_Reset;//N
//			TIM_OC2Init(TIM1, &CH2);//PA9
//		
//			
//			PWMmode=-1;
//		}
//		if(PWMmode==14)//_____________________________________________________________ Middle Right
//		{
//			//Enable Tim1 CH1 PWM PA8 PA13
//			TIM_OCInitTypeDef CH1;
//			CH1.TIM_OCMode = TIM_OCMode_PWM1;
//			CH1.TIM_Pulse = 70;//
//			CH1.TIM_OutputState = TIM_OutputState_Enable;
//			CH1.TIM_OCPolarity = TIM_OCPolarity_High;
//			//CH1.TIM_OCIdleState=TIM_OCIdleState_Reset;
//			CH1.TIM_OutputNState = TIM_OutputNState_Disable;//N
//			CH1.TIM_OCNPolarity = TIM_OCNPolarity_Low;//N
//			//CH1.TIM_OCNIdleState=TIM_OCNIdleState_Reset;//N
//			TIM_OC1Init(TIM1, &CH1);//PA8 
//			
//			TIM_OCInitTypeDef CH2;
//			CH2.TIM_OCMode = TIM_OCMode_PWM1;
//			CH2.TIM_Pulse =30;//
//			CH2.TIM_OutputState = TIM_OutputState_Disable;
//			CH2.TIM_OCPolarity = TIM_OCPolarity_Low;
//			//CH2.TIM_OCIdleState=TIM_OCIdleState_Reset;
//			CH2.TIM_OutputNState = TIM_OutputNState_Enable;//N
//			CH2.TIM_OCNPolarity = TIM_OCNPolarity_High;//N
//			//CH2.TIM_OCNIdleState=TIM_OCNIdleState_Reset;//N
//			TIM_OC2Init(TIM1, &CH2);//PA9
//			
//			
//			DelayMs(30);//before 10
//			
//			//Enable Tim1 CH1 PWM PA8 PA13
//			CH1.TIM_OCMode = TIM_OCMode_PWM1;
//			CH1.TIM_Pulse =0;//
//			CH1.TIM_OutputState = TIM_OutputState_Enable;
//			CH1.TIM_OCPolarity = TIM_OCPolarity_High;
//			//CH1.TIM_OCIdleState=TIM_OCIdleState_Reset;
//			CH1.TIM_OutputNState = TIM_OutputNState_Disable;//N
//			CH1.TIM_OCNPolarity = TIM_OCNPolarity_Low;//N
//			//CH1.TIM_OCNIdleState=TIM_OCNIdleState_Reset;//N
//			TIM_OC1Init(TIM1, &CH1);//PA8 
//			
//			CH2.TIM_OCMode = TIM_OCMode_PWM1;
//			CH2.TIM_Pulse =0;//
//			CH2.TIM_OutputState = TIM_OutputState_Disable;
//			CH2.TIM_OCPolarity = TIM_OCPolarity_Low;
//			//CH2.TIM_OCIdleState=TIM_OCIdleState_Reset;
//			CH2.TIM_OutputNState = TIM_OutputNState_Enable;//N
//			CH2.TIM_OCNPolarity = TIM_OCNPolarity_High;//N
//			//CH2.TIM_OCNIdleState=TIM_OCNIdleState_Reset;//N
//			TIM_OC2Init(TIM1, &CH2);//PA9
//		
//			
//			PWMmode=-1;
//		}
//		if(PWMmode==15)//_____________________________________________________________ Middle Hard Left
//		{
//			//Enable Tim1 CH1 PWM PA8 PA13
//			TIM_OCInitTypeDef DCH1;
//			DCH1.TIM_OCMode = TIM_OCMode_PWM1;
//			DCH1.TIM_Pulse =5;//
//			DCH1.TIM_OutputState = TIM_OutputState_Disable;
//			DCH1.TIM_OCPolarity = TIM_OCPolarity_Low;
//			//DCH2.TIM_OCIdleState=TIM_OCIdleState_Reset;
//			DCH1.TIM_OutputNState = TIM_OutputNState_Enable;//N
//			DCH1.TIM_OCNPolarity = TIM_OCNPolarity_High;//N
//			//DCH2.TIM_OCNIdleState=TIM_OCNIdleState_Reset;//N
//			TIM_OC1Init(TIM1, &DCH1);//PB13 CH1N
//			
//			TIM_OCInitTypeDef CH2;
//			CH2.TIM_OCMode = TIM_OCMode_PWM1;
//			CH2.TIM_Pulse =70;//
//			CH2.TIM_OutputState = TIM_OutputState_Disable;
//			CH2.TIM_OCPolarity = TIM_OCPolarity_Low;
//			//CH2.TIM_OCIdleState=TIM_OCIdleState_Reset;
//			CH2.TIM_OutputNState = TIM_OutputNState_Enable;//N
//			CH2.TIM_OCNPolarity = TIM_OCNPolarity_High;//N
//			//CH2.TIM_OCNIdleState=TIM_OCNIdleState_Reset;//N
//			TIM_OC2Init(TIM1, &CH2);//PA9
//			
//			
//			DelayMs(50);
//			
//			//Enable Tim1 CH1 PWM PA8 PA13
//			DCH1.TIM_OCMode = TIM_OCMode_PWM1;
//			DCH1.TIM_Pulse =0;//
//			DCH1.TIM_OutputState = TIM_OutputState_Enable;
//			DCH1.TIM_OCPolarity = TIM_OCPolarity_High;
//			//DCH1.TIM_OCIdleState=TIM_OCIdleState_Reset;
//			DCH1.TIM_OutputNState = TIM_OutputNState_Disable;//N
//			DCH1.TIM_OCNPolarity = TIM_OCNPolarity_Low;//N
//			//DCH1.TIM_OCNIdleState=TIM_OCNIdleState_Reset;//N
//			TIM_OC1Init(TIM1, &DCH1);//PA8 
//			
//			CH2.TIM_OCMode = TIM_OCMode_PWM1;
//			CH2.TIM_Pulse =0;//
//			CH2.TIM_OutputState = TIM_OutputState_Disable;
//			CH2.TIM_OCPolarity = TIM_OCPolarity_Low;
//			//CH2.TIM_OCIdleState=TIM_OCIdleState_Reset;
//			CH2.TIM_OutputNState = TIM_OutputNState_Enable;//N
//			CH2.TIM_OCNPolarity = TIM_OCNPolarity_High;//N
//			//CH2.TIM_OCNIdleState=TIM_OCNIdleState_Reset;//N
//			TIM_OC2Init(TIM1, &CH2);//PA9
//		
//			
//			PWMmode=-1;
//		}
//		if(PWMmode==16)//_____________________________________________________________ Middle Hard Right
//		{
//			//Enable Tim1 CH1 PWM PA8 PA13
//			TIM_OCInitTypeDef CH1;
//			CH1.TIM_OCMode = TIM_OCMode_PWM1;
//			CH1.TIM_Pulse =70;//
//			CH1.TIM_OutputState = TIM_OutputState_Enable;
//			CH1.TIM_OCPolarity = TIM_OCPolarity_High;
//			//CH1.TIM_OCIdleState=TIM_OCIdleState_Reset;
//			CH1.TIM_OutputNState = TIM_OutputNState_Disable;//N
//			CH1.TIM_OCNPolarity = TIM_OCNPolarity_Low;//N
//			//CH1.TIM_OCNIdleState=TIM_OCNIdleState_Reset;//N
//			TIM_OC1Init(TIM1, &CH1);//PA8 
//			
//			TIM_OCInitTypeDef DCH2;
//			DCH2.TIM_OCMode = TIM_OCMode_PWM1;
//			DCH2.TIM_Pulse =5;//
//			DCH2.TIM_OutputState = TIM_OutputState_Enable;
//			DCH2.TIM_OCPolarity = TIM_OCPolarity_High;
//			//DCH2.TIM_OCIdleState=TIM_OCIdleState_Reset;
//			DCH2.TIM_OutputNState = TIM_OutputNState_Disable;//N
//			DCH2.TIM_OCNPolarity = TIM_OCNPolarity_Low;//N
//			//DCH2.TIM_OCNIdleState=TIM_OCNIdleState_Reset;//N
//			TIM_OC2Init(TIM1, &DCH2);//PA9 CH2
//			
//			
//			DelayMs(50);
//			
//			//Enable Tim1 CH1 PWM PA8 PA13
//			CH1.TIM_OCMode = TIM_OCMode_PWM1;
//			CH1.TIM_Pulse =0;//
//			CH1.TIM_OutputState = TIM_OutputState_Enable;
//			CH1.TIM_OCPolarity = TIM_OCPolarity_High;
//			//CH1.TIM_OCIdleState=TIM_OCIdleState_Reset;
//			CH1.TIM_OutputNState = TIM_OutputNState_Disable;//N
//			CH1.TIM_OCNPolarity = TIM_OCNPolarity_Low;//N
//			//CH1.TIM_OCNIdleState=TIM_OCNIdleState_Reset;//N
//			TIM_OC1Init(TIM1, &CH1);//PA8 
//			
//			DCH2.TIM_OCMode = TIM_OCMode_PWM1;
//			DCH2.TIM_Pulse =0;//
//			DCH2.TIM_OutputState = TIM_OutputState_Disable;
//			DCH2.TIM_OCPolarity = TIM_OCPolarity_Low;
//			//DCH2.TIM_OCIdleState=TIM_OCIdleState_Reset;
//			DCH2.TIM_OutputNState = TIM_OutputNState_Enable;//N
//			DCH2.TIM_OCNPolarity = TIM_OCNPolarity_High;//N
//			//DCH2.TIM_OCNIdleState=TIM_OCNIdleState_Reset;//N
//			TIM_OC2Init(TIM1, &DCH2);//PA9
//		
//			
//			PWMmode=-1;
//		}
//		if(PWMmode==17)//_____________________________________________________________ Second turn
//		{
//			//Enable Tim1 CH1 PWM PA8 PA13
//			TIM_OCInitTypeDef DCH1;
//			DCH1.TIM_OCMode = TIM_OCMode_PWM1;
//			DCH1.TIM_Pulse = 160;//150
//			DCH1.TIM_OutputState = TIM_OutputState_Disable;
//			DCH1.TIM_OCPolarity = TIM_OCPolarity_Low;
//			//DCH2.TIM_OCIdleState=TIM_OCIdleState_Reset;
//			DCH1.TIM_OutputNState = TIM_OutputNState_Enable;//N
//			DCH1.TIM_OCNPolarity = TIM_OCNPolarity_High;//N
//			//DCH2.TIM_OCNIdleState=TIM_OCNIdleState_Reset;//N
//			TIM_OC1Init(TIM1, &DCH1);//PB13 CH1N
//			
//			TIM_OCInitTypeDef CH2;
//			CH2.TIM_OCMode = TIM_OCMode_PWM1;
//			CH2.TIM_Pulse =70;//70
//			CH2.TIM_OutputState = TIM_OutputState_Disable;
//			CH2.TIM_OCPolarity = TIM_OCPolarity_Low;
//			//CH2.TIM_OCIdleState=TIM_OCIdleState_Reset;
//			CH2.TIM_OutputNState = TIM_OutputNState_Enable;//N
//			CH2.TIM_OCNPolarity = TIM_OCNPolarity_High;//N
//			//CH2.TIM_OCNIdleState=TIM_OCNIdleState_Reset;//N
//			TIM_OC2Init(TIM1, &CH2);//PA9
//			
//			
//			DelayMs(550);//before 430
//			
//			

//			
//			//Enable Tim1 CH1 PWM PA8 PA13
//			DCH1.TIM_OCMode = TIM_OCMode_PWM1;
//			DCH1.TIM_Pulse =0;//
//			DCH1.TIM_OutputState = TIM_OutputState_Enable;
//			DCH1.TIM_OCPolarity = TIM_OCPolarity_High;
//			//DCH1.TIM_OCIdleState=TIM_OCIdleState_Reset;
//			DCH1.TIM_OutputNState = TIM_OutputNState_Disable;//N
//			DCH1.TIM_OCNPolarity = TIM_OCNPolarity_Low;//N
//			//DCH1.TIM_OCNIdleState=TIM_OCNIdleState_Reset;//N
//			TIM_OC1Init(TIM1, &DCH1);//PA8 
//			
//			CH2.TIM_OCMode = TIM_OCMode_PWM1;
//			CH2.TIM_Pulse =0;//
//			CH2.TIM_OutputState = TIM_OutputState_Disable;
//			CH2.TIM_OCPolarity = TIM_OCPolarity_Low;
//			//CH2.TIM_OCIdleState=TIM_OCIdleState_Reset;
//			CH2.TIM_OutputNState = TIM_OutputNState_Enable;//N
//			CH2.TIM_OCNPolarity = TIM_OCNPolarity_High;//N
//			//CH2.TIM_OCNIdleState=TIM_OCNIdleState_Reset;//N
//			TIM_OC2Init(TIM1, &CH2);//PA9
//			PWMmode=-1;
//		}
//		if(PWMmode==18)//_____________________________________________________________ExtremeLeft
//		{
//			//Enable Tim1 CH1 PWM PA8 PA13
//			TIM_OCInitTypeDef DCH1;
//			DCH1.TIM_OCMode = TIM_OCMode_PWM1;
//			DCH1.TIM_Pulse =20;//
//			DCH1.TIM_OutputState = TIM_OutputState_Disable;
//			DCH1.TIM_OCPolarity = TIM_OCPolarity_Low;
//			//DCH2.TIM_OCIdleState=TIM_OCIdleState_Reset;
//			DCH1.TIM_OutputNState = TIM_OutputNState_Enable;//N
//			DCH1.TIM_OCNPolarity = TIM_OCNPolarity_High;//N
//			//DCH2.TIM_OCNIdleState=TIM_OCNIdleState_Reset;//N
//			TIM_OC1Init(TIM1, &DCH1);//PB13 CH1N
//			
//			TIM_OCInitTypeDef CH2;
//			CH2.TIM_OCMode = TIM_OCMode_PWM1;
//			CH2.TIM_Pulse =60;//
//			CH2.TIM_OutputState = TIM_OutputState_Disable;
//			CH2.TIM_OCPolarity = TIM_OCPolarity_Low;
//			//CH2.TIM_OCIdleState=TIM_OCIdleState_Reset;
//			CH2.TIM_OutputNState = TIM_OutputNState_Enable;//N
//			CH2.TIM_OCNPolarity = TIM_OCNPolarity_High;//N
//			//CH2.TIM_OCNIdleState=TIM_OCNIdleState_Reset;//N
//			TIM_OC2Init(TIM1, &CH2);//PA9
//			
//			
//			DelayMs(20);
//			
//			//Enable Tim1 CH1 PWM PA8 PA13
//			DCH1.TIM_OCMode = TIM_OCMode_PWM1;
//			DCH1.TIM_Pulse =0;//
//			DCH1.TIM_OutputState = TIM_OutputState_Enable;
//			DCH1.TIM_OCPolarity = TIM_OCPolarity_High;
//			//DCH1.TIM_OCIdleState=TIM_OCIdleState_Reset;
//			DCH1.TIM_OutputNState = TIM_OutputNState_Disable;//N
//			DCH1.TIM_OCNPolarity = TIM_OCNPolarity_Low;//N
//			//DCH1.TIM_OCNIdleState=TIM_OCNIdleState_Reset;//N
//			TIM_OC1Init(TIM1, &DCH1);//PA8 
//			
//			CH2.TIM_OCMode = TIM_OCMode_PWM1;
//			CH2.TIM_Pulse =0;//
//			CH2.TIM_OutputState = TIM_OutputState_Disable;
//			CH2.TIM_OCPolarity = TIM_OCPolarity_Low;
//			//CH2.TIM_OCIdleState=TIM_OCIdleState_Reset;
//			CH2.TIM_OutputNState = TIM_OutputNState_Enable;//N
//			CH2.TIM_OCNPolarity = TIM_OCNPolarity_High;//N
//			//CH2.TIM_OCNIdleState=TIM_OCNIdleState_Reset;//N
//			TIM_OC2Init(TIM1, &CH2);//PA9
//		
//			
//			PWMmode=-1;
//		}
//		TIM_OCInitTypeDef CH1;
//    CH1.TIM_OCMode = TIM_OCMode_PWM1;
//    CH1.TIM_Pulse = pwm_left;
//    CH1.TIM_OutputState = TIM_OutputState_Enable;
//    CH1.TIM_OCPolarity = TIM_OCPolarity_High;
//    CH1.TIM_OutputNState = TIM_OutputNState_Disable;
//    CH1.TIM_OCNPolarity = TIM_OCNPolarity_Low;
//    TIM_OC1Init(TIM1, &CH1); 
//    TIM_OCInitTypeDef CH2;
//    CH2.TIM_OCMode = TIM_OCMode_PWM1;
//    CH2.TIM_Pulse = pwm_right;
//    CH2.TIM_OutputState = TIM_OutputState_Disable;
//    CH2.TIM_OCPolarity = TIM_OCPolarity_Low;
//    CH2.TIM_OutputNState = TIM_OutputNState_Enable;
//    CH2.TIM_OCNPolarity = TIM_OCNPolarity_High;
//    TIM_OC2Init(TIM1, &CH2);
//	}
//}
//void readFloor() 
//{
//	// Set PA7 to 1
//	GPIO_SetBits(GPIOA, GPIO_Pin_7);
//	DelayMs(1);
//	// Initialize the data transmission from the master to the slave
//	SPI_I2S_SendData(SPI1, 0);
//	// Enable the interrupt to receive data by using the ISR handler
//	NVIC_EnableIRQ(SPI1_IRQn);;
//}
//// put the readings to the variable c
//void SPI1_IRQHandler() 
//{
//	// the received character has all the readings
//	 c = (char) SPI_I2S_ReceiveData(SPI1) & 0xff;
//	
//	if (GPIO_ReadOutputDataBit(GPIOA, GPIO_Pin_7) == 1) 
//	{
//	  // Set PA7 to 0 to trigger the shift register
//	  GPIO_ResetBits(GPIOA, GPIO_Pin_7);
//	  // Go to get the next reading
//	  SPI_I2S_SendData(SPI1, 0);
//		
//	} 
//	else 
//	{
//		if((c&(1<<0)) && (c&(1<<7)) && (repeat == 0)) //reading all 00000000
//		{
//			repeat = 1;
//			count++;
//		}
//		if(count == 12)
//		{
//			PWMmode = 17;
//			count++;
//		}else if(count == 5)
//		{
//			PWMmode = 10;
//			count++;
//		}
//		else{
//		if((!(c&(1<<0)) && !(c&(1<<1)) && !(c&(1<<2)) && !(c&(1<<3)) && !(c&(1<<4)) && !(c&(1<<5)) && !(c&(1<<6)) && !(c&(1<<7))) || (!(c&(1<<0)) && !(c&(1<<1)) && !(c&(1<<2)) && !(c&(1<<3)) && !(c&(1<<4)) && !(c&(1<<5)) && !(c&(1<<6)) && (c&(1<<7))))
//		{
//			PWMmode = 18;
//		}else
//		{
//			if(!(c&(1<<7)) || !(c&(1<<0)))
//			{
//				repeat = 0;
//			}
//			if(count == 13 || count == 14 || count == 15 || count == 16)
//			{
//				if (c&(1<0)){
//					PWMmode = 16;	
//				}else if (c&(1<<1)) { // Right
//					PWMmode = 16;	
//				}else if(c&(1<<7))			//Middle mode
//				{
//					PWMmode = 15;	// Left
//				}else if (c&(1<<6)) {
//					PWMmode = 15;	
//				}else if (c&(1<<5)) {
//					PWMmode = 13;	 
//				}else if (c&(1<<2)) {
//					PWMmode = 14;	
//				}else if (c&(1<<4)) {
//					PWMmode = 13;	
//				}else if (c&(1<<3)) {
//					PWMmode = 14;	
//				}
//			}else if(count == 6)
//			{
//				if(c&(1<<7))			//Middle mode
//				{
//					PWMmode = 15;	// Left
//				}else if (c&(1<0)){
//					count = 7;
//				}else if (c&(1<<6)) {
//					PWMmode = 15;	
//				}else if (c&(1<<1)) { // Right
//					PWMmode = 16;	
//				}else if (c&(1<<5)) {
//					PWMmode = 13;	 
//				}else if (c&(1<<2)) {
//					PWMmode = 14;	
//				}else if (c&(1<<3)) {
//					PWMmode = 14;	
//				}else if (c&(1<<4)) {
//					PWMmode = 13;	
//				}else {
//					pwm(0,40);
//				}
//			}else if(count == 2 || count == 4 || count == 9 || count == 11) //Slow mode, before count==9 no 8
//			{
//				if (c&(1<<0)) {
//				pwm(50, 35);	// Hard right before marco pwm(40, 30);
//			}else if (c&(1<<1)) {
//				pwm(70, 40);	// Right before marco pwm(40, 30);
//			}else if (c&(1<<2)) {
//				pwm(60, 32);	//62,32
//			}else if (c&(1<<3)) {
//				pwm(60, 36);	// 
//			}else if (c&(1<<4)){
//				pwm(40,70);	// Left b4 65
//			}else if(c&(1<<5)){
//				pwm(35,65);	// Hard Left b4 65
//			}else if (c&(1<<6)) {
//				PWMmode = 8;	// 
//			}else if (c&(1<<7)) {
//				PWMmode = 8;	// 
//			}
//			}
//			else{ 
//			if (c&(1<<5)) {
//				PWMmode = 4;	// 
//			}else if (c&(1<<6)){
//				PWMmode = 6;	// Left
//			}else if (c&(1<<3)) {
//				PWMmode = 5;	// 
//			}else if(c&(1<<7)	)			//Normal mode
//			{
//				PWMmode = 6;	// Hard Left
//			} else if (c&(1<<4)) {
//				PWMmode = 4;	// 
//			}else if (c&(1<<2)) {
//				PWMmode = 5;	//
//			}else if (c&(1<<1)) {
//				PWMmode = 7;	// Right
//			}else if (c&(1<<0)) {
//				PWMmode = 7;	// Hard right
//			}
//		}
//	}
//}
//	
//	
//	{
//	if(c&(1<<0))
//	{
//	while(USART_GetFlagStatus(USART2, USART_FLAG_TC) == RESET);	
//	USART_SendData(USART2,'0');
//	}
//	else
//	{
//	while(USART_GetFlagStatus(USART2, USART_FLAG_TC) == RESET);	
//	USART_SendData(USART2,'1');
//	}
//	if(c&(1<<1))
//	{
//	while(USART_GetFlagStatus(USART2, USART_FLAG_TC) == RESET);	
//	USART_SendData(USART2,'0');
//	}
//	else
//	{
//	while(USART_GetFlagStatus(USART2, USART_FLAG_TC) == RESET);	
//	USART_SendData(USART2,'1');
//	}	
//	if(c&(1<<2))
//	{
//	while(USART_GetFlagStatus(USART2, USART_FLAG_TC) == RESET);	
//	USART_SendData(USART2,'0');
//	}
//	else
//	{
//	while(USART_GetFlagStatus(USART2, USART_FLAG_TC) == RESET);	
//	USART_SendData(USART2,'1');
//	}	
//	if(c&(1<<3))
//	{
//	while(USART_GetFlagStatus(USART2, USART_FLAG_TC) == RESET);	
//	USART_SendData(USART2,'0');
//	}
//	else
//	{
//	while(USART_GetFlagStatus(USART2, USART_FLAG_TC) == RESET);	
//	USART_SendData(USART2,'1');
//	}	
//	if(c&(1<<4))
//	{
//	while(USART_GetFlagStatus(USART2, USART_FLAG_TC) == RESET);	
//	USART_SendData(USART2,'0');
//	}
//	else
//	{
//	while(USART_GetFlagStatus(USART2, USART_FLAG_TC) == RESET);	
//	USART_SendData(USART2,'1');
//	}	
//	if(c&(1<<5))
//	{
//	while(USART_GetFlagStatus(USART2, USART_FLAG_TC) == RESET);	
//	USART_SendData(USART2,'0');
//	}
//	else
//	{
//	while(USART_GetFlagStatus(USART2, USART_FLAG_TC) == RESET);	
//	USART_SendData(USART2,'1');
//	}	
//	if(c&(1<<6))
//	{
//	while(USART_GetFlagStatus(USART2, USART_FLAG_TC) == RESET);	
//	USART_SendData(USART2,'0');
//	}
//	else
//	{
//	while(USART_GetFlagStatus(USART2, USART_FLAG_TC) == RESET);	
//	USART_SendData(USART2,'1');
//	}	
//	if(c&(1<<7))
//	{
//	while(USART_GetFlagStatus(USART2, USART_FLAG_TC) == RESET);	
//	USART_SendData(USART2,'0');
//	}
//	else
//	{
//	while(USART_GetFlagStatus(USART2, USART_FLAG_TC) == RESET);	
//	USART_SendData(USART2,'1');
//	}	
//		
////	while(USART_GetFlagStatus(USART3, USART_FLAG_TC) == RESET);
////	USART_SendData(USART2, c);
//	while(USART_GetFlagStatus(USART2, USART_FLAG_TC) == RESET);
//	USART_SendData(USART2, '\r');
//	while(USART_GetFlagStatus(USART2, USART_FLAG_TC) == RESET);
//	USART_SendData(USART2, '\n');
//	}
//	
//	// Check PA7. If it is 1, it means the data is ready
//	
//	  // disable the interrupt because it is not ready
//	  NVIC_DisableIRQ(SPI1_IRQn);
//		
//		
//	}
//}

//void DelayMs(uint32_t ms)
//{
//	// Reload ms value
//	msTicks = ms;
//	// Wait until msTick reach zero
//	while (msTicks);
//}

//// SysTick_Handler function will be called every 1 ms
//void SysTick_Handler()
//{
//	if (msTicks != 0)
//	{
//		msTicks--;
//	}
//}


/*log
Tested USART3 and successfully send out character
SPI2.c change the char c in unsigned
SPI2.c change all PB13 to PA5,PB15 to PA7
SPI2.c change SPI2 to SPI1 
SPI2.c change RCC_APB1ENR_SPI2EN to RCC_APB2ENR_SPI1EN



*/
#include "stm32f10x.h"                  // Device header
#include "stdio.h"
#include "misc.h"
unsigned char state=0;
unsigned char c;
static __IO uint32_t msTicks;
void DelayMs(uint32_t ms);
unsigned char character;
unsigned char led8bit=1;
void readFloor();
char buffer[] = {"Yes"};
int count = 0;
int repeat = 0;
static int PWMmode=0;
void PWMODE(void);
static unsigned int pwm_left;
static unsigned int pwm_right;

void pwm(unsigned int l, unsigned int r){
    pwm_left=l;
    pwm_right=r;
}
int main(void)
{
	// Update SystemCoreClock value
	SystemCoreClockUpdate();
	
	// Configure the SysTick timer to overflow every 1 ms
	SysTick_Config(SystemCoreClock / 1000);

	// Setup PA5 and PA7
	// PA5 = SPI1_SCK, PA7 = IR LED / MODE
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7|GPIO_Pin_4;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	//GPIO_WriteBit(GPIOA, GPIO_Pin_4, Bit_SET);
	
	RCC_APB2PeriphClockCmd(RCC_APB2ENR_SPI1EN, ENABLE);

	SPI_InitTypeDef   SPI_InitStructure;
	SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
  SPI_InitStructure.SPI_Mode = SPI_Mode_Master;
  SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;
  SPI_InitStructure.SPI_CPOL = SPI_CPOL_High;
  SPI_InitStructure.SPI_CPHA = SPI_CPHA_2Edge;
  SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;
  // 36 MHz / 256 = 140.625 kHz
  SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_256;
  SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;
  SPI_Init(SPI1, &SPI_InitStructure);
	// Enable the receive interrupt
	SPI_I2S_ITConfig(SPI1, SPI_I2S_IT_RXNE, ENABLE);
  // Enable SPI1
  SPI_Cmd(SPI1, ENABLE);
	
	// Enable USART3 and GPIOB clocks
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3, ENABLE);
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	// Configure PB10 and PB11 as USART3 pins
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
  GPIO_Init(GPIOB, &GPIO_InitStructure);

  // Initialize USART3
	USART_InitTypeDef USART_InitStructure;
  USART_InitStructure.USART_BaudRate = 9600;
  USART_InitStructure.USART_WordLength = USART_WordLength_8b;
  USART_InitStructure.USART_StopBits = USART_StopBits_1;
  USART_InitStructure.USART_Parity = USART_Parity_No;
  USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
  USART_InitStructure.USART_Mode = USART_Mode_Tx;
  USART_Init(USART3, &USART_InitStructure);
	
	// Enable USART2 and GPIOA clocks
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	// Configure PA2 and PA3 as USART3 pins
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOA, &GPIO_InitStructure);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
  GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	
	USART_InitStructure.USART_BaudRate = 115200;
  USART_InitStructure.USART_WordLength = USART_WordLength_8b;
  USART_InitStructure.USART_StopBits = USART_StopBits_1;
  USART_InitStructure.USART_Parity = USART_Parity_No;
  USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
  USART_InitStructure.USART_Mode = USART_Mode_Tx;
  USART_Init(USART2, &USART_InitStructure);

  // Enable USART2,USART23
  USART_Cmd(USART3, ENABLE);
	USART_Cmd(USART2, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOB, ENABLE);
	//GPIO set up for PA8(green) PA9(blue) PA10(red) 
	//GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_8|GPIO_Pin_9;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
  GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF_PP;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	//GPIO set up for PB13 
	GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_13|GPIO_Pin_14;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
  GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF_PP;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	//PB6 LED
	GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_6;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOB, &GPIO_InitStructure);	
	
	//Timer 1 set up 
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
	
	while(1)
	{
		readFloor();
		DelayMs(3);//can not too fast, maybe need to clear some flag

		TIM_OCInitTypeDef CH1;
    CH1.TIM_OCMode = TIM_OCMode_PWM1;
    CH1.TIM_Pulse = 50;
    CH1.TIM_OutputState = TIM_OutputState_Enable;
    CH1.TIM_OCPolarity = TIM_OCPolarity_High;
    CH1.TIM_OutputNState = TIM_OutputNState_Disable;
    CH1.TIM_OCNPolarity = TIM_OCNPolarity_Low;
    TIM_OC1Init(TIM1, &CH1); 
    TIM_OCInitTypeDef CH2;
    CH2.TIM_OCMode = TIM_OCMode_PWM1;
    CH2.TIM_Pulse = 50;
    CH2.TIM_OutputState = TIM_OutputState_Disable;
    CH2.TIM_OCPolarity = TIM_OCPolarity_Low;
    CH2.TIM_OutputNState = TIM_OutputNState_Enable;
    CH2.TIM_OCNPolarity = TIM_OCNPolarity_High;
    TIM_OC2Init(TIM1, &CH2);
	}
}
void readFloor() 
{
	// Set PA7 to 1
	GPIO_SetBits(GPIOA, GPIO_Pin_7);
	DelayMs(1);
	// Initialize the data transmission from the master to the slave
	SPI_I2S_SendData(SPI1, 0);
	// Enable the interrupt to receive data by using the ISR handler
	NVIC_EnableIRQ(SPI1_IRQn);;
}
// put the readings to the variable c
void SPI1_IRQHandler() 
{
	// the received character has all the readings
	 c = (char) SPI_I2S_ReceiveData(SPI1) & 0xff;
	
	if (GPIO_ReadOutputDataBit(GPIOA, GPIO_Pin_7) == 1) 
	{
	  // Set PA7 to 0 to trigger the shift register
	  GPIO_ResetBits(GPIOA, GPIO_Pin_7);
	  // Go to get the next reading
	  SPI_I2S_SendData(SPI1, 0);
		
	} 
	else 
	{
		if((c&(1<<0)) && (c&(1<<7)) && (repeat == 0)) //reading all 00000000
		{
			repeat = 1;
			count++;
		}
		if(count == 12)
		{
			PWMmode = 17;
			count++;
		}else if(count == 5)
		{
			PWMmode = 10;
			count++;
		}
		else{
		if((!(c&(1<<0)) && !(c&(1<<1)) && !(c&(1<<2)) && !(c&(1<<3)) && !(c&(1<<4)) && !(c&(1<<5)) && !(c&(1<<6)) && !(c&(1<<7))) || (!(c&(1<<0)) && !(c&(1<<1)) && !(c&(1<<2)) && !(c&(1<<3)) && !(c&(1<<4)) && !(c&(1<<5)) && !(c&(1<<6)) && (c&(1<<7))))
		{
			PWMmode = 18;
		}else
		{
			if(!(c&(1<<7)) || !(c&(1<<0)))
			{
				repeat = 0;
			}
			if(count == 13 || count == 14 || count == 15 || count == 16)
			{
				if (c&(1<0)){
					PWMmode = 16;	
				}else if (c&(1<<1)) { // Right
					PWMmode = 16;	
				}else if(c&(1<<7))			//Middle mode
				{
					PWMmode = 15;	// Left
				}else if (c&(1<<6)) {
					PWMmode = 15;	
				}else if (c&(1<<5)) {
					PWMmode = 13;	 
				}else if (c&(1<<2)) {
					PWMmode = 14;	
				}else if (c&(1<<4)) {
					PWMmode = 13;	
				}else if (c&(1<<3)) {
					PWMmode = 14;	
				}
			}else if(count == 6)
			{
				if(c&(1<<7))			//Middle mode
				{
					PWMmode = 15;	// Left
				}else if (c&(1<0)){
					count = 7;
				}else if (c&(1<<6)) {
					PWMmode = 15;	
				}else if (c&(1<<1)) { // Right
					PWMmode = 16;	
				}else if (c&(1<<5)) {
					PWMmode = 13;	 
				}else if (c&(1<<2)) {
					PWMmode = 14;	
				}else if (c&(1<<3)) {
					PWMmode = 14;	
				}else if (c&(1<<4)) {
					PWMmode = 13;	
				}else {
					pwm(0,40);
				}
			}else if(count == 2 || count == 4 || count == 9 || count == 11) //Slow mode, before count==9 no 8
			{
				if (c&(1<<0)) {
				pwm(50, 35);	// Hard right before marco pwm(40, 30);
			}else if (c&(1<<1)) {
				pwm(70, 40);	// Right before marco pwm(40, 30);
			}else if (c&(1<<2)) {
				pwm(60, 32);	//62,32
			}else if (c&(1<<3)) {
				pwm(60, 36);	// 
			}else if (c&(1<<4)){
				pwm(40,70);	// Left b4 65
			}else if(c&(1<<5)){
				pwm(35,65);	// Hard Left b4 65
			}else if (c&(1<<6)) {
				PWMmode = 8;	// 
			}else if (c&(1<<7)) {
				PWMmode = 8;	// 
			}
			}
			else{ 
			if (c&(1<<5)) {
				PWMmode = 4;	// 
			}else if (c&(1<<6)){
				PWMmode = 6;	// Left
			}else if (c&(1<<3)) {
				PWMmode = 5;	// 
			}else if(c&(1<<7)	)			//Normal mode
			{
				PWMmode = 6;	// Hard Left
			} else if (c&(1<<4)) {
				PWMmode = 4;	// 
			}else if (c&(1<<2)) {
				PWMmode = 5;	//
			}else if (c&(1<<1)) {
				PWMmode = 7;	// Right
			}else if (c&(1<<0)) {
				PWMmode = 7;	// Hard right
			}
		}
	}
}
	
	
	{
	if(c&(1<<0))
	{
	while(USART_GetFlagStatus(USART2, USART_FLAG_TC) == RESET);	
	USART_SendData(USART2,'0');
	}
	else
	{
	while(USART_GetFlagStatus(USART2, USART_FLAG_TC) == RESET);	
	USART_SendData(USART2,'1');
	}
	if(c&(1<<1))
	{
	while(USART_GetFlagStatus(USART2, USART_FLAG_TC) == RESET);	
	USART_SendData(USART2,'0');
	}
	else
	{
	while(USART_GetFlagStatus(USART2, USART_FLAG_TC) == RESET);	
	USART_SendData(USART2,'1');
	}	
	if(c&(1<<2))
	{
	while(USART_GetFlagStatus(USART2, USART_FLAG_TC) == RESET);	
	USART_SendData(USART2,'0');
	}
	else
	{
	while(USART_GetFlagStatus(USART2, USART_FLAG_TC) == RESET);	
	USART_SendData(USART2,'1');
	}	
	if(c&(1<<3))
	{
	while(USART_GetFlagStatus(USART2, USART_FLAG_TC) == RESET);	
	USART_SendData(USART2,'0');
	}
	else
	{
	while(USART_GetFlagStatus(USART2, USART_FLAG_TC) == RESET);	
	USART_SendData(USART2,'1');
	}	
	if(c&(1<<4))
	{
	while(USART_GetFlagStatus(USART2, USART_FLAG_TC) == RESET);	
	USART_SendData(USART2,'0');
	}
	else
	{
	while(USART_GetFlagStatus(USART2, USART_FLAG_TC) == RESET);	
	USART_SendData(USART2,'1');
	}	
	if(c&(1<<5))
	{
	while(USART_GetFlagStatus(USART2, USART_FLAG_TC) == RESET);	
	USART_SendData(USART2,'0');
	}
	else
	{
	while(USART_GetFlagStatus(USART2, USART_FLAG_TC) == RESET);	
	USART_SendData(USART2,'1');
	}	
	if(c&(1<<6))
	{
	while(USART_GetFlagStatus(USART2, USART_FLAG_TC) == RESET);	
	USART_SendData(USART2,'0');
	}
	else
	{
	while(USART_GetFlagStatus(USART2, USART_FLAG_TC) == RESET);	
	USART_SendData(USART2,'1');
	}	
	if(c&(1<<7))
	{
	while(USART_GetFlagStatus(USART2, USART_FLAG_TC) == RESET);	
	USART_SendData(USART2,'0');
	}
	else
	{
	while(USART_GetFlagStatus(USART2, USART_FLAG_TC) == RESET);	
	USART_SendData(USART2,'1');
	}	
		
//	while(USART_GetFlagStatus(USART3, USART_FLAG_TC) == RESET);
//	USART_SendData(USART2, c);
	while(USART_GetFlagStatus(USART2, USART_FLAG_TC) == RESET);
	USART_SendData(USART2, '\r');
	while(USART_GetFlagStatus(USART2, USART_FLAG_TC) == RESET);
	USART_SendData(USART2, '\n');
	}
	
	// Check PA7. If it is 1, it means the data is ready
	
	  // disable the interrupt because it is not ready
	  NVIC_DisableIRQ(SPI1_IRQn);
		
		
	}
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