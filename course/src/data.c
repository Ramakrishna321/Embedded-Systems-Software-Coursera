/**
 * @file data.c
 * @brief Abstraction of basic data manipulation
 *
 * This implementation file provides an abstraction of the two basic functions
 * of converting ascii to integer and vice versa.
 * 
 * @author Venkata Ramakrishna Chivukula
 * @date February 12 2018
 *
 */
 #include <stdint.h>
 #include "data.h"

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base){
  int neg = 0;
  int temp = 0;
  int i = 0;
  
  if(data<0){
    neg = 1;
    data=data*(-1);
    *ptr=45;
  }
     
  for( ; data>0; data/=base, i++){
    *(ptr+i+neg)=(data%base)+48;
    if(data%base>9){
      *(ptr+i+neg)+=8;
    }
  }
  
  int length = i;
  
  for(int i =0; i<length/2 ;i++){
    temp = *(ptr+i+neg);
    *(ptr+i+neg)=*(ptr+length-1-i+neg);
    *(ptr+length-1-i+neg)=temp;
  }
  
    
  *(ptr+length+neg)= 0;
  length++;
  return length;
}
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base){ 
  int neg = 0;
  int num = 0;
  int i = 0;
  int length = 0;
  int place=1;
  
  if (*ptr==45){
    neg = 1;
    i++;
  }
  
  for(length=0; *(ptr+neg+length)!= 0;length++ );
  
  length--;  
  for(;length>=0;length--){
    if(*(ptr+neg+length)>47&&*(ptr+neg+length)<58){
      num=num+(((*(ptr+neg+length)-48)*place));
    }
    if(*(ptr+neg+length)>64&&*(ptr+neg+length)<71){
      num=num+(((*(ptr+neg+length)-55)*place));
    }  
    place=place*base;
  }
  if (neg==1){
    num=num*(-1);
  }

  return num;
}
