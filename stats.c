/******************************************************************************
 * Copyright (C) 2020 by Cesar Oliveros - Universidad de Carabobo
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file status.c
 * @brief <Add Brief Description Here >
 *
 * <Add Extended Description Here>
 *
 * @author Cesar Oliveros
 * @date 5/08/2020
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void print_statistics(unsigned int min, unsigned int max, unsigned int mean, unsigned int median)
{
    printf("minimum: %d\nmaximum: %d\nmean: %d\nmedian: %d\n",min,max,mean,median);
}

void print_array(unsigned char * ptr,unsigned int size)
{
    printf("Array:");
    for(int i=0;i<size;i++)
    {
        printf(" %d,",ptr[i]);
        if(((i + 1) % 8 == 0) && (i+1 != size)) printf("\n      ");
    }
    printf("\b.\n");
}

unsigned int find_median(unsigned char * ptr,unsigned int size)
{
    unsigned int tmp, i;
    sort_array(ptr,size);
    if(size % 2 == 0)
    {
        i = (size / 2) - 1;
        tmp = *(ptr + i) + *(ptr + i + 1);
        tmp /= 2;
    }
    else
    {
        i = (size - 1) / 2;
        tmp = *(ptr + i);
    }
    return tmp;
}

unsigned int find_mean(unsigned char * ptr,unsigned int size)
{
    unsigned tmp = 0;
    for(int i=0;i<size;i++)
    {
        tmp += *(ptr++);
    }
    tmp /= size;
    return tmp;
}

unsigned int find_maximum(unsigned char * ptr,unsigned int size)
{
    unsigned int tmp = *ptr;
    for(int i=0;i<size;i++)
    {
        if(*(++ptr)>tmp) tmp = *ptr;
    }
    return tmp;
}

unsigned int find_minimum(unsigned char * ptr,unsigned int size)
{
    unsigned int tmp = *ptr;
    for(int i=0;i<size-1;i++)
    {
        if(*(++ptr)<tmp) tmp = *ptr;
    }
    return tmp;
}

unsigned int sort_array(unsigned char * ptr, unsigned int size)
{
    unsigned int max, tmpsize;
    unsigned char array[size];
    tmpsize = size;
    for(int i=0;i<size;i++)
    {
        max = find_maximum(ptr++,tmpsize--);
        array[i]=max;
    }
    if(sizeof(array) == size)
    {
        ptr=&array[0];
        return 1;
    }
    else return 0;
}

void main() {

    unsigned int min, max, mean, median;
    unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                                114, 88,   45,  76, 123,  87,  25,  23,
                                200, 122, 150, 90,   92,  87, 177, 244,
                                201,   6,  12,  60,   8,   2,   5,  67,
                                  7,  87, 250, 230,  99,   3, 100,  90};
    min = find_minimum(test, SIZE);
    max = find_maximum(test, SIZE);
    mean = find_mean(test, SIZE);
    median=find_median(test, SIZE);
    print_array(test, SIZE);
    print_statistics(min,max,mean,median);
} /* End main */

