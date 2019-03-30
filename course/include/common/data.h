/**
 * @file data.h
 * @brief Abstraction of basic data manipulation
 *
 * This header file contains basic ascii to integer conversion, integer to ascii 
 *
 * @author Venkata Ramakrishna Chivukula
 * @date February 12 2018
 *
 */
 #ifndef __DATA_H__
 #define __DATA_H__

/**
 * @brief converts integer to ascii value 
 *
 * Given a integer type number, converts it into ascii value according to the 
 * given base value.
 *
 * @param data Value to be converted
 * @param ptr location where the ascii type has to be stored
 * @param base Base of the number being converted
 *
 * @return length of the data
 */
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);

/**
 * @brief converts ascii value to integer 
 *
 * Given a pointer to ascii string, converts it into integer value according to 
 * the given base value.
 *
 * @param ptr location where the ascii type has to be stored
 * @param digits number of digits in the integer
 * @param base Base of the number being converted
 *
 * @return length of the data
 */
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);

#endif
