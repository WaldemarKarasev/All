#include <stdio.h>
#include <stdlib.h>

#include "cmathematics.h"
#include "vec.h"
#include "matrix.h"
#include "BigInt.h"

int main()
{
    printf("Hello World!\n");
    
    BigInt b1 = newBigInt(-15932);
    BigInt b2 = newBigInt(16932);
    
    printf("%s\n", BigIntToString(subtractBigInt(b1, b2)));


    return 0;
}

