#include <vector>

/**
 * Finds two numbers in the array that add up to the target value.
 * Uses brute force approach checking all pairs.
 * 
 * Time Complexity: O(n^2) - nested loops through entire array
 * Space Complexity: O(1) - only using constant extra space
 * 
 * @param nums Vector of integers to search
 * @param target The target sum
 * @return Vector of two indices whose values sum to target
 */
class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::vector<int> resultIndices;
        
        // Outer loop: iterate through each element
        for (int firstIndex = 0; firstIndex < nums.size() - 1; firstIndex++) {
            // Inner loop: check all elements after firstIndex
            for (int secondIndex = firstIndex + 1; secondIndex < nums.size(); secondIndex++) {
                // Check if the sum of two elements equals the target
                if (nums[firstIndex] + nums[secondIndex] == target) {
                    // Store the indices in the result vector
                    resultIndices.push_back(firstIndex);
                    resultIndices.push_back(secondIndex);
                    return resultIndices;
                }
            }
        }
        
        // Return empty vector if no pair is found
        return resultIndices;
    }
};
