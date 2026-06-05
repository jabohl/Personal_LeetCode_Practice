/**
 * LeetCode Problem: Reverse Integer (LeetCode 7)
 *
 * Problem Description:
 * Given a signed 32-bit integer x, return x with its digits reversed.
 * If reversing x causes the value to go outside the signed 32-bit integer
 * range [-2^31, 2^31 - 1], then return 0.
 *
 * Example 1:
 * Input: x = 123
 * Output: 321
 *
 * Example 2:
 * Input: x = -123
 * Output: -321
 *
 * Example 3:
 * Input: x = 120
 * Output: 21
 *
 * Constraints:
 * -2^31 <= x <= 2^31 - 1
 *
 * Time Complexity: O(log x) - where x is the number of digits
 * Space Complexity: O(log x) - to store digit count
 */

#include <stdio.h>
#include <math.h>
#include <limits.h>

/**
 * Reverse the digits of a signed 32-bit integer.
 * Returns 0 if the result overflows the signed 32-bit integer range.
 *
 * Args:
 *     number: The integer to reverse
 *
 * Returns:
 *     The reversed integer, or 0 if overflow occurs
 */
int reverse(int number) {
    int isNegative = 0;
    
    // Handle negative numbers
    if (number < 0) {
        isNegative = 1;
        number = -number;
    }

    // Calculate the number of digits
    int digitCount = 0;
    int tempNumber = number;

    while (tempNumber > 0) {
        digitCount += 1;
        tempNumber -= (tempNumber % 10);
        tempNumber /= 10;
    }

    // Reconstruct the reversed number
    int reversedNumber = 0;
    int currentDigitCount = digitCount;
    tempNumber = number;

    while (tempNumber > 0) {
        int currentDigit = tempNumber % 10;
        reversedNumber += currentDigit * (int)pow(10, currentDigitCount - 1);
        currentDigitCount -= 1;
        tempNumber /= 10;
    }

    // Apply the original sign
    if (isNegative) {
        reversedNumber = -reversedNumber;
    }

    // Check for overflow and return 0 if out of range
    if (reversedNumber > INT_MAX || reversedNumber < INT_MIN) {
        return 0;
    }

    return reversedNumber;
}
