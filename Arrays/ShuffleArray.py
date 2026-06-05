import random

class Solution:
    """
    Provides shuffle and reset functionality for an array.
    Allows shuffling the array and resetting it to the original order.
    
    Time Complexity: O(n) for shuffle, O(n) for reset
    Space Complexity: O(n) to store the original array
    """
    
    def __init__(self, nums: List[int]):
        """
        Initializes the shuffler with the original array.
        
        Args:
            nums: The original array to shuffle
        """
        # Store a copy of the original array for reset functionality
        self.originalArray = []
        # Working copy that will be shuffled
        self.currentArray = []
        
        # Copy all elements from nums to both storage arrays
        for element in nums:
            self.currentArray.append(element)
            self.originalArray.append(element)
    
    def reset(self) -> List[int]:
        """
        Resets the array to its original order.
        
        Returns:
            The original unshuffled array
        """
        # Restore the current array to the original state
        self.currentArray = self.originalArray[:]
        
        return self.currentArray
    
    def shuffle(self) -> List[int]:
        """
        Returns a randomly shuffled version of the array.
        
        Returns:
            A shuffled copy of the array
        """
        # Create a copy of the current array to shuffle
        shuffledArray = []
        
        for element in self.currentArray:
            shuffledArray.append(element)
        
        # Shuffle the copy using Fisher-Yates algorithm (via random.shuffle)
        random.shuffle(shuffledArray)
        
        return shuffledArray
