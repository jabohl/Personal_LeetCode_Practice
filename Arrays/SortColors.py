class Solution:
    """
    Sorts an array containing only 0s, 1s, and 2s in-place.
    Uses a three-pointer approach to separate the colors.
    
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    
    def sortColors(self, nums: List[int]) -> None:
        """
        Sorts the array in-place by partitioning:
        - 0s to the left
        - 1s in the middle
        - 2s to the right
        
        Args:
            nums: List of integers containing only 0, 1, and 2
        
        Returns:
            None (modifies nums in-place)
        """
        
        # Handle edge cases
        if len(nums) < 2:
            return
        
        # Pointer for current element being examined
        currentIndex = 0
        # Pointer for position where 0s should be placed
        zeroPointer = 0
        # Pointer for position where 2s should be placed
        twoPointer = len(nums) - 1
        
        # Continue until currentIndex reaches the twoPointer
        while currentIndex <= twoPointer:
            if nums[currentIndex] == 0:
                # Swap current element with element at zeroPointer
                temp = nums[zeroPointer]
                nums[zeroPointer] = nums[currentIndex]
                nums[currentIndex] = temp
                
                currentIndex += 1
                zeroPointer += 1
            
            elif nums[currentIndex] == 1:
                # 1 is already in correct partition, just move forward
                currentIndex += 1
            
            else:  # nums[currentIndex] == 2
                # Swap current element with element at twoPointer
                temp = nums[twoPointer]
                nums[twoPointer] = nums[currentIndex]
                nums[currentIndex] = temp
                
                # Don't increment currentIndex yet, we need to check the swapped element
                twoPointer -= 1
