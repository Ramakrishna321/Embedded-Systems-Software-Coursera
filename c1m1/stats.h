/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.h
 * @brief Header file for the application to perform statistical analysis.
 *
 * This is the header file for a simple program to perform statistical analysis 
 * on a dataset. The statistical analysis includes finding mean, maximum, 
 * minimum, and other such operations.
 * 
 * @author <Venkata Ramkrishna Chivukula>
 * @date <20/01/2018 >
 *
 */

#ifndef __STATS_H__
#define __STATS_H__


/**
 * @brief Prints the statistics of a given array to the screen
 *
 * This function takes as an input unsigned char pointer of the array and a
 * 32-bit unsigned integer defining the size of the array and prints the 
 * statistics of the array to the screen
 * The statistics are 
 *                 - minimum
 *                 - maximum
 *                 - mean 
 *                 - median
 *
 * @param ptr The pointer to the array whose statistics have to be printed.
 * @param length The length of the array that has been pointed to in the ptr input.
 *
 */
void print_statistics(unsigned char * ptr, int length);

/**
 * @brief Prints the given array to the screen
 *
 * This function takes as an input unsigned char pointer of the array and a
 * 32-bit integer defining the size of the array and prints the array to the screen
 *
 *
 * @param ptr The pointer to the array which has to be printed.
 * @param length The length of the array that has been pointed to in the ptr input.
 *
 */
void print_array(unsigned char * ptr, int length);

/**
 * @brief Outputs the median of a given array
 *
 * This function takes as an input unsigned char pointer of the array and a
 * 32-bit integer defining the size of the array and returns the median of
 * the array
 *
 * @param ptr The pointer to the array whose median has to be found.
 * @param length The length of the array that has been pointed to in the ptr input.
 *
 * @return Returns the value of the median of the array
 */
unsigned char find_median(unsigned char * ptr, int length);

/**
 * @brief Outputs the mean of a given array
 *
 * This function takes as an input unsigned char pointer of the array and a
 * 32-bit integer defining the size of the array and returns the mean of the
 * array
 *
 * @param ptr The pointer to the array whose mean has to be found.
 * @param length The length of the array that has been pointed to in the ptr input.
 *
 * @return Returns the value of the mean of the array
 */
unsigned char find_mean(unsigned char * ptr, int length);

/**
 * @brief Outputs the value of the largest element in a given array
 *
 * This function takes as an input unsigned char pointer of the array and a
 * 32-bit integer defining the size of the array and returns the value of 
 * the largest element in a given array
 *
 * @param ptr The pointer to the array whose maximum has to be found.
 * @param length The length of the array that has been pointed to in the ptr input.
 *
 * @return Returns the value of the largest element in the array
 */
unsigned char find_maximum(unsigned char * ptr, int length);

/**
 * @brief Outputs the value of the smallest element in a given array
 *
 * This function takes as an input unsigned char pointer of the array and a
 * 32-bit integer defining the size of the array and returns the value of 
 * the smallest element in a given array
 *
 * @param ptr The pointer to the array whose minimum has to be found.
 * @param length The length of the array that has been pointed to in the ptr input.
 *
 * @return Returns the value of the smallest element in the array
 */
unsigned char find_minimum(unsigned char * ptr, int length);

/**
 * @brief Sorts the given array in a descending order
 *
 * This function takes as an input unsigned char pointer of the array and a
 * 32-bit integer defining the size of the array. It will then sort the array
 * in a descending order that is, the largest element will be at the first 
 * position and the smallest will be at the last. 
 *
 * @param ptr The pointer to the array which has to be sorted.
 * @param length The length of the array that has been pointed to in the ptr 
 * input.
 *
 */
void sort_array(unsigned char * ptr, int length);

#endif /* __STATS_H__ */
