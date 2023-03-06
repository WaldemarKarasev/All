#include <iostream>

bool isPalindrome(int x)
{
    int sum = 0;
    int temp = x;

    while (x > 0)
    {
        int val = x % 10;
        
        sum = (sum * 10) + val;

        x /= 10;
    }
    
    if (temp == sum)
    {
        return true;
    }
    
    return false;
 
}

int Palindrome(int x)
{
    int sum = 0;

    while (x > 0)
    {
        int temp = x % 10;
        
        sum = (sum * 10) + temp;

        x /= 10;
    }
    
    return sum;
 
}


int main()
{
    int x = 1234;
    int y = 121;

    std::cout << isPalindrome(x) << std::endl;
    std::cout << isPalindrome(y) << std::endl;

    return 0;
}