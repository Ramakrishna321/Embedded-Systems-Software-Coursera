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
/*
 *
 * @file stats.c
 * @brief Contains main and the definition of the other functions that are going
 * to be used in the application
 *
 * This file contains the definition of the different functions used to perform 
 * the statistical analysis. Upon execution it will print the required data to 
 * the command line such as the maximum value, minimum value, etc.
 *
 * @author Venkata Ramakrishna Chivukula
 * @date 20/01/2018
 *
 */



#include <stdio.h>
#include "stats.h"
#include "platform.h"

/* Size of the Data Set */
#define SIZE (40)

void print_statistics(unsigned char * ptr, int length){
  unsigned char max, min, mean, median;
  max = find_maximum( ptr,  length);
  min = find_minimum( ptr,  length);
  mean = find_mean( ptr,  length);
  median = find_median( ptr,  length);
  PRINTF("The maximum value in the given array is = %d\n", max);
  PRINTF("The minimum value in the given array is = %d\n", min);
  PRINTF("The mean of the given array is = %d\n", mean);
  PRINTF("The median of the given array is = %d\n", median);
}

void print_array(unsigned char * ptr, int length){
  
  for(int i = 0; i < length; i++){
    #ifdef VERBOSE
    PRINTF("Index = %d, Value = %d,\n", i, *( ptr + i));
    #endif
        
  }
}

unsigned char find_median(unsigned char * ptr, int length){
  
  sort_array( ptr , length );
  unsigned char median;
  
  if(length % 2 == 0){
    unsigned char middle = length / 2;
    median = ((* (ptr + middle ))+(* (ptr + middle + 1 ))) / 2;
  }
  else{
    unsigned char middle = length / 2;
    median = (* (ptr + middle ));
  }
  return median;
}

unsigned char find_mean(unsigned char * ptr, int length){
  int sum = 0;
  for(int i = 0; i < length; i++ ){
    sum = sum + * ( ptr + i );
  }
  unsigned char mean = sum / length;
  return mean;
}

unsigned char find_maximum(unsigned char * ptr, int length){
  unsigned char max = * ptr;
  for(int i = 0; i < length; i++){
    if(max < * (ptr + i)){
      max = * (ptr + i);
    }
  }
  return max;
}

unsigned char find_minimum(unsigned char * ptr, int length){
  unsigned char min = * ptr;
  for(int i = 0; i < length; i++){
    if(min > * (ptr + i)){
      min = * (ptr + i);
    }
  }
  return min;
}

void sort_array(unsigned char * ptr, int length){

  for(int i = 0; i<length; i++){
    for(int j = i + 1; j<length; j++){
      if(* (ptr + i) < * (ptr + j) ){
        unsigned char temp = * (ptr + i);
        * (ptr + i) = * (ptr + j);
        * (ptr + j) = temp; 
      }
    }
  }
}
