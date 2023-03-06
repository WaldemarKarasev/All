#include <iostream>


bool isEven1(int num) {return !(1 & num);}

bool isEven2(int num) {return !(num % 2);}


int main()
{
//     int i = 8;
//     int y = 9;
    
//     std::cout << isEven1(i) << std::endl;
//     std::cout << isEven2(i) << std::endl;

    for (int i = 0; i < 10000; ++i)
    {
        std::cout << isEven2(i) << std::endl;
    }
    
         
}