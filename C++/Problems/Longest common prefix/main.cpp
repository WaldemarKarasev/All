#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::string longestCommonPrefix(std::vector<std::string>& strs)
{
    std::string prefix = "0";
    
    //std::sort(strs.begin(), strs.end());
    
    
    std::string minWord = strs[0];
    for (int i = 0; i < strs.size(); i++)
    {
        int tmp = strs[i].size();
        if (tmp <= minWord.size())
        {
            minWord = strs[i];
        }    

    }
    
   for (int i = 0; i < minWord.length(); ++i)
   {
        char ch = strs[0].at(i);
        for (int j = 1; j < strs.size(); ++j)
        {

            if (i == strs[j].length() || strs[j].at(i) != ch)
            {
                return strs[0].substr(0, i);
            }
                        
        }
        
   }
   
   return minWord;
   
    
}

int main()
{
    std::vector<std::string> strs = {"flowers", "flow", "flight"};

    std::cout << longestCommonPrefix(strs) << std::endl;

    return 0;
}