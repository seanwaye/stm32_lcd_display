#include <stm32f10x.h>


/************************** SPI Flash 连接引脚定义********************************/
#define SPI_APBxClock_FUN           RCC_APB2PeriphClockCmd
#define SPI_CLK                     RCC_APB2Periph_SPI1

#define SPI_SCK_APBxClock_FUN       RCC_APB2PeriphClockCmd
#define SPI_SCK_CLK                 RCC_APB2Periph_GPIOA   
#define SPI_SCK_PORT                GPIOA   
#define SPI_SCK_PIN                 GPIO_Pin_5

#define SPI_MISO_APBxClock_FUN      RCC_APB2PeriphClockCmd
#define SPI_MISO_CLK                RCC_APB2Periph_GPIOA    
#define SPI_MISO_PORT               GPIOA 
#define SPI_MISO_PIN                GPIO_Pin_6

#define SPI_MOSI_APBxClock_FUN      RCC_APB2PeriphClockCmd
#define SPI_MOSI_CLK                RCC_APB2Periph_GPIOA    
#define SPI_MOSI_PORT               GPIOA 
#define SPI_MOSI_PIN                GPIO_Pin_7

#define SPI_CS_APBxClock_FUN        RCC_APB2PeriphClockCmd
#define SPI_CS_CLK                  RCC_APB2Periph_GPIOA    
#define SPI_CS_PORT                 GPIOA
#define SPI_CS_PIN                  GPIO_Pin_4

#define SPI_CS_ENABLE()             GPIO_ResetBits(SPI_CS_PORT, SPI_CS_PIN)
#define SPI_CS_DISABLE()            GPIO_SetBits(SPI_CS_PORT, SPI_CS_PIN)


#define DATA_VALID 0
#define DATA_INVALID 1

//用于表示当前spi处于什么状态
#define SEARCH 0
#define GET_HEAD 1
#define GET_DATA 2

//帧起始位
#define FRAME_START 0x1234

//帧类型
#define FRAME_TYPE_IMAGE 1
#define FRAME_TYPE_STATUS 2
#define FRAME_TYPE_CMD 3

//取得帧头各个域
#define get_frame_type(p)  (*(u8*)(p))
#define get_frame_id(p)  (*((u8*)(p)+1))
#define get_frame_length(p)  (*(u32*)((u8*)(p)+2))

//帧的计量数据
#define FRAME_HEAD_SIZE 6

void SPI_init(void);
void send_fram(void *fram_head_p,void * data);

