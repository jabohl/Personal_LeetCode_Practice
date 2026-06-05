"""
LeetCode Problem: Reverse Integer

Problem Description:
Given a signed 32-bit integer x, return x with its digits reversed.
If reversing x causes the value to go outside the signed 32-bit integer range [-2^31, 2^31 - 1],
then return 0.

Example 1:
Input: x = 123
Output: 321

Example 2:
Input: x = -123
Output: -321

Example 3:
Input: x = 120
Output: 21

Constraints:
-2^31 <= x <= 2^31 - 1

Time Complexity: O(log x) - where x is the number of digits
Space Complexity: O(log x) - to store the digits list
"""


class Solution:
    """Solution class for the Reverse Integer problem."""
    
    def reverse(self, number: int) -> int:
        """
        Reverse the digits of a signed 32-bit integer.
        Returns 0 if the result overflows the signed 32-bit integer range.
        
        Args:
            number: The integer to reverse
            
        Returns:
            The reversed integer, or 0 if overflow occurs
        """
        # Track if the original number was negative
        is_negative = False
        if number < 0:
            is_negative = True
            number = abs(number)
        
        # Extract all digits from the number
        digits = []
        while number > 0:
            digit = number % 10
            digits.append(digit)
            number //= 10
        
        # Reconstruct the reversed number from the digits list
        reversed_number = 0
        power_of_ten = len(digits) - 1
        
        for digit in digits:
            reversed_number += digit * (10 ** power_of_ten)
            power_of_ten -= 1
        
        # Apply the original sign
        if is_negative:
            reversed_number *= -1
        
        # Define 32-bit signed integer bounds
        INT_MAX = (2 ** 31) - 1
        INT_MIN = -(2 ** 31)
        
        # Check for overflow and return 0 if out of range
        if reversed_number > INT_MAX or reversed_number < INT_MIN:
            return 0
        
        return reversed_number
