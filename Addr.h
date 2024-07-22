typedef unsigned int uint32_t;


#define RCC_BASE        0x40023800
#define GPIOC_BASE      0x40020000
#define RCC_AHB1ENR_OFFSET  0x30
#define GPIOC_MODER_OFFSET  0x00
#define GPIOC_ODR_OFFSET    0x14
#define RCC_AHB1ENR    (*(volatile uint32_t *)(RCC_BASE + RCC_AHB1ENR_OFFSET))
#define GPIOC_MODER    (*(volatile uint32_t *)(GPIOC_BASE + GPIOC_MODER_OFFSET))
#define GPIOC_ODR      (*(volatile uint32_t *)(GPIOC_BASE + GPIOC_ODR_OFFSET))


