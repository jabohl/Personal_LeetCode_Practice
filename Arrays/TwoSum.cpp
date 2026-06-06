#include <vector>


class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::vector<int> resultIndices;


        for (int firstIndex = 0; firstIndex < nums.size() - 1; firstIndex++) {
            for (int secondIndex = firstIndex + 1; secondIndex < nums.size(); secondIndex++) {
                if (nums[firstIndex] + nums[secondIndex] == target) {
                    resultIndices.push_back(firstIndex);
                    resultIndices.push_back(secondIndex);


                    return resultIndices;
                }
            }
        }


        return resultIndices;
    }
};
