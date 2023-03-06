#include <stdlib.h>
#include <string.h>

#include "BigInt.h"

const BigInt BIGINT_ZERO = {true, 0, 0, NULL};

/**
 * @brief 
 * 
 * @param capacity 
 * @return BigInt 
 */
BigInt allocateBigInt(size_t capacity)
{
    BigInt ret;
    ret.capacity = capacity;
    ret.noDigits = 0;
    ret.sign = true;
    ret.digits = malloc(capacity * sizeof(char));
    return ret;
}

/**
 * @brief 
 * 
 * @param str 
 * @return BigInt 
 */
BigInt strToBigInt(char* str)
{
    size_t len = strlen(str);
    size_t noDigits = len;

    bool sign = true;
    if (str[0] == '-')
    {
        sign = false;
        noDigits--;
    }
    
    // check for empty string

    BigInt ret = allocateBigInt(noDigits);
    ret.noDigits = noDigits;
    ret.sign = sign;

    for (size_t idx = 0; idx < noDigits; idx++)
    {
        char c = str[len - 1 - idx];

        if (c >= '0' && c <= '9')
        {
            ret.digits[idx] = c - '0';
        }
        else
        {
            return BIGINT_ZERO; 
        }
        
    }
    
    return ret;
}

BigInt newBigInt(int i)
{
    bool sign = true;
    if (i < 0)
    {
        sign = false;
        i  *= -1;
    }

    BigInt ret = newPositiveBigInt(i);
    ret.sign = sign;

    return ret;    
}

BigInt newPositiveBigInt(size_t i)
{
    // get number of digits
    int copy = i;
    int noDigits = 0;
    while (copy > 0)
    {
        noDigits++;
        copy /= 10;
    }

    BigInt ret = allocateBigInt(noDigits);
    ret.noDigits = noDigits;

    for (size_t idx = 0; idx < noDigits; idx++, i /=10)
    {
        ret.digits[idx] = i % 10;
        int p = i%10;
    }

    return ret;
}

char* BigIntPtrToString(BigInt* i)
{
    if (!i->noDigits)
    {
        return "0";
    }

    size_t noChars = i->noDigits;
    if (!i->sign)
    {
        noChars++;
    }
    // + 1 == '\0'
    char* ret = malloc((noChars + 1) * sizeof(char));

    if (!ret)
    {
        return NULL;
    }

    size_t strIdx = 0;
    if (!i->sign)
    {
        ret[strIdx++] = '-';
    }

    for (size_t digitIdx = i->noDigits; digitIdx != 0; digitIdx--, strIdx++)
    {
        ret[strIdx] = '0' + i->digits[digitIdx - 1];
    }

    ret[noChars] = '\0';

    return ret;   
    
}


char* BigIntToString(BigInt i)
{
    return BigIntPtrToString(&i);
}

char compareBigInt(BigInt i1, BigInt i2)
{
    if (i1.sign && !i2.sign) // i1 >= 0, i2 < 0
    {
        return 1;
    }
    else if (!i1.sign && i2.sign) // i1 < 0, i2 >= 0
    {
        return -1;
    }
    else if (!i1.sign && !i2.sign) // i1 < 0, i2 < 0
    {
        // both negative, compare the positive, return opposite
        i1.sign = true;
        i2.sign = true;
        char comparison = compareBigInt(i1, i2);
        return -comparison;
    }
    
    // both positive
    if (i1.noDigits > i2.noDigits)
    {
        return 1;
    }
    else if (i1.noDigits < i2.noDigits)
    {
        return -1;
    }
    
    // same number of digits, compare individual digits
    // start from highest magnitude terms
    size_t idx = i1.noDigits;
    while (idx--)
    {
        if (i1.digits[idx] > i2.digits[idx])
        {
            return 1;
        }
        else if (i1.digits[idx] < i2.digits[idx])
        {
            return -1;
        }
        
        
    }

    // all digits are equal
    return 0;
}

BigInt addBigInt(BigInt i1, BigInt i2)
{
    if(i1.sign && !i2.sign) // i1 + (-i2) = i1 - i2
    {
        i2.sign = true;
        return subtractBigInt(i1, i2);
    }
    else if (!i1.sign && i2.sign) // (-i1) + i2 = i2 - i1
    {
        i1.sign = true;
        return subtractBigInt(i2, i1);
    }

    size_t noDigits = MAX(i1.noDigits, i2.noDigits) + 1;

    BigInt ret = allocateBigInt(noDigits);
    ret.noDigits = noDigits;

    bool carry = false;
    char res;
    for (size_t idx = 0; idx < ret.noDigits; idx++)
    {
        res = carry ? 1 : 0;
        if (idx < i1.noDigits)
        {
            res += i1.digits[idx];
        }
        if (idx < i2.noDigits)
        {
            res += i2.digits[idx];
        }
        
        if (res >= 10)
        {
            carry = true;
            res -=10;
        }
        else
        {
            carry = false;
        }
        
        ret.digits[idx] = res;
    }
    
    // remove leading zeros
    while (!ret.digits[ret.noDigits - 1])
    {
        ret.noDigits--;
    }

    if (!i1.sign && !i2.sign) // (-i1) + (-i2) = -(i1 + i2)
    {
        ret.sign = false;
    }

    return ret;   

}

BigInt subtractBigInt(BigInt i1, BigInt i2)
{
    char comparison = compareBigInt(i1, i2);
    if (!comparison)
    {
        // the numbers are the same
        return BIGINT_ZERO;
    }
    
    if (i1.sign && !i2.sign) // i1 - (-i2) = i1 + i2 
    {
        i2.sign = true;
        return addBigInt(i1, i2);
    }
    else if (!i1.sign && i2.sign)  // (-i1) - i2 = - (i1 + i2)
    {
        i2.sign = false;
        return addBigInt(i1, i2);
    }
    else if (!i1.sign && !i2.sign) // (-i1) - (-i2) = (-i1) + i2 = i2 - i1
    {
        i1.sign = true; // eq. true in video
        i2.sign = true;
        return subtractBigInt(i2, i1);
    }
    else // both positive, find max
    {
        if (comparison < 0) // i2  > i1; i1 - i2 = -(i2 - i1)
        {
            BigInt res = subtractBigInt(i2, i1);
            res.sign = !res.sign;
            return res;
        }
    }

    // know both are positive and i1 is larger than i2
    size_t noDigits = i1.noDigits;
    BigInt ret = allocateBigInt(noDigits);
    ret.noDigits = noDigits;

    bool carry = false;
    
    for (size_t idx = 0; idx < ret.noDigits; idx++) // this works only if i1 > i2
    {
        char res = carry ? -1 : 0; // char res = ... in video
        if (idx < i1.noDigits)
        {
            res += i1.digits[idx];
        }
        if (idx < i2.noDigits)
        {
            res -= i2.digits[idx];
        }
        if (res < 0)
        {
            carry = true;
            res += 10;
        }
        else
        {
            carry = false;
        }
        
        ret.digits[idx] = res;
    }
    
    // remove leading zeros
    while (!ret.digits[ret.noDigits - 1])
    {
        ret.noDigits--;
    }

    return ret;
}