#include <iostream>
#include <vector>

std::vector<int> TwoSum(std::vector<int>& nums, int target)
{
    std::vector<int> result;
    int check = 0;

    for (int i = 0; i < nums.size() - 1; ++i)
    {
        check = 0;
        check += nums[i];

        for (int j = i + 1; j < nums.size(); ++j)
        {
            check += nums[j];
            if (check == target)
            {
                result.assign({i, j});
                return result;
            }
            else
                check -= nums[j];
        }
        
    }

    result.assign({0});
    
    return result;
    
}

int main()
{
    std::vector<int> nums = {1, 2, 3, 4, 5, 6};
    int target = 3;

    std::vector<int> result = TwoSum(nums, target);

    for (int i = 0; i < result.size(); ++i)
    {
        std::cout << result[i] << ' ';
    }
    
    std::cout << '\n';

    return 0;
}
