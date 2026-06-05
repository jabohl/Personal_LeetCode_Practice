class Solution:
    """
    Finds all elements that appear more than n/3 times in the array.
    
    Time Complexity: O(n)
    Space Complexity: O(n) for the dictionary
    """
    
    def majorityElement(self, nums: List[int]) -> List[int]:
        """
        Finds all numbers that appear more than len(nums)/3 times.
        
        Args:
            nums: List of integers
        
        Returns:
            List of integers that appear more than n/3 times
        """
        # Dictionary to store frequency of each element
        elementFrequencyMap = {}
        
        # Initialize the dictionary with all unique elements
        for element in nums:
            elementFrequencyMap[element] = 0
        
        # Count the frequency of each element
        for elementIndex in range(len(nums)):
            elementFrequencyMap[nums[elementIndex]] += 1
        
        # List to store elements that appear more than n/3 times
        majorityElements = []
        
        # Check which elements appear more than n/3 times
        for uniqueElement in elementFrequencyMap:
            if elementFrequencyMap[uniqueElement] > len(nums) / 3:
                majorityElements.append(uniqueElement)
        
        return majorityElements
