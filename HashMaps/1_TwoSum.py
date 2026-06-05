"""
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
"""

class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        # Dictionary to store value -> index mapping
        num_map = {}
        
        for i, num in enumerate(nums):
            complement = target - num
            
            # Check if complement exists in map
            if complement in num_map:
                return [num_map[complement], i]
            
            # Store current number and its index
            num_map[num] = i
        
        return []  # No solution found


# Test cases
if __name__ == "__main__":
    sol = Solution()
    
    # Test 1
    nums1 = [2, 7, 11, 15]
    target1 = 9
    result1 = sol.twoSum(nums1, target1)
    print(f"Test 1: {result1}")  # Expected output: [0, 1]
    
    # Test 2
    nums2 = [3, 2, 4]
    target2 = 6
    result2 = sol.twoSum(nums2, target2)
    print(f"Test 2: {result2}")  # Expected output: [1, 2]
    
    # Test 3
    nums3 = [3, 3]
    target3 = 6
    result3 = sol.twoSum(nums3, target3)
    print(f"Test 3: {result3}")  # Expected output: [0, 1]
