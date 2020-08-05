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
 * @file <stats.h>
 * @brief <Header file of status.c>
 *
 * <Add Extended Description Here>
 *
 * @author Cesar Oliveros
 * @date 5/08/2020
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */ 

/**
 * @brief A function that prints the statistics of an array including minimum, maximum, mean, and median.
 *
 * <Add Extended Description Here>
 *
 * @param ptr pointer to an n-element array
 * @param size size of the array
 *
 * @return none
 */
unsigned int print_statistics(unsigned char * ptr,unsigned int size);

/**
 * @brief Given an array of data and a length, prints the array to the screen.
 *
 * <Add Extended Description Here>
 *
 * @param ptr pointer to an n-element array
 * @param size size of the array
 *
 * @return none
 */
void print_array(unsigned char * ptr,unsigned int size);

/**
 * @brief Given an array of data and a length, returns the median value.
 *
 * <Add Extended Description Here>
 *
 * @param ptr pointer to an n-element array
 * @param size size of the array
 *
 * @return The median value
 */
unsigned int find_median(unsigned char * ptr,unsigned int size);

/**
 * @brief Given an array of data and a length, returns the mean.
 *
 * <Add Extended Description Here>
 *
 * @param ptr pointer to an n-element array
 * @param size size of the array
 *
 * @return The mean value
 */
unsigned int find_mean(unsigned char * ptr,unsigned int size);

/**
 * @brief Given an array of data and a length, returns the maximum.
 *
 * <Add Extended Description Here>
 *
 * @param ptr pointer to an n-element array
 * @param size size of the array
 *
 * @return The maximum value
 */
unsigned int find_maximum(unsigned char * ptr,unsigned int size);

/**
 * @brief Given an array of data and a length, returns the minimum.
 *
 * <Add Extended Description Here>
 *
 * @param ptr pointer to an n-element array
 * @param size size of the array
 *
 * @return The minimum value
 */
unsigned int find_minimum(unsigned char * ptr,unsigned int size);

/**
 * @brief Given an array of data and a length, sorts the array from largest to smallest.
 *
 * <Add Extended Description Here>
 *
 * @param ptr pointer to an n-element array
 * @param size size of the array
 *
 * @return 1 if done, 0 if some error.
 */
unsigned int sort_array(unsigned char * ptr,unsigned int size);

#endif /* __STATS_H__ */
