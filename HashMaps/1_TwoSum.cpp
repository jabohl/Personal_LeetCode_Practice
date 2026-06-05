/*
LeetCode Problem 1: Two Sum

Problem:
Given an array of integers nums and an integer target, return the indices of the two numbers 
that add up to target. You may assume each input has exactly one solution, and you cannot 
use the same element twice.

Example:
Input: nums = [2, 7, 11, 15], target = 9
Output: [0, 1]
Explanation: nums[0] + nums[1] == 9, so we return [0, 1]

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map; // value -> index
        
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            
            // Check if complement exists in map
            if (map.find(complement) != map.end()) {
                return {map[complement], i};
            }
            
            // Store current number and its index
            map[nums[i]] = i;
        }
        
        return {}; // No solution found
    }
};

// Test cases
int main() {
    Solution sol;
    
    // Test 1
    vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    vector<int> result1 = sol.twoSum(nums1, target1);
    // Expected output: [0, 1]
    
    // Test 2
    vector<int> nums2 = {3, 2, 4};
    int target2 = 6;
    vector<int> result2 = sol.twoSum(nums2, target2);
    // Expected output: [1, 2]
    
    // Test 3
    vector<int> nums3 = {3, 3};
    int target3 = 6;
    vector<int> result3 = sol.twoSum(nums3, target3);
    // Expected output: [0, 1]
    
    return 0;
}
