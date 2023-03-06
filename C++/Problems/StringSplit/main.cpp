#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>

int main()
{
    std::string s = "102.43 1984.1 214";

    std::stringstream ss(s);
    std::istream_iterator<std::string> begin(ss);
    std::istream_iterator<std::string> end;
    std::vector<std::string> tokens(begin, end);
 
    for (auto s: tokens) {
        std::cout << s << std::endl;
    }
    
    std::cout << "\n\n";
    std::vector<float> numbers;
//    numbers.reserve(10);
    for (auto it : tokens)
    {
        numbers.push_back(std::stof(it));
    }

    for (auto it : numbers)
    {
        std::cout << it*100 << '\n';
    }
    
    

    return 0;
    
    
}