#include "stdio.h"

int main()
{
    int a;

    // a = 0;
    
    // for (int i = 0; i < 4; ++i)
    // {
    //     a |= (1 << i);
    // }
    

    a = ((1 << 1) | (1 << 2));

    printf("a = %i\n", a);

    return 0;
}