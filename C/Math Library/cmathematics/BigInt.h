#include <stdarg.h>
#include <stdio.h>

#include "cmathematics.h"

#ifndef BIGINT_H
#define BIGINT_H

/**
 * structuree representing a BigInt 
 */
typedef struct
{
    bool sign;
    size_t capacity;
    size_t noDigits;
    char* digits;

} BigInt;

extern const BigInt BIGINT_ZERO;

/**
 * @brief 
 * 
 * @param capacity 
 * @return BigInt 
 */
BigInt allocateBigInt(size_t capacity);

/**
 * @brief 
 * 
 * @param str 
 * @return BigInt 
 */
BigInt strToBigInt(char* str);

/**
 * @brief 
 * 
 * @param i 
 * @return BigInt 
 */
BigInt newBigInt(int i);

/**
 * @brief 
 * 
 * @param i 
 * @return BigInt 
 */
BigInt newPositiveBigInt(size_t i);

/**
 * @brief 
 * 
 * @param i 
 * @return char* 
 */
char* BigIntPtrToString(BigInt* i);

/**
 * @brief 
 * 
 * @param i 
 * @return char* 
 */
char* BigIntToString(BigInt i);

/**
 * @brief 
 * 
 * @param i1 
 * @param i2 
 * @return char 
 */
char compareBigInt(BigInt i1, BigInt i2);

/**
 * @brief 
 * 
 * @param i1 
 * @param i2 
 * @return BigInt 
 */
BigInt addBigInt(BigInt i1, BigInt i2);

/**
 * @brief 
 * 
 * @param i1 
 * @param i2 
 * @return BigInt 
 */
BigInt subtractBigInt(BigInt i1, BigInt i2);

#endif // BIGINT_H