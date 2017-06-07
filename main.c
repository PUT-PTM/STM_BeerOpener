#include "stm32f4xx_adc.h"
#include "stm32f4xx_conf.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_tim.h"
#include "stm32f4xx_exti.h"
#include "misc.h"


const int relay1Pin =  GPIO_Pin_8;      // the number of the Realy1 pin
const int relay2Pin =  GPIO_Pin_9;      // the number of the Relay2 pin
const int sensorPin_linear_actuator = GPIO_Pin_1; //select the input pin for the potentiometer
const int sensorPin_FSR = GPIO_Pin_0;// select the input pin for FSR

// variables will change:

float CurrentPosition = 0; // variable to store the value coming from the potentiometer
float sensorValue = 0;  // variable to store the value coming from the FSR
int CheckPos = 0;

int main(void)
{
	SystemInit();
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA , ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB , ENABLE);

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC2, ENABLE);

	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin = sensorPin_linear_actuator | sensorPin_FSR;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AN;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOA, &GPIO_InitStructure);


	GPIO_InitStructure.GPIO_Pin =
	relay1Pin | relay2Pin;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOB, &GPIO_InitStructure);

	GPIO_SetBits(GPIOB, relay1Pin);
	GPIO_SetBits(GPIOB, relay2Pin);


	ADC_CommonInitTypeDef ADC_CommonInitStructure;
	ADC_CommonInitStructure.ADC_Mode = ADC_Mode_Independent;
	ADC_CommonInitStructure.ADC_Prescaler = ADC_Prescaler_Div2;
	ADC_CommonInitStructure.ADC_DMAAccessMode = ADC_DMAAccessMode_Disabled;
	ADC_CommonInitStructure.ADC_TwoSamplingDelay = ADC_TwoSamplingDelay_5Cycles;
	ADC_CommonInit(&ADC_CommonInitStructure);

	ADC_InitTypeDef ADC_InitStructure;
	ADC_InitStructure.ADC_Resolution = ADC_Resolution_12b;
	ADC_InitStructure.ADC_ScanConvMode = DISABLE;
	ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;
	ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_T1_CC1;
	ADC_InitStructure.ADC_ExternalTrigConvEdge = ADC_ExternalTrigConvEdge_None;
	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
	ADC_InitStructure.ADC_NbrOfConversion = 1;
	ADC_Init(ADC1, &ADC_InitStructure);
	ADC_Init(ADC2, &ADC_InitStructure);

	ADC_RegularChannelConfig(ADC1, ADC_Channel_1, 1, ADC_SampleTime_84Cycles);
	ADC_Cmd(ADC1, ENABLE);
	ADC_RegularChannelConfig(ADC2, ADC_Channel_0, 1, ADC_SampleTime_84Cycles);
	ADC_Cmd(ADC2, ENABLE);

	while(1)
    {
		ADC_SoftwareStartConv(ADC1);
		while(ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) == RESET);
		CurrentPosition = ADC_GetConversionValue(ADC1);

		ADC_SoftwareStartConv(ADC2);
		while(ADC_GetFlagStatus(ADC2, ADC_FLAG_EOC) == RESET);
		sensorValue = ADC_GetConversionValue(ADC2);

				if (sensorValue > 2000) {
						GPIO_ResetBits(GPIOB, relay1Pin);
						GPIO_ResetBits(GPIOB, relay2Pin);
						CheckPos = 0;
				}
				if (sensorValue < 2000) {
					if(CheckPos == 0){
						GPIO_SetBits(GPIOB, relay1Pin);
						GPIO_SetBits(GPIOB, relay2Pin);
						CheckPos = 1;
						for(int i=0;i<100000;i++);
					}
					GPIO_ResetBits(GPIOB, relay1Pin);
					GPIO_SetBits(GPIOB, relay2Pin);

				}


    }
}

