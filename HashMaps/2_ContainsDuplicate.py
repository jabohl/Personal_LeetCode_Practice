"""
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
"""

class Solution:
    def containsDuplicate(self, nums: list[int]) -> bool:
        # Use a set to track seen numbers
        seen = set()
        
        for num in nums:
            # If number already in set, it's a duplicate
            if num in seen:
                return True
            
            # Add number to set
            seen.add(num)
        
        return False  # No duplicates found


# Test cases
if __name__ == "__main__":
    sol = Solution()
    
    # Test 1 - Contains duplicate
    nums1 = [1, 2, 3, 1]
    result1 = sol.containsDuplicate(nums1)
    print(f"Test 1: {result1}")  # Expected output: True
    
    # Test 2 - All distinct
    nums2 = [1, 2, 3, 4]
    result2 = sol.containsDuplicate(nums2)
    print(f"Test 2: {result2}")  # Expected output: False
    
    # Test 3 - Large duplicate values
    nums3 = [99, 99]
    result3 = sol.containsDuplicate(nums3)
    print(f"Test 3: {result3}")  # Expected output: True
    
    # Test 4 - Single element
    nums4 = [1]
    result4 = sol.containsDuplicate(nums4)
    print(f"Test 4: {result4}")  # Expected output: False
