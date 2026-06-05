#include <vector>
#include <algorithm>

/**
 * Sorts an array containing only 0s, 1s, and 2s in-place.
 * Uses a three-pointer approach to separate the colors.
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
class Solution {
public:
    void sortColors(std::vector<int>& nums) {
        // Handle edge cases
        if (nums.size() < 2) {
            return;
        }
        
        // Pointer for current element being examined
        int currentIndex = 0;
        // Pointer for position where 0s should be placed
        int zeroPointer = 0;
        // Pointer for position where 2s should be placed
        int twoPointer = nums.size() - 1;
        
        // Continue until currentIndex reaches the twoPointer
        while (currentIndex <= twoPointer) {
            if (nums[currentIndex] == 0) {
                // Swap current element with element at zeroPointer
                std::swap(nums[zeroPointer], nums[currentIndex]);
                currentIndex++;
                zeroPointer++;
            } else if (nums[currentIndex] == 1) {
                // 1 is already in correct partition, just move forward
                currentIndex++;
            } else {  // nums[currentIndex] == 2
                // Swap current element with element at twoPointer
                std::swap(nums[twoPointer], nums[currentIndex]);
                // Don't increment currentIndex yet, we need to check the swapped element
                twoPointer--;
            }
        }
    }
};
