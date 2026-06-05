class SmallestInfiniteSet:
    """
    Manages an infinite set of positive integers starting from 1.
    Supports removing the smallest element and adding numbers back.
    
    Time Complexity: 
        - popSmallest: O(n) due to list slicing
        - addBack: O(n) for insertion in sorted order
    Space Complexity: O(n) for storing removed numbers
    """
    
    def __init__(self):
        """
        Initializes the set with numbers 1 through 1000.
        """
        # Store numbers in the infinite set
        # Represents all positive integers (practical limit: 1000)
        self.infiniteSet = []
        
        # Initialize with numbers 1 through 1000
        for number in range(1, 1001):
            self.infiniteSet.append(number)
    
    def popSmallest(self) -> int:
        """
        Removes and returns the smallest number from the set.
        
        Returns:
            The smallest integer in the set
        """
        # Get the smallest element (at index 0)
        smallestElement = self.infiniteSet[0]
        
        # Remove it from the set (slice off the first element)
        self.infiniteSet = self.infiniteSet[1:]
        
        # Return the smallest element
        return smallestElement
    
    def addBack(self, num: int) -> None:
        """
        Adds a number back to the set if it's not already present.
        Maintains the set in sorted order.
        
        Args:
            num: The number to add back to the set
        """
        # Position where num should be inserted
        insertionIndex = 0
        
        # Check if the number is already in the set
        isNumberNotInSet = num not in self.infiniteSet
        
        # Only add if the number is not already in the set
        if isNumberNotInSet:
            # Find the correct position to maintain sorted order
            for currentIndex in range(len(self.infiniteSet)):
                # Find the first element greater than num
                if self.infiniteSet[currentIndex] > num:
                    insertionIndex = currentIndex
                    break
            
            # Insert num at the correct position
            self.infiniteSet.insert(insertionIndex, num)
