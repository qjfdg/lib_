/**
  ******************************************************************************
  * @file    bsp_swo.c
  * @author  joe.qiao
  * @version V1.0.0
  * @date    07-September-2016
  * @brief   
  * @COPYRIGHT joe.qiao 
  ******************************************************************************
  * @attention
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include <stdio.h>

#define ITM_Port8(n)    (*((volatile unsigned char *)(0xE0000000+4*n)))
#define ITM_Port16(n)   (*((volatile unsigned short*)(0xE0000000+4*n)))
#define ITM_Port32(n)   (*((volatile unsigned long *)(0xE0000000+4*n)))

#define DEMCR           (*((volatile unsigned long *)(0xE000EDFC)))
#define TRCENA          0x01000000




#ifdef TRACE_SWO

int fputc(int ch, FILE *f) 
{
    if (DEMCR & TRCENA) 
    {
        while (ITM_Port32(0) == 0){;}
        ITM_Port8(0) = ch;
    }
    return(ch);
}

#endif








