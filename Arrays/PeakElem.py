class Solution:
    """
    Finds a peak element in the array.
    A peak element is an element that is strictly greater than its neighbors.
    
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    
    def findPeakElement(self, nums: List[int]) -> int:
        """
        Finds and returns the index of a peak element.
        Edge elements can be peaks (e.g., nums[0] > nums[1] makes nums[0] a peak).
        
        Args:
            nums: List of integers
        
        Returns:
            Index of a peak element
        """
        # Handle edge case: array with single element
        if len(nums) == 1:
            return 0
        
        # Handle edge case: array with two elements
        if len(nums) == 2:
            if nums[0] > nums[1]:
                return 0
            else:
                return 1
        
        # Check if the first element is a peak (greater than its right neighbor)
        if nums[0] > nums[1]:
            return 0
        
        # Check all interior elements
        for currentIndex in range(1, len(nums) - 1):
            # A peak must be greater than both left and right neighbors
            if nums[currentIndex] > nums[currentIndex - 1] and nums[currentIndex] > nums[currentIndex + 1]:
                return currentIndex
        
        # Check if the last element is a peak (greater than its left neighbor)
        if nums[len(nums) - 1] > nums[len(nums) - 2]:
            return len(nums) - 1
