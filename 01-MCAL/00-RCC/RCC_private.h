/*************************************************************/
/*************************************************************/
/************ Author  : Mohamed Hassan Hassan     ************/
/************ Layer   : MCAL                      ************/
/************ Version : 2.00                      ************/
/************ SWC     : RCC                       ************/
/*************************************************************/
/*************************************************************/

#ifndef _RCC_PRIVATE_H_
#define _RCC_PRIVATE_H_


#define RCC_ENABLE                        1
#define RCC_DISABLE                       0


#define RCC_BASE_ADDRESS                  0x40023800

typedef struct
{
	volatile u32 CR;
	volatile u32 PLLCFGR;
	volatile u32 CFGR;
	volatile u32 CIR;
	volatile u32 AHB1RSTR;
	volatile u32 AHB2RSTR;
	volatile u32 RESERVED1;
	volatile u32 RESERVED2;
	volatile u32 APB1RSTR;
	volatile u32 APB2RSTR;
	volatile u32 RESERVED3;
	volatile u32 RESERVED4;
	volatile u32 AHB1ENR;
	volatile u32 AHB2ENR;
	volatile u32 RESERVED5;
	volatile u32 RESERVED6;
	volatile u32 APB1ENR;
	volatile u32 APB2ENR;
	volatile u32 RESERVED7;
	volatile u32 RESERVED8;
	volatile u32 AHB1LPENR;
	volatile u32 AHB2LPENR;
	volatile u32 RESERVED9;
	volatile u32 RESERVED10;
	volatile u32 APB1LPENR;
	volatile u32 APB2LPENR;
	volatile u32 RESERVED11;
	volatile u32 RESERVED12;
	volatile u32 BDCR;
	volatile u32 CSR;
	volatile u32 RESERVED13;
	volatile u32 RESERVED14;
	volatile u32 SSCGR;
	volatile u32 PLLI2SCFGR;
	volatile u32 RESERVED15;
	volatile u32 DCKCFGR;
}RCC_t;

/* Pointer to struct */
#define RCC     ((volatile RCC_t*)(RCC_BASE_ADDRESS))


/********************************************/
/* Pins of RCC_CR, RCC_PLLCFGR and PLL_CFGR */
/********************************************/
typedef enum
{
	HSION,
	HSIRDY,
	HSITIRM = 3,
	HSICAL  = 8,
	HSEON   = 16,
	HSERDY,
	HSEBYP,
	CSSON,
	PLLON   = 24,
	PLLRDY,
	PLLI2SON,
	PLLI2SRDY
}RCC_CR_t;


typedef enum
{
	PLLM,
	PLLN   = 6,
	PLLP   = 16,
	PLLSRC = 22,
	PLLQ   = 24
}RCC_PLLCFGR_t;


typedef enum
{
	SW,
	SWS      = 2,
	HPRE     = 4,
	PPRE1    = 10,
	PPRE2    = 13,
	RTCPRE   = 16,
	MCO1     = 21,
	I2SSRC   = 23,
	MCO1PRE,
	MCO2PRE  = 27,
	MCO2     = 30
}RCC_CFGR_t;


/****************************************/
/* enum for storing some important data */
/****************************************/
typedef enum
{
	RCC_HSI,
	RCC_HSE,
	RCC_PLL
}SysClk;


typedef enum
{
	APB_NO,
	APB_PRE_2   = 4,
	APB_PRE_4,
	APB_PRE_8,
	APB_PRE_16,
	APB_Default = 0,
}APB_PreScaler;



typedef enum
{
	AHB_NO,
	AHB_PRE_2    = 8,
	AHB_PRE_4,
	AHB_PRE_8,
	AHB_PRE_16,
	AHB_PRE_64,
	AHB_PRE_128,
	AHB_PRE_256,
	AHB_PRE_512,
	AHB_Default  = 0,
}AHB_PreScaler;


typedef enum
{
	MCO1_HSI,
	MCO1_LSE,
	MCO1_HSE,
	MCO1_PLL,
	MCO1_Default = MCO1_HSI
}MCO1_Source;


typedef enum
{
	MCO2_SYSTICK,
	MCO2_PLLI2S,
	MCO2_HSE,
	MCO2_PLL,
	MCO2_Default = MCO2_SYSTICK
}MCO2_Source;

typedef enum
{
	No_Division,
	Division_By_2,
	Division_By_3,
	Division_By_4,
	Division_By_5
}MCO_Div;


typedef enum
{
	PLLP_2,
	PLLP_4,
	PLLP_6,
	PLLP_8,
}RCC_PLL_Div;



/******************************************/
/* Default values for some configurations */
/******************************************/
#define RCC_PLLM_DEFAULT                      0x010000
#define RCC_PLLN_DEFAULT                      0x011000000
#define RCC_PLLP_DEFAULT                      PLLP_2
#define RCC_PLLQ_DEFAULT                      4
#define RCC_DEFAULT_TRIMMING_VALUE            16

/*************************************/
/* Number of Peripherals on each Bus */
/*************************************/
#define RCC_AHB1_PERIPHERAL_NUMBER        23
#define RCC_AHB2_PERIPHERAL_NUMBER        31
#define RCC_APB1_PERIPHERAL_NUMBER        60
#define RCC_APB2_PERIPHERAL_NUMBER        79



#define RCC_I2S_CLOCK                         0
#define RCC_I2S_EXTERNAL                      1




#endif /* RCC_PRIVATE_H_ */
