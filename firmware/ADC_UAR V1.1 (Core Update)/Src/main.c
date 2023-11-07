/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
ADC_HandleTypeDef hadc1;

TIM_HandleTypeDef htim2;

UART_HandleTypeDef huart1;

/* USER CODE BEGIN PV */
uint16_t count = 0;
volatile uint8_t rx_byte;
volatile uint8_t rx2_byte[20];
volatile uint16_t tx_byte;
volatile char tx2_byte[4];
volatile char ADC_Label[20];
volatile uint8_t valor = 0;
uint16_t readValue1;
uint16_t readValue2;
uint16_t readValue3;
uint16_t readValue4;
uint16_t readValue5;
uint16_t readValue6;
uint16_t readValue7;
uint16_t readValue8;
uint8_t value = 0;
ADC_ChannelConfTypeDef sConfigPrivate = {0};
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART1_UART_Init(void);
static void MX_ADC1_Init(void);
static void MX_TIM2_Init(void);
/* USER CODE BEGIN PFP */
void Receiver(uint8_t dato);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART1_UART_Init();
  MX_ADC1_Init();
  MX_TIM2_Init();
  /* USER CODE BEGIN 2 */
  HAL_UART_Receive_IT(&huart1, (uint8_t *)(&rx_byte), 4);
  HAL_UART_Transmit_IT(&huart1, (uint8_t *)(&tx_byte), 4);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */

  while (1)
  {
	  sConfigPrivate.Rank = ADC_REGULAR_RANK_1;
	  sConfigPrivate.SamplingTime = ADC_SAMPLETIME_1CYCLE_5;

	  sConfigPrivate.Channel = ADC_CHANNEL_7;
	  HAL_ADC_ConfigChannel(&hadc1, &sConfigPrivate);
	  HAL_ADC_Start(&hadc1);
	  HAL_ADC_PollForConversion(&hadc1,1000);
	  readValue8 = HAL_ADC_GetValue(&hadc1);
	  HAL_ADC_Stop(&hadc1);

	  sConfigPrivate.Channel = ADC_CHANNEL_6;
	  HAL_ADC_ConfigChannel(&hadc1, &sConfigPrivate);
	  HAL_ADC_Start(&hadc1);
	  HAL_ADC_PollForConversion(&hadc1,1000);
	  readValue7 = HAL_ADC_GetValue(&hadc1);
	  HAL_ADC_Stop(&hadc1);

	  sConfigPrivate.Channel = ADC_CHANNEL_5;
	  HAL_ADC_ConfigChannel(&hadc1, &sConfigPrivate);
	  HAL_ADC_Start(&hadc1);
	  HAL_ADC_PollForConversion(&hadc1,1000);
	  readValue6 = HAL_ADC_GetValue(&hadc1);
	  HAL_ADC_Stop(&hadc1);

	  sConfigPrivate.Channel = ADC_CHANNEL_4;
	  HAL_ADC_ConfigChannel(&hadc1, &sConfigPrivate);
	  HAL_ADC_Start(&hadc1);
	  HAL_ADC_PollForConversion(&hadc1,1000);
	  readValue5 = HAL_ADC_GetValue(&hadc1);
	  HAL_ADC_Stop(&hadc1);

	  sConfigPrivate.Channel = ADC_CHANNEL_3;
	  HAL_ADC_ConfigChannel(&hadc1, &sConfigPrivate);
	  HAL_ADC_Start(&hadc1);
	  HAL_ADC_PollForConversion(&hadc1,1000);
	  readValue4 = HAL_ADC_GetValue(&hadc1);
	  HAL_ADC_Stop(&hadc1);

	  sConfigPrivate.Channel = ADC_CHANNEL_2;
	  HAL_ADC_ConfigChannel(&hadc1, &sConfigPrivate);
	  HAL_ADC_Start(&hadc1);
	  HAL_ADC_PollForConversion(&hadc1,1000);
	  readValue3 = HAL_ADC_GetValue(&hadc1);
	  HAL_ADC_Stop(&hadc1);

	  sConfigPrivate.Channel = ADC_CHANNEL_1;
	  HAL_ADC_ConfigChannel(&hadc1, &sConfigPrivate);
	  HAL_ADC_Start(&hadc1);
	  HAL_ADC_PollForConversion(&hadc1,1000);
	  readValue2 = HAL_ADC_GetValue(&hadc1);
	  HAL_ADC_Stop(&hadc1);

	  sConfigPrivate.Channel = ADC_CHANNEL_0;
	  HAL_ADC_ConfigChannel(&hadc1, &sConfigPrivate);
	  HAL_ADC_Start(&hadc1);
	  HAL_ADC_PollForConversion(&hadc1,1000);
	  readValue1 = HAL_ADC_GetValue(&hadc1);
	  HAL_ADC_Stop(&hadc1);
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */

	  if(rx_byte){
		  Receiver(rx_byte);
		  HAL_UART_Receive_IT(&huart1, (uint8_t *)(&rx_byte), 1);
		  rx_byte = 0;
	  }
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_ADC;
  PeriphClkInit.AdcClockSelection = RCC_ADCPCLK2_DIV2;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief ADC1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_ADC1_Init(void)
{

  /* USER CODE BEGIN ADC1_Init 0 */

  /* USER CODE END ADC1_Init 0 */

  ADC_ChannelConfTypeDef sConfig = {0};

  /* USER CODE BEGIN ADC1_Init 1 */

  /* USER CODE END ADC1_Init 1 */

  /** Common config
  */
  hadc1.Instance = ADC1;
  hadc1.Init.ScanConvMode = ADC_SCAN_DISABLE;
  hadc1.Init.ContinuousConvMode = ENABLE;
  hadc1.Init.DiscontinuousConvMode = DISABLE;
  hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc1.Init.NbrOfConversion = 1;
  if (HAL_ADC_Init(&hadc1) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Regular Channel
  */
  sConfig.Channel = ADC_CHANNEL_2;
  sConfig.Rank = ADC_REGULAR_RANK_1;
  sConfig.SamplingTime = ADC_SAMPLETIME_1CYCLE_5;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN ADC1_Init 2 */

  /* USER CODE END ADC1_Init 2 */

}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 127;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 625;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */

}

/**
  * @brief USART1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 9600;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_RESET);

  /*Configure GPIO pins : PB12 PB13 PB14 */
  GPIO_InitStruct.Pin = GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : PB15 */
  GPIO_InitStruct.Pin = GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : PA8 */
  GPIO_InitStruct.Pin = GPIO_PIN_8;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

void Receiver(uint8_t dato){
	static index=0;    				//Declaro unafuncion estatica index con valor 0

	if(rx_byte == '#'){
		rx2_byte[0] = rx_byte; 		//Asigna el valor de la variable rx_byte en la posicion 0 del array
		index=1; 					//incrementa el valor de index a 1
	}else if(rx_byte=='*'){   		//si rx_byte es igual a *
		rx2_byte[index++]=rx_byte;  //Asigna el valor de rx_byte a rx2_byte en la posicion de index=1 y aumenta en uno index
		rx2_byte[index]=0; 			// Asigna el valor 0 a la posicion del index
		index=0; 					//Setea el index en 0
		Analizador(); 				//Llama a la funcion Analizador
	}else if(index!=0){ 			//Si index es distinto de la posicion 0
		rx2_byte[index++]=rx_byte;  // Copia el valor de rx_byte en la posicion index del array rx2_byte y lo incrementa en 1
	}
}


void Analizador(void){
	int resu;

	do{
		if(strcmp((const char *)(rx2_byte),"#TEMP*")==0){
			HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_15, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_14, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_13, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_12, GPIO_PIN_RESET);
			tx_byte = readValue1;
			sprintf(tx2_byte, "%d", tx_byte);
			//HAL_UART_Transmit_IT(&huart1, (uint8_t *)(&tx_byte), 4);
			HAL_UART_Transmit_IT(&huart1, (uint8_t *)tx2_byte, strlen(tx2_byte));
			valor = 1;
			break;
		}
		if(strcmp((const char *)(rx2_byte),"#ANEMOMETER*")==0){
			HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_15, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_14, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_13, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_12, GPIO_PIN_RESET);
			tx_byte = readValue2;
			sprintf(tx2_byte, "%d", tx_byte);
			//HAL_UART_Transmit_IT(&huart1, (uint8_t *)(&tx_byte), 4);
			HAL_UART_Transmit_IT(&huart1, (uint8_t *)tx2_byte, strlen(tx2_byte));
			valor = 2;
			break;
		}
		if(strcmp((const char *)(rx2_byte),"#RAIN_DROP*")==0){
			HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_15, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_14, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_13, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_12, GPIO_PIN_RESET);
			tx_byte = readValue3;
			sprintf(tx2_byte, "%d", tx_byte);
			//HAL_UART_Transmit_IT(&huart1, (uint8_t *)(&tx_byte), 4);
			HAL_UART_Transmit_IT(&huart1, (uint8_t *)tx2_byte, strlen(tx2_byte));
			valor = 3;
			break;
		}
		if(strcmp((const char *)(rx2_byte),"#SOIL_MOISTURE*")==0){
			HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_15, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_14, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_13, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_12, GPIO_PIN_RESET);
			tx_byte = readValue4;
			sprintf(tx2_byte, "%d", tx_byte);
			//HAL_UART_Transmit_IT(&huart1, (uint8_t *)(&tx_byte), 4);
			HAL_UART_Transmit_IT(&huart1, (uint8_t *)tx2_byte, strlen(tx2_byte));
			valor = 4;
			break;
		}
		if(strcmp((const char *)(rx2_byte),"#UV_LEVEL*")==0){
			HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_15, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_14, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_13, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_12, GPIO_PIN_SET);
			tx_byte = readValue5;
			sprintf(tx2_byte, "%d", tx_byte);
			//HAL_UART_Transmit_IT(&huart1, (uint8_t *)(&tx_byte), 4);
			HAL_UART_Transmit_IT(&huart1, (uint8_t *)tx2_byte, strlen(tx2_byte));
			valor = 5;
			break;
		}
		if(strcmp((const char *)(rx2_byte),"#OFF*")==0){
			HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_15, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_14, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_13, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_12, GPIO_PIN_RESET);
			rx_byte=0;
			tx_byte=0;
			sprintf(tx2_byte, "%d", tx_byte);
			HAL_UART_Transmit_IT(&huart1, (uint8_t *)tx2_byte, strlen(tx2_byte));
			break;
		}
		if(strcmp((const char )(rx2_byte),"#DEBUG")==0){
					valor=6;
					while (valor == 6){
						HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8, GPIO_PIN_SET);
						HAL_GPIO_WritePin(GPIOB,GPIO_PIN_15, GPIO_PIN_RESET);
						HAL_GPIO_WritePin(GPIOB,GPIO_PIN_14, GPIO_PIN_RESET);
						HAL_GPIO_WritePin(GPIOB,GPIO_PIN_13, GPIO_PIN_RESET);
						HAL_GPIO_WritePin(GPIOB,GPIO_PIN_12, GPIO_PIN_RESET);
						tx_byte = readValue1;
						sprintf(tx2_byte, "%d", tx_byte);
						strcpy(ADC_Label,"#TEMP*");
						HAL_UART_Transmit_IT(&huart1, (uint8_t *)ADC_Label, strlen(ADC_Label));
						HAL_Delay(100);
						HAL_UART_Transmit_IT(&huart1, (uint8_t *)tx2_byte, strlen(tx2_byte));
						HAL_Delay(100);
						HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8, GPIO_PIN_RESET);
						HAL_GPIO_WritePin(GPIOB,GPIO_PIN_15, GPIO_PIN_SET);
						HAL_GPIO_WritePin(GPIOB,GPIO_PIN_14, GPIO_PIN_RESET);
						HAL_GPIO_WritePin(GPIOB,GPIO_PIN_13, GPIO_PIN_RESET);
						HAL_GPIO_WritePin(GPIOB,GPIO_PIN_12, GPIO_PIN_RESET);
						tx_byte = readValue2;
						sprintf(tx2_byte, "%d", tx_byte);
						strcpy(ADC_Label,"#ANEMOMETER*");
						HAL_UART_Transmit_IT(&huart1, (uint8_t *)ADC_Label, strlen(ADC_Label));
						HAL_Delay(100);
						HAL_UART_Transmit_IT(&huart1, (uint8_t *)tx2_byte, strlen(tx2_byte));
						HAL_Delay(100);
						HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8, GPIO_PIN_RESET);
						HAL_GPIO_WritePin(GPIOB,GPIO_PIN_15, GPIO_PIN_RESET);
						HAL_GPIO_WritePin(GPIOB,GPIO_PIN_14, GPIO_PIN_SET);
						HAL_GPIO_WritePin(GPIOB,GPIO_PIN_13, GPIO_PIN_RESET);
						HAL_GPIO_WritePin(GPIOB,GPIO_PIN_12, GPIO_PIN_RESET);
						tx_byte = readValue3;
						sprintf(tx2_byte, "%d", tx_byte);
						strcpy(ADC_Label,"#RAIN_DROP*");
						HAL_UART_Transmit_IT(&huart1, (uint8_t *)ADC_Label, strlen(ADC_Label));
						HAL_Delay(100);
						HAL_UART_Transmit_IT(&huart1, (uint8_t *)tx2_byte, strlen(tx2_byte));
						HAL_Delay(100);
						HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8, GPIO_PIN_RESET);
						HAL_GPIO_WritePin(GPIOB,GPIO_PIN_15, GPIO_PIN_RESET);
						HAL_GPIO_WritePin(GPIOB,GPIO_PIN_14, GPIO_PIN_RESET);
						HAL_GPIO_WritePin(GPIOB,GPIO_PIN_13, GPIO_PIN_SET);
						HAL_GPIO_WritePin(GPIOB,GPIO_PIN_12, GPIO_PIN_RESET);
						tx_byte = readValue4;
						sprintf(tx2_byte, "%d", tx_byte);
						strcpy(ADC_Label,"#SOIL_MOISTURE*");
						HAL_UART_Transmit_IT(&huart1, (uint8_t *)ADC_Label, strlen(ADC_Label));
						HAL_Delay(100);
						HAL_UART_Transmit_IT(&huart1, (uint8_t *)tx2_byte, strlen(tx2_byte));
						HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8, GPIO_PIN_RESET);
						HAL_GPIO_WritePin(GPIOB,GPIO_PIN_15, GPIO_PIN_RESET);
						HAL_GPIO_WritePin(GPIOB,GPIO_PIN_14, GPIO_PIN_RESET);
						HAL_GPIO_WritePin(GPIOB,GPIO_PIN_13, GPIO_PIN_RESET);
						HAL_GPIO_WritePin(GPIOB,GPIO_PIN_12, GPIO_PIN_SET);
						tx_byte = readValue5;
						sprintf(tx2_byte, "%d", tx_byte);
						strcpy(ADC_Label,"#UV_LEVEL*");
						HAL_UART_Transmit_IT(&huart1, (uint8_t *)ADC_Label, strlen(ADC_Label));
						HAL_Delay(100);
						HAL_UART_Transmit_IT(&huart1, (uint8_t *)tx2_byte, strlen(tx2_byte));
						HAL_Delay(100);
					}
				}

	}while(0);
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
