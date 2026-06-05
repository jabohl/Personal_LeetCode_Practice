/*
LeetCode Problem 217: Contains Duplicate

Problem:
Given an integer array nums, return true if any value appears at least twice in the array, 
and return false if every element is distinct.

Example:
Input: nums = [1, 2, 3, 1]
Output: true

Input: nums = [1, 2, 3, 4]
Output: false

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        
        for (int num : nums) {
            // If number already in set, it's a duplicate
            if (seen.find(num) != seen.end()) {
                return true;
            }
            
            // Add number to set
            seen.insert(num);
        }
        
        return false; // No duplicates found
    }
};

// Test cases
int main() {
    Solution sol;
    
    // Test 1 - Contains duplicate
    vector<int> nums1 = {1, 2, 3, 1};
    bool result1 = sol.containsDuplicate(nums1);
    // Expected output: true
    
    // Test 2 - All distinct
    vector<int> nums2 = {1, 2, 3, 4};
    bool result2 = sol.containsDuplicate(nums2);
    // Expected output: false
    
    // Test 3 - Large duplicate values
    vector<int> nums3 = {99, 99};
    bool result3 = sol.containsDuplicate(nums3);
    // Expected output: true
    
    // Test 4 - Single element
    vector<int> nums4 = {1};
    bool result4 = sol.containsDuplicate(nums4);
    // Expected output: false
    
    return 0;
}
