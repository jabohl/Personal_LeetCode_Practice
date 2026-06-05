#include <vector>
#include <unordered_map>

/**
 * Finds all elements that appear more than n/3 times in the array.
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(n) for the hash map
 */
class Solution {
public:
    std::vector<int> majorityElement(std::vector<int>& nums) {
        // Hash map to store frequency of each element
        std::unordered_map<int, int> elementFrequencyMap;
        
        // Count the frequency of each element
        for (int num : nums) {
            elementFrequencyMap[num]++;
        }
        
        // Vector to store elements that appear more than n/3 times
        std::vector<int> majorityElements;
        
        // Check which elements appear more than n/3 times
        for (auto& pair : elementFrequencyMap) {
            if (pair.second > nums.size() / 3) {
                majorityElements.push_back(pair.first);
            }
        }
        
        return majorityElements;
    }
};
