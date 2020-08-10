/******************************************************************************
 * Copyright (C) 2020 by Cesar Oliveros - Universidad de Carabobo
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Cesar Oliveros and the University of Carabobo are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file data.c
 * @brief <Add Brief Description Here >
 *
 * <Add Extended Description Here>
 *
 * @author Cesar Oliveros
 * @date 7/08/2020
 *
 */

#include <stdint.h>
#include "data.h"

#define NUMBER_OFFSET 48
#define LETTER_OFFSET (NUMBER_OFFSET + 7)
#define FALSE 0
#define TRUE 1
#undef NULL
#define NULL 0

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base)
{
    uint32_t dec_offset = 1000000000;
    uint8_t * init = ptr;
    uint8_t tmp, digits = 0;
    int8_t i, sign = FALSE;
    int offset;
    if( ! (base == 2 || base == 8 || base == 10 || base == 16))
        return NULL;

    if(data < 0)
    {
        sign = TRUE;
        data *= -1;
    }
    /* 33 characters long maximum */
    if(base == 2)
    {
        if(data < 0) *(--ptr) = '1';
        for(i = 31; i >= 0; i--)
        {
            tmp = (data >> i) & 0x01;
            *ptr++ = tmp + NUMBER_OFFSET;
            digits++;
        }
    }
    /* 13 characters long maximum (counting minus '-' and null terminator) */
    else if(base == 8)
    {
        for(i = 30; i >= 0; i -= 3)
        {
            tmp = (data >> i) & 0x07;
            *ptr++ = tmp + NUMBER_OFFSET;
            digits++;
        }
    }
    /* 12 characters long maximum (counting minus '-' and null terminator) */
    else if(base == 10)
    {
        for(i = 0; i < 10; i++)
        {
            tmp = data / (dec_offset) - (data / (dec_offset * 10)) * 10;
            dec_offset /= 10;
            *ptr++ = tmp + NUMBER_OFFSET;
            digits++;
        }
    }
    /* 10 characters long maximum (counting minus '-' and null terminator) */
    else if(base == 16)
    {
        for(i = 28; i >= 0; i -= 4)
        {
            tmp = (data >> i) & 0x0F;
            if(tmp < 10)
                *ptr++ = tmp + NUMBER_OFFSET;
            else
                *ptr++ = tmp + LETTER_OFFSET;
            digits++;
        }
    }
    offset = digits;
    ptr = init;
    while(*ptr == '0')
    {
        ptr++;
        digits--;
    }
    ptr = init;
    offset -= digits;
    if(sign)
    {
        *ptr++ = '-';
    }
    for(i = 0; i < digits; i++)
    {
        *ptr = *(ptr + offset - sign);
        ptr++;
    }
    *ptr = NULL;
    ptr = init;
    return digits;
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base)
{
    int32_t converted = 0;
    int32_t radix = 1;
    int32_t tmp;
    int8_t sign = 1;
    uint8_t * init = ptr;
    uint8_t i;
    if( ! (base == 2 || base == 8 || base == 10 || base == 16))
        //#error "parameter 'base' in my_itoa() must be either 2, 8, 10 or 16"
        return NULL;

    if(*ptr == '-')
    {
        sign = -1;
        ptr++;
    }
    while(digits != 0)
    {
        digits--;
        for(i = 0; i < digits; i++)
        {
            radix *= base;
        }
        if(*ptr >= LETTER_OFFSET)
            tmp = (*ptr++ - LETTER_OFFSET) * radix;
        else
            tmp = (*ptr++ - NUMBER_OFFSET) * radix;
        converted += tmp;
        radix = 1;
    }
    ptr = init;
    return converted * sign;
}
