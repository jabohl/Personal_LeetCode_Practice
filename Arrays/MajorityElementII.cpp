#include <vector>
#include <unordered_map>


class Solution {
public:
    std::vector<int> majorityElement(std::vector<int>& nums) {
        std::unordered_map<int, int> elementFrequencyMap;


        for (int num : nums) {
            elementFrequencyMap[num]++;
        }


        std::vector<int> majorityElements;


        for (auto& pair : elementFrequencyMap) {
            if (pair.second > nums.size() / 3) {
                majorityElements.push_back(pair.first);
            }
        }


        return majorityElements;
    }
};
