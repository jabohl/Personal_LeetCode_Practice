"""
LeetCode Problem: Vowels Game In String

Problem:
Alice and Bob play a game. Alice starts first. The game is played on a string of lowercase letters.
On each turn, a player removes a prefix (including an empty prefix) from the string such that 
the number of vowels in the remaining string is even. A player who cannot make a valid move loses.

Alice wants to know if she can win the game.

Example:
Input: s = "euuuu"
Output: false
Explanation: Alice cannot win no matter what prefix she removes.

Time Complexity: O(n^2) - worst case, we iterate through the string multiple times
Space Complexity: O(n) - for string slicing
"""

class Solution:
    """Solution for the Vowels Game In String problem."""
    
    def doesAliceWin(self, s: str) -> bool:
        """
        Determines if Alice can win the vowels game.
        
        Args:
            s (str): Input string of lowercase letters
            
        Returns:
            bool: True if Alice wins, False if Bob wins
        """
        
        def count_vowels(text: str) -> int:
            """
            Count the number of vowels in a string.
            
            Args:
                text (str): Input string to count vowels in
                
            Returns:
                int: Number of vowels found
            """
            vowels = set('aeiou')
            return sum(1 for char in text if char in vowels)
        
        # If total vowels is odd, Alice can remove an empty prefix
        # and Bob will face an even number of vowels (losing position)
        if count_vowels(s) % 2 != 0:
            return True
        
        # If there are no vowels, Alice cannot make a valid move
        if count_vowels(s) == 0:
            return False
        
        # Simulate the game: Alice tries all possible moves
        current_string = s
        while len(current_string) > 0:
            # Try removing prefixes from longest to shortest
            for prefix_end_index in range(len(current_string) - 1, -1, -1):
                remaining_after_prefix = current_string[prefix_end_index:]
                vowel_count_after_move = count_vowels(remaining_after_prefix)
                
                # If remaining vowels is odd, Bob faces losing position
                if vowel_count_after_move % 2 != 0:
                    if not current_string:
                        return False
                    current_string = remaining_after_prefix
                
                # If no vowels remain, Alice wins (valid move by Alice)
                elif vowel_count_after_move == 0:
                    if not current_string:
                        return True
                    current_string = current_string[1:]
                
                # If remaining vowels is even, continue game
                elif vowel_count_after_move % 2 == 0:
                    if not current_string:
                        return True
                    current_string = remaining_after_prefix
        
        return False


# Test cases
if __name__ == "__main__":
    solution = Solution()
    
    # Test 1: Odd number of vowels
    test1 = "euuuu"
    result1 = solution.doesAliceWin(test1)
    print(f"Test 1 - Input: '{test1}' | Output: {result1}")  # Expected: False
    
    # Test 2: String with no vowels
    test2 = "bcdf"
    result2 = solution.doesAliceWin(test2)
    print(f"Test 2 - Input: '{test2}' | Output: {result2}")  # Expected: False
    
    # Test 3: Even vowels
    test3 = "aeu"
    result3 = solution.doesAliceWin(test3)
    print(f"Test 3 - Input: '{test3}' | Output: {result3}")  # Expected: False
