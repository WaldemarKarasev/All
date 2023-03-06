#include <iostream>
#include <string>
#include <stack>


bool Solution(std::string s)
{
    std::stack<char> stack;

    for (char  ch : s)
    {
        if (ch == '(')
        {
            stack.push(')');
            continue;
        }
        else if (ch == '[')
        {
            stack.push(']');
            continue;
        }
        else if (ch == '{')
        {
            stack.push('}');
            continue;
        }
        else if (stack.empty())
        {
            return false;
        }

        if (stack.top() == ch)
        {
            stack.pop();
            continue;
        }
        else
            return false;
                            
    }

    return stack.empty();
    
}

int main()
{
    std::string s = "[]{}()";
    std::string s1 = "{]()][)";
    std::string s2 = "({[]})";
    

    
    std::cout << Solution(s) << std::endl;
    std::cout << Solution(s1) << std::endl;
    std::cout << Solution(s2) << std::endl;

    

    return 0;
}